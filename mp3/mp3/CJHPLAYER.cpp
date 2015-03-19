
// mp3.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "CJHPLAYER.h"
#include "cjhplayerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cmp3App

BEGIN_MESSAGE_MAP(CplayerApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// Cmp3App ����

CplayerApp::CplayerApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO:  �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� Cmp3App ����

CplayerApp theApp;


// Cmp3App ��ʼ��


BOOL CplayerApp::InitInstance()
{

	
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()��  ���򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	// ���� shell ���������Է��Ի������
	// �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
	CShellManager *pShellManager = new CShellManager;

	// ���Windows Native���Ӿ����������Ա��� MFC �ؼ�����������
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO:  Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("CJHPLAYER"));

	CplayerDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO:  �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO:  �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "����: �Ի��򴴽�ʧ�ܣ�Ӧ�ó���������ֹ��\n");
		TRACE(traceAppMsg, 0, "����: ������ڶԻ�����ʹ�� MFC �ؼ������޷� #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS��\n");
	}
	

	//��   
	
	// ɾ�����洴���� shell ��������
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}


	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}

bool CplayerApp::Load(HWND hwnd, CString Strfilepath)
{
	m_hWnd = hwnd;
	mciSendCommand(DeviceID, MCI_CLOSE, 0, 0); 
	mciopenparms.lpstrElementName = Strfilepath;
	DWORD dwReturn;
	if (dwReturn = mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_WAIT, 
		(DWORD)(LPVOID)&mciopenparms))
	{
		//char buffer[256];
		//mciGetErrorString(dwReturn, (LPWSTR)buffer, 256);
		//MessageBox(hwnd, (LPWSTR)buffer, L"����", MB_ICONHAND | MB_ICONERROR | MB_ICONSTOP);
		return false;
	}
	DeviceID = mciopenparms.wDeviceID;
	return true;
}
DWORD CplayerApp::getinformation(DWORD item)
{
	
	MCI_STATUS_PARMS mcistatusparms;

	mcistatusparms.dwItem = item;
	mcistatusparms.dwReturn = 0;
	mciSendCommand(DeviceID, MCI_STATUS, MCI_STATUS_ITEM, (DWORD)&mcistatusparms);
	return mcistatusparms.dwReturn;
}
void CplayerApp::Play()
{
	MCI_PLAY_PARMS mciplayparms;
	mciplayparms.dwCallback = (DWORD)m_hWnd;
	mciplayparms.dwFrom = 0;
	mciSendCommand(DeviceID, MCI_PLAY, MCI_FROM | MCI_NOTIFY, (DWORD)(LPVOID)&mciplayparms);
}
void CplayerApp::Pause()
{
	mciSendCommand(DeviceID, MCI_PAUSE, 0, 0);
}
void CplayerApp::resum()
{
	mciSendCommand(DeviceID, MCI_RESUME, 0, 0);
}
void CplayerApp::Stop()
{
	mciSendCommand(DeviceID, MCI_STOP, 0, 0);
	mciSendCommand(DeviceID, MCI_CLOSE, 0, 0);
}
