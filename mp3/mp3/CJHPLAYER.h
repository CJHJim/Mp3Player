
// mp3.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif
#include "Mmsystem.h"
#include "Digitalv.h" 
#include "resource.h"		// ������
#pragma comment(lib,"Winmm.lib")

// Cmp3App: 
// �йش����ʵ�֣������ mp3.cpp
//

class CplayerApp : public CWinApp
{
public:
	CplayerApp();
	MCI_OPEN_PARMS mciopenparms;
	HWND m_hWnd; 
	DWORD DeviceID;

	bool Load(HWND hwnd, CString Strfilepath);
	DWORD getinformation(DWORD item);
	void Play();
	void Pause();
	void resum();
	void Stop();
// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	DECLARE_MESSAGE_MAP()
};

extern CplayerApp theApp;