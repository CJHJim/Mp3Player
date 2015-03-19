
// mp3Dlg.h : 头文件
//

#pragma once
#include "Mmsystem.h"
#include "Digitalv.h" 
#include "CJHPLAYER.h"               
#include "afxwin.h"
#include "afxcmn.h"
#include <map>
#include "afxbutton.h"
#include"mySliderCtrl.h"
using namespace std;
#pragma comment(lib,"Winmm.lib")


// Cmp3Dlg 对话框
class CplayerDlg : public CDialogEx
{
// 构造
public:
	CplayerDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MP3_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP();
	afx_msg void getmusic(CString strfilepath);
	afx_msg void PlayMusic(bool isclick);
	afx_msg void SetVolumn(DWORD vol);
	afx_msg void PlayTo(DWORD pos);
	afx_msg void openList();
	afx_msg void savelist();
	afx_msg string CstringToString(CString cstr);
	afx_msg void Remove(int pos);
	map<int,CString> List;
public:

	afx_msg void OnBnClickedPre();
	afx_msg void OnBnClickedPlay();
	afx_msg void OnBnClickedNext();
	afx_msg void OnBnClickedImport();
	CListBox m_List;
	CStatic m_name;
	int pos;
	int length;
	int play_model;
	afx_msg void OnBnClickedStop();
	afx_msg void OnLbnDblclkList();
	mySliderCtrl progress;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	mySliderCtrl m_vol;
	afx_msg void OnTRBNThumbPosChangingProgress(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMReleasedcaptureProgress(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedAbout();
	afx_msg void OnBnClickedAddfile();
	afx_msg void OnBnClickedClear();
	CButton m_playbtn;
	CComboBox m_playmodel;
	afx_msg void OnCbnSelchangePlayModel();
	afx_msg void OnBnClickedHelpbtn();
	afx_msg void OnBnClickedRemove();
	afx_msg void OnClose();
	afx_msg void OnBnClickedExit();
	afx_msg void OnBnClickedAdvance();
	afx_msg void OnBnClickedBack();
	afx_msg void OnNMReleasedcaptureSlider2(NMHDR *pNMHDR, LRESULT *pResult);
};
