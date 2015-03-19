
// mp3.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif
#include "Mmsystem.h"
#include "Digitalv.h" 
#include "resource.h"		// 主符号
#pragma comment(lib,"Winmm.lib")

// Cmp3App: 
// 有关此类的实现，请参阅 mp3.cpp
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
// 重写
public:
	virtual BOOL InitInstance();

// 实现
	DECLARE_MESSAGE_MAP()
};

extern CplayerApp theApp;