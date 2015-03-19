
// mp3Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CJHPLAYER.h"
#include "cjhplayerDlg.h"
#include "afxdialogex.h"
#include <string>
#include<cstring>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_WM_TIMER()
END_MESSAGE_MAP()
// CDialogHelp 对话框

class CDialogHelp : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogHelp)

public:
	CDialogHelp(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDialogHelp();

	virtual void OnFinalRelease();

	// 对话框数据
	enum { IDD = IDD_HELPDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

IMPLEMENT_DYNAMIC(CDialogHelp, CDialogEx)

CDialogHelp::CDialogHelp(CWnd* pParent /*=NULL*/)
: CDialogEx(CDialogHelp::IDD, pParent)
{

	EnableAutomation();

}

CDialogHelp::~CDialogHelp()
{
}

void CDialogHelp::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。  基类将自动
	// 删除该对象。  在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CDialogEx::OnFinalRelease();
}

void CDialogHelp::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogHelp, CDialogEx)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CDialogHelp, CDialogEx)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_IDialogHelp 支持
//  以支持来自 VBA 的类型安全绑定。  此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {41715B23-78F5-478D-8F46-FC2C43832B5F}
static const IID IID_IDialogHelp =
{ 0x41715B23, 0x78F5, 0x478D, { 0x8F, 0x46, 0xFC, 0x2C, 0x43, 0x83, 0x2B, 0x5F } };

BEGIN_INTERFACE_MAP(CDialogHelp, CDialogEx)
	INTERFACE_PART(CDialogHelp, IID_IDialogHelp, Dispatch)
END_INTERFACE_MAP()


// Cmp3Dlg 对话框



CplayerDlg::CplayerDlg(CWnd* pParent /*=NULL*/)
: CDialogEx(CplayerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	
}

void CplayerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, m_List);
	DDX_Control(pDX, IDC_NAME, m_name);
	DDX_Control(pDX, IDC_PROGRESS, progress);
	DDX_Control(pDX, IDC_SLIDER2, m_vol);
	DDX_Control(pDX, IDC_PLAY, m_playbtn);
	DDX_Control(pDX, IDC_PLAY_MODEL, m_playmodel);
}

BEGIN_MESSAGE_MAP(CplayerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_PRE, &CplayerDlg::OnBnClickedPre)
	ON_BN_CLICKED(IDC_PLAY, &CplayerDlg::OnBnClickedPlay)
	ON_BN_CLICKED(IDC_NEXT, &CplayerDlg::OnBnClickedNext)
	ON_BN_CLICKED(IDC_IMPORT, &CplayerDlg::OnBnClickedImport)
	ON_BN_CLICKED(IDC_STOP, &CplayerDlg::OnBnClickedStop)
	ON_LBN_DBLCLK(IDC_LIST, &CplayerDlg::OnLbnDblclkList)
	ON_WM_TIMER()
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_PROGRESS, &CplayerDlg::OnNMReleasedcaptureProgress)
	ON_BN_CLICKED(IDC_ABOUT, &CplayerDlg::OnBnClickedAbout)
	ON_BN_CLICKED(IDC_ADDFILE, &CplayerDlg::OnBnClickedAddfile)
	ON_BN_CLICKED(IDC_CLEAR, &CplayerDlg::OnBnClickedClear)
	ON_CBN_SELCHANGE(IDC_PLAY_MODEL, &CplayerDlg::OnCbnSelchangePlayModel)
	ON_BN_CLICKED(IDC_HELPBTN, &CplayerDlg::OnBnClickedHelpbtn)
	ON_BN_CLICKED(IDC_REMOVE, &CplayerDlg::OnBnClickedRemove)
	ON_WM_CLOSE()
	ON_BN_CLICKED(ID_EXIT, &CplayerDlg::OnBnClickedExit)
	ON_BN_CLICKED(IDC_ADVANCE, &CplayerDlg::OnBnClickedAdvance)
	ON_BN_CLICKED(IDC_BACK, &CplayerDlg::OnBnClickedBack)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER2, &CplayerDlg::OnNMReleasedcaptureSlider2)
END_MESSAGE_MAP()


// Cmp3Dlg 消息处理程序

BOOL CplayerDlg::OnInitDialog()
{

	CDialogEx::OnInitDialog();
	
	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	m_playbtn.SetBitmap(::LoadBitmap(AfxGetResourceHandle(), MAKEINTRESOURCE(IDB_BITMAP6)));
	ShowWindow(SW_NORMAL);
	
	// TODO:  在此添加额外的初始化代码
	progress.SetRange(0, 1000);//初始化进度条
	m_vol.SetRange(0, 100);//初始化音量条
	
	//初始化播放模式选项
	m_playmodel.InsertString(0,"列表循环");
	m_playmodel.InsertString(1,"单曲循环");
	m_playmodel.InsertString(2,"随机播放");
	m_playmodel.SetCurSel(0);
	play_model = 0;//播放模式选项默认为列表循环
	openList();
	m_vol.SetPos(50);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CplayerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CplayerDlg::OnPaint()
{
	
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{//载入背景
		CPaintDC   dc(this);
		CRect   rect;
		GetClientRect(&rect);
		CDC   dcMem;
		dcMem.CreateCompatibleDC(&dc);
		CBitmap   bmpBackground;
		bmpBackground.LoadBitmap(IDB_BITMAP2);
			BITMAP   bitmap;
		bmpBackground.GetBitmap(&bitmap);
		CBitmap   *pbmpOld = dcMem.SelectObject(&bmpBackground);
		dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);

	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CplayerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}






void CplayerDlg::OnBnClickedPlay()//播放音乐
{
	DWORD info = theApp.getinformation(MCI_STATUS_MODE);//获取状态
	if (info == MCI_MODE_PAUSE)//
	{
		
		m_playbtn.SetBitmap(::LoadBitmap(AfxGetResourceHandle(), MAKEINTRESOURCE(IDB_BITMAP5)));//改变播放按钮状态
		theApp.resum();
		return;
	}
	else
	if (info == MCI_MODE_PLAY)
	{
		m_playbtn.SetBitmap(::LoadBitmap(AfxGetResourceHandle(), MAKEINTRESOURCE(IDB_BITMAP6)));//同理
		theApp.Pause();
		return;
	}
	else
	{
		pos = m_List.GetCurSel();//得到播放的曲目位置
		PlayMusic(true);
	}
}

void CplayerDlg::OnBnClickedPre()//上一曲
{
	if (pos == -1)//如果没有音乐或者是没有选择音乐
	{
		if (m_List.GetCount() == 0)
		{
			MessageBox("请添加音乐");
			return;
		}
		MessageBox("请选择音乐");
		return;
	}
	if (pos <= 0)
	{
		pos = m_List.GetCount() - 1;
	}
	else
		pos--;
	PlayMusic(false);
}

void CplayerDlg::OnBnClickedNext()//下一曲
{
	if (pos == -1)//如果没有音乐或没有选择音乐
	{
		if (m_List.GetCount() == 0)
		{
			MessageBox("请添加音乐");
			return;
		}
		MessageBox("请选择音乐");
		return;
	}
	switch (play_model)
	{
	case 0:
	case 1:if (pos >= m_List.GetCount() - 1)
	       {
			   pos = 0;
	       }
		   else
			   pos++; break;
	case 2:srand((int)time(0));
		pos =rand() % m_List.GetCount();//随机播放，随机选择播放列表上的曲目进行播放
		break;
	}
	
	PlayMusic(false);
}


void CplayerDlg::OnBnClickedImport()//添加单首音乐
{
	
	CFileDialog open(true);
	open.m_ofn.lpstrTitle="打开音乐文件夹";//需加上L表示unicode
	open.m_ofn.lpstrFilter = "mp3 文件(*.mp3)\0*.mp3\0WAV文件(*.wav)\0*.wav\0WMA文件(*.wma)\0 * .wav\0APE文件(*.ape)\0*.ape\0\0";

	if (open.DoModal() == IDOK)
	{
		CString strfilepath = open.GetPathName();
		CString strfilename = open.GetFileName();
		m_List.InsertString(m_List.GetCount(), strfilename);
		List.insert(pair<int, CString>(m_List.GetCount() - 1, strfilepath));
	}
	if (pos == -1)//如果还没有选择音乐则pos自动定位到第一首音乐，以便于点击播放按键时可以立即播放
		pos = 0;
}


void CplayerDlg::OnBnClickedStop()//停止
{
	m_playbtn.SetBitmap(::LoadBitmap(AfxGetResourceHandle(), MAKEINTRESOURCE(IDB_BITMAP6)));//播放键复位
	SetDlgItemText(IDC_NAME, "当前无播放");
	SetDlgItemText(IDC_TIME, "00:00");
	SetDlgItemText(IDC_NOW, "00:00");
	progress.SetPos(0);//进度条复位
	theApp.Stop();//停止播放
	KillTimer(0);//结束计时
}



void CplayerDlg::OnLbnDblclkList()//双击播放列表的项，播放音乐
{
	pos = m_List.GetCurSel();
	PlayMusic(true);
	
}
void CplayerDlg::PlayMusic(bool isclick)//播放pos位置的音乐
{
	CString strfilename;//保存文件名的变量
	if (pos == -1)//如果没有选择音乐或者没有音乐可播放
	{
		if (m_List.GetCount() ==0)
		{
			MessageBox("请添加音乐");
			return;
		}
		MessageBox("请选择音乐");
	}
	else
	{
		m_List.GetText(pos, strfilename);//从播放列表框中获取歌曲名
		SetDlgItemText(IDC_NAME, strfilename);//显示到窗口
		theApp.Stop();//停止当前播放
		if (theApp.Load(this->m_hWnd, List.at(pos)))//如果载入歌曲成功
		{
			long l = theApp.getinformation(MCI_STATUS_LENGTH);//获取歌曲长度
			length = l / 1000;//转换为秒
			CString s;//用于显示时间
			CTime x(length);//初始化为时间
			s = x.Format("%M:%S");//格式化为分秒形式(被逼无奈才这么做的T_T，这编译器还不成熟)
			SetDlgItemText(IDC_TIME, s);//显示到窗口

			theApp.Play();//开始播放
			SetVolumn(m_vol.GetPos());//获取音量并设置
			m_playbtn.SetBitmap(::LoadBitmap(AfxGetResourceHandle(), MAKEINTRESOURCE(IDB_BITMAP5)));
			//改变播放按钮的状态
			SetTimer(0, 1000, NULL);//设置计时器
			OnTimer(0);//计时开始
		}
		else
		{
			if (isclick)
			{
				MessageBox( "初始化MCI时发生问题，无法播放该音乐", "错误", MB_ICONHAND | MB_ICONERROR | MB_ICONSTOP);
				
			}
			if (m_List.GetCount() <= 1)//避免只有一首歌曲时死循环
				return;

			Remove(pos);//否则MCI初始化失败自动播放下一曲
			
		}
	}
}

void CplayerDlg::OnTimer(UINT_PTR nIDEvent)//计时器
{
	DWORD info = theApp.getinformation(MCI_STATUS_MODE);//获取设备当前状态
	if (info == MCI_MODE_STOP)//如果当前歌曲播放结束
	{
		OnBnClickedNext();//播放下一曲
		return;
	}
	if (info == MCI_MODE_PLAY || info == MCI_MODE_PAUSE)//如果正在播放或已经暂停
	{
	DWORD p_pos = theApp.getinformation(MCI_STATUS_POSITION);//获取播放的位置
	double progress_pos = (p_pos/length) ;//转换为进度条的长度范围
	progress.SetPos(progress_pos);//设置进度条位置
	long now = p_pos / 1000;//获取当前播放时间进度
	CString s;//用于显示时间
	CTime x(now);//初始化为时间
	s = x.Format("%M:%S");//格式化为分秒形式
	SetDlgItemText(IDC_NOW, s);//显示到窗口
	if (progress_pos >= progress.GetRangeMax()-5)//如果播放结束
	{
		OnBnClickedNext();//播放下一曲
		return;
	}
	CDialogEx::OnTimer(nIDEvent);
	UpdateData(FALSE);
	}
	
}
void CplayerDlg::OnNMReleasedcaptureSlider2(NMHDR *pNMHDR, LRESULT *pResult)//用户改变播放音量
{
	SetVolumn(m_vol.GetPos());//获取拖动到的位置
	UpdateData(false);
	*pResult = 0;
}
void CplayerDlg::SetVolumn(DWORD vol)//设置音量
{
	MCI_DGV_SETAUDIO_PARMS mcisetvolumn;
	mcisetvolumn.dwItem = MCI_DGV_SETAUDIO_VOLUME;
	mcisetvolumn.dwValue = vol;//音量值
	mciSendCommand(theApp.DeviceID,
		MCI_SETAUDIO, MCI_DGV_SETAUDIO_VALUE | MCI_DGV_SETAUDIO_ITEM, (DWORD)(LPVOID)&mcisetvolumn);

}

void CplayerDlg::PlayTo(DWORD pos)//播放音乐
{
	

		MCI_PLAY_PARMS pp;
		pp.dwCallback = NULL;
		pp.dwFrom = pos;
		mciSendCommand(theApp.DeviceID, MCI_PLAY, MCI_FROM, (DWORD)&pp);

}

void CplayerDlg::OnNMReleasedcaptureProgress(NMHDR *pNMHDR, LRESULT *pResult)//拖动进度条到指定的播放位置播放
{
	DWORD seekto = progress.GetPos()*length;//获取拖动到的位置
	PlayTo(seekto);//播放
	*pResult = 0;
}

void CplayerDlg::OnBnClickedAddfile()//添加指定文件夹里的mp3音乐
{

	CString m_FileDir;
	BROWSEINFO bi;
	ZeroMemory(&bi, sizeof(BROWSEINFO));
	bi.hwndOwner = m_hWnd;
	bi.ulFlags = BIF_RETURNONLYFSDIRS;
	LPITEMIDLIST pidl = SHBrowseForFolder(&bi);
	BOOL bRet = FALSE;
	TCHAR szFolder[MAX_PATH * 2];
	szFolder[0] = _T('\0');
	if (pidl)
	{
		if (SHGetPathFromIDList(pidl, szFolder))
			bRet = TRUE;
		IMalloc *pMalloc = NULL;
		if (SUCCEEDED(SHGetMalloc(&pMalloc))
			&& pMalloc)
		{
			pMalloc->Free(pidl);
			pMalloc->Release();
		}
	}
	m_FileDir = szFolder;
	getmusic(m_FileDir);
}

void CplayerDlg::getmusic(CString path)//获取文件夹里的所有mp3音乐
{
	CFileFind ff;
	path += "\\";
	BOOL res = ff.FindFile(path + "*.mp3");
	int count = 0;
	while (res)
	{
		res = ff.FindNextFile();//如果还能找到mp3文件
		if (!ff.IsDirectory() && !ff.IsDots())
		{
			CString strFile = ff.GetFileName();
			m_List.InsertString(m_List.GetCount(), strFile);
			m_List.SetCurSel(m_List.GetCount() - 1);
			List.insert(pair<int, CString>(m_List.GetCount() - 1, path + strFile));
		}
		count++;

	}
	if (count <= 0)
		MessageBox("该文件夹里没有音乐文件!!-_-");
	else
	{
		if (pos == -1)//如果还没有选择音乐则pos自动定位到第一首音乐，以便于点击播放按键时可以立即播放
			pos = 0;
	}
	ff.Close();
}

void CplayerDlg::OnBnClickedClear()//清空播放列表
{
	OnBnClickedStop();//停止播放
	SetDlgItemText(IDC_NAME, "当前无播放");
	m_List.ResetContent();//清除列表歌曲信息
	List.clear();//清除播放路径map
}

void CplayerDlg::OnCbnSelchangePlayModel()//修改播放模式
{
	play_model = m_playmodel.GetCurSel();
}

void CplayerDlg::OnBnClickedRemove()//删除播放列表中指定歌曲
{
	int x=m_List.GetCurSel();//获得歌曲列表中被选中的项的序号
	if (x == -1)
	{
		MessageBox("未选中音乐-_-");
		return;
	}
	Remove(x);
}
void CplayerDlg::Remove(int p)
{
	List.erase(p);//在路径map中删除该项
	m_List.DeleteString(p);//在列表中删除该项
	map<int, CString>::iterator i;
	int index = 0;
	map<int, CString> temp;
	for (i = List.begin(); i != List.end(); i++)//重新给路径遍历map赋值
	{
		temp.insert((pair<int, CString>(index, i->second)));
		index++;
	}
	List = temp;
	if (pos == p)//如果删除的正好是在播放的项
	{
		OnBnClickedNext();//则使播放位置滚到下一曲
	}
}
void CplayerDlg::OnBnClickedAbout()//弹出关于对话框
{
	CAboutDlg t;
	t.DoModal();
}
void CplayerDlg::OnBnClickedHelpbtn()//打开帮助对话框
{
	CDialogHelp x;
	x.DoModal();

}
void CplayerDlg::openList()//获得播放列表
{
	ifstream LinN;
	LinN.open("Name.cjh");
	ifstream LinP;
	LinP.open("Path.cjh");
	char d = 3;
	string name;
	string path;
	if (getline(LinN,name,d)&&getline(LinP,path,d))
	{
		while ((!LinN.eof())&&(!LinP.eof()))
		{
			m_List.InsertString(m_List.GetCount(), CString(name.c_str()));
			m_List.SetCurSel(m_List.GetCount() - 1);
			List.insert(pair<int, CString>(m_List.GetCount() - 1, CString(path.c_str())));
			getline(LinN, name, d);
			getline(LinP, path, d);
		}
	}
	LinN.close();
	LinP.close();
}
void CplayerDlg::savelist()//保存播放列表
{
	if (m_List.GetCount() == 0 || List.empty())
		return;
	ofstream OutN("Name.cjh", ios::trunc | ios::left);
	ofstream OutP("Path.cjh", ios::trunc | ios::left);
	CString Cname, Cpath;
	int index = 0;
	char d = 3;
	map<int, CString>::iterator i;
	for (i = List.begin(); i != List.end(); i++)//重新给路径遍历map赋值
	{
		m_List.GetText(index, Cname);
		Cpath = i->second;
		
		OutN << left << CstringToString(Cname) << d;
		OutP << CstringToString(Cpath) << d;
		Cname = L"";
	    Cpath = L"";
		index++;
	}
	OutN.close();
	OutP.close();
}

string CplayerDlg::CstringToString(CString cstr)
{
	CStringA stra(cstr.GetBuffer(0));
	cstr.ReleaseBuffer();
	string str = stra.GetBuffer(0);
	stra.ReleaseBuffer();
	return str;
}
void CplayerDlg::OnClose()
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	savelist();
	CDialogEx::OnClose();
}

void CplayerDlg::OnBnClickedExit()
{
	

	OnClose();
	OnCancel();
}


void CplayerDlg::OnBnClickedAdvance()//快进
{
	int p = progress.GetPos();
	p += 50;
	progress.SetPos(p);
	DWORD seekto = progress.GetPos()*length;//获取拖动到的位置
	PlayTo(seekto);//播放
}




void CplayerDlg::OnBnClickedBack()//快退
{
	int p = progress.GetPos();
	p -= 50;
	progress.SetPos(p);
	DWORD seekto = progress.GetPos()*length;//获取拖动到的位置
	PlayTo(seekto);//播放
}



