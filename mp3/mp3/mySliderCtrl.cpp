

#include "stdafx.h"
#include "mySliderCtrl.h"


#include <shlwapi.h>		
#pragma comment( lib, "shlwapi.lib" )

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

mySliderCtrl::mySliderCtrl()
{
	SetPrimaryColor( RGB(0, 255, 0) );	
}

mySliderCtrl::mySliderCtrl(COLORREF cr)
{
	SetPrimaryColor( cr );	
}

mySliderCtrl::~mySliderCtrl()
{
}


BEGIN_MESSAGE_MAP(mySliderCtrl, CSliderCtrl)
	//{{AFX_MSG_MAP(CCustomDrawSliderCtrl)
	ON_NOTIFY_REFLECT(NM_CUSTOMDRAW, OnReflectedCustomDraw)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


void mySliderCtrl::SetPrimaryColor(COLORREF cr)
{
	

	m_crPrimary = cr;

	

	m_crHilite		= ::ColorAdjustLuma( cr, 500, TRUE );	
	m_crMidShadow	= ::ColorAdjustLuma( cr, -210, TRUE );	
	m_crShadow		= ::ColorAdjustLuma( cr, -333, TRUE );	
	m_crDarkerShadow = ::ColorAdjustLuma( cr, -500, TRUE );	



	if ( m_normalBrush.m_hObject )
		m_normalBrush.DeleteObject();
	
	m_normalBrush.CreateSolidBrush( cr );


	
	
	WORD bitsBrush1[8] = { 0x0055,0x00aa,0x0055,0x00aa,0x0055,0x00aa,0x0055,0x00aa };
	
	CBitmap bm;
	bm.CreateBitmap( 8, 8, 1, 1, bitsBrush1);
	
	LOGBRUSH logBrush;
	logBrush.lbStyle = BS_PATTERN;
	logBrush.lbHatch = (int) bm.GetSafeHandle();
	logBrush.lbColor = 0;		
	if ( m_focusBrush.m_hObject )
		m_focusBrush.DeleteObject();

	m_focusBrush.CreateBrushIndirect(&logBrush);

}

void mySliderCtrl::OnReflectedCustomDraw(NMHDR* pNMHDR, LRESULT* pResult)
{

	
	NMCUSTOMDRAW nmcd = *(LPNMCUSTOMDRAW)pNMHDR;
	
	UINT drawStage = nmcd.dwDrawStage;
	UINT itemSpec = nmcd.dwItemSpec;
	
	switch ( drawStage )
	{
		

	case CDDS_PREPAINT:		
		
		*pResult = CDRF_NOTIFYITEMDRAW | CDRF_NOTIFYPOSTPAINT ;
		break;
		
	case CDDS_PREERASE:		
	case CDDS_POSTERASE:	
	case CDDS_ITEMPREERASE:	
	case CDDS_ITEMPOSTERASE:	
		
		
		
		*pResult = CDRF_DODEFAULT;
		break;
		
	case CDDS_ITEMPREPAINT:	
		
		switch ( itemSpec )
		{
		case TBCD_CHANNEL:	

			*pResult = CDRF_DODEFAULT| CDRF_NOTIFYPOSTPAINT;
			break;

		case TBCD_TICS:		
			*pResult = CDRF_DODEFAULT;
			break;
			
		case TBCD_THUMB:	
			
			{
				CDC* pDC = CDC::FromHandle( nmcd.hdc );
				int iSaveDC = pDC->SaveDC();
				
				CBrush* pB = &m_normalBrush;
				CPen pen( PS_SOLID, 1, m_crShadow );
				
				
				
				if ( nmcd.uItemState && CDIS_FOCUS )
				{
					pB = &m_focusBrush;
					
					pDC->SetBrushOrg( nmcd.rc.right%8, nmcd.rc.top%8 );
					pDC->SetBkColor( m_crPrimary );
					pDC->SetTextColor( m_crHilite );				
				}
				
				pDC->SelectObject( pB );
				pDC->SelectObject( &pen );

#if 1	

				pDC->Ellipse( &(nmcd.rc) );

#else	
				
				int xx, yy, dx, dy, cx, cy;
				xx = nmcd.rc.left;
				yy = nmcd.rc.top;
				dx = 2;
				dy = 2;
				cx = nmcd.rc.right - xx - 1;
				cy = nmcd.rc.bottom - yy - 1;
				POINT pts[8] = { {xx+dx, yy}, {xx, yy+dy}, {xx, yy+cy-dy}, {xx+dx, yy+cy},
						{xx+cx-dx, yy+cy}, {xx+cx, yy+cy-dy}, {xx+cx, yy+dy}, {xx+cx-dx, yy} };

				pDC->Polygon( pts, 8 );

#endif	

				pDC->RestoreDC( iSaveDC );
				pDC->Detach();
			}
			*pResult = CDRF_SKIPDEFAULT;	
			break;
			
		default:
			ASSERT( FALSE );	
		};
		
		break;

	case CDDS_ITEMPOSTPAINT:	

		switch ( itemSpec )
		{
		case TBCD_CHANNEL:
			{
				CDC* pDC = CDC::FromHandle( nmcd.hdc );

				RECT rrc = {nmcd.rc.left+1, nmcd.rc.top+1, nmcd.rc.right-1, nmcd.rc.bottom-1};
				pDC->Draw3dRect( &rrc, m_crMidShadow, m_crHilite );
				pDC->Detach();
			}
			*pResult = CDRF_SKIPDEFAULT;
			break;

		case TBCD_TICS:		
			*pResult = CDRF_DODEFAULT;
			break;
			
		case TBCD_THUMB:	
			
			*pResult = CDRF_DODEFAULT ;	
			
		default:
			ASSERT( FALSE );	
		};

		break;

	case CDDS_POSTPAINT:		
		{
			CDC* pDC = CDC::FromHandle( nmcd.hdc );

			CBrush bWhite( RGB(255, 255, 255) );	
			CBrush bDark( m_crDarkerShadow );		
			CPen p(PS_SOLID, 1, m_crPrimary);

			CRect rClient;
			GetClientRect( &rClient );
			DWORD dwStyle = GetStyle();


			int cx = 8;
			CRect rrcFirst;( 1, 1, cx, cx );
			CRect rrcLast;

		

			if ( dwStyle & TBS_VERT )
			{
				if ( dwStyle & TBS_LEFT )
				{
					rrcFirst = CRect( rClient.right-cx, 1, rClient.right-1, cx ); 
					rrcLast = CRect( rClient.right-cx, rClient.bottom-cx, rClient.right-1, rClient.bottom-1 );
				}
				else
				{
					rrcFirst = CRect( 1, 1, cx, cx ); 
					rrcLast = CRect( 1, rClient.bottom-cx, cx, rClient.bottom-1 );
				}
			}
			else
			{
				if ( dwStyle & TBS_TOP )
				{
					rrcFirst = CRect( 1, rClient.bottom-cx, cx, rClient.bottom-1 ); 
					rrcLast = CRect( rClient.right-cx, rClient.bottom-cx, rClient.right-1, rClient.bottom-1 );
				}
				else
				{
					rrcFirst = CRect( 1, 1, cx, cx ); 
					rrcLast = CRect( rClient.right-cx, 1, rClient.right-1, cx );
				}
			}
			
			int iSave = pDC->SaveDC();
			pDC->SelectObject( &bWhite );
			pDC->SelectObject( &p );
			pDC->Ellipse( &rrcFirst );
			pDC->SelectObject( &bDark );
			pDC->Ellipse( &rrcLast );
			pDC->RestoreDC( iSave );

			pDC->Detach();
		}

		*pResult = CDRF_SKIPDEFAULT;
		break;


	default:			
		ASSERT( FALSE );	
		
	};
	
}

COLORREF mySliderCtrl::GetPrimaryColor() const
{
	return m_crPrimary;
}

COLORREF mySliderCtrl::GetHiliteColor() const
{
	return m_crHilite;
}

COLORREF mySliderCtrl::GetShadowColor() const
{
	return m_crShadow;
}
