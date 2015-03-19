
// mp3Dlg.cpp : ʵ���ļ�
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


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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
// CDialogHelp �Ի���

class CDialogHelp : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogHelp)

public:
	CDialogHelp(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDialogHelp();

	virtual void OnFinalRelease();

	// �Ի�������
	enum { IDD = IDD_HELPDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease��  ���ཫ�Զ�
	// ɾ���ö���  �ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

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

// ע��: ������� IID_IDialogHelp ֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡�  �� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {41715B23-78F5-478D-8F46-FC2C43832B5F}
static const IID IID_IDialogHelp =
{ 0x41715B23, 0x78F5, 0x478D, { 0x8F, 0x46, 0xFC, 0x2C, 0x43, 0x83, 0x2B, 0x5F } };

BEGIN_INTERFACE_MAP(CDialogHelp, CDialogEx)
	INTERFACE_PART(CDialogHelp, IID_IDialogHelp, Dispatch)
END_INTERFACE_MAP()


// Cmp3Dlg �Ի���



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


// Cmp3Dlg ��Ϣ�������

BOOL CplayerDlg::OnInitDialog()
{

	CDialogEx::OnInitDialog();
	
	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��
	m_playbtn.SetBitmap(::LoadBitmap(AfxGetResourceHandle(), MAKEINTRESOURCE(IDB_BITMAP6)));
	ShowWindow(SW_NORMAL);
	
	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	progress.SetRange(0, 1000);//��ʼ��������
	m_vol.SetRange(0, 100);//��ʼ��������
	
	//��ʼ������ģʽѡ��
	m_playmodel.InsertString(0,"�б�ѭ��");
	m_playmodel.InsertString(1,"����ѭ��");
	m_playmodel.InsertString(2,"�������");
	m_playmodel.SetCurSel(0);
	play_model = 0;//����ģʽѡ��Ĭ��Ϊ�б�ѭ��
	openList();
	m_vol.SetPos(50);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CplayerDlg::OnPaint()
{
	
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{//���뱳��
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

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CplayerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}






void CplayerDlg::OnBnClickedPlay()//��������
{
	DWORD info = theApp.getinformation(MCI_STATUS_MODE);//��ȡ״̬
	if (info == MCI_MODE_PAUSE)//
	{
		
		m_playbtn.SetBitmap(::LoadBitmap(AfxGetResourceHandle(), MAKEINTRESOURCE(IDB_BITMAP5)));//�ı䲥�Ű�ť״̬
		theApp.resum();
		return;
	}
	else
	if (info == MCI_MODE_PLAY)
	{
		m_playbtn.SetBitmap(::LoadBitmap(AfxGetResourceHandle(), MAKEINTRESOURCE(IDB_BITMAP6)));//ͬ��
		theApp.Pause();
		return;
	}
	else
	{
		pos = m_List.GetCurSel();//�õ����ŵ���Ŀλ��
		PlayMusic(true);
	}
}

void CplayerDlg::OnBnClickedPre()//��һ��
{
	if (pos == -1)//���û�����ֻ�����û��ѡ������
	{
		if (m_List.GetCount() == 0)
		{
			MessageBox("���������");
			return;
		}
		MessageBox("��ѡ������");
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

void CplayerDlg::OnBnClickedNext()//��һ��
{
	if (pos == -1)//���û�����ֻ�û��ѡ������
	{
		if (m_List.GetCount() == 0)
		{
			MessageBox("���������");
			return;
		}
		MessageBox("��ѡ������");
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
		pos =rand() % m_List.GetCount();//������ţ����ѡ�񲥷��б��ϵ���Ŀ���в���
		break;
	}
	
	PlayMusic(false);
}


void CplayerDlg::OnBnClickedImport()//��ӵ�������
{
	
	CFileDialog open(true);
	open.m_ofn.lpstrTitle="�������ļ���";//�����L��ʾunicode
	open.m_ofn.lpstrFilter = "mp3 �ļ�(*.mp3)\0*.mp3\0WAV�ļ�(*.wav)\0*.wav\0WMA�ļ�(*.wma)\0 * .wav\0APE�ļ�(*.ape)\0*.ape\0\0";

	if (open.DoModal() == IDOK)
	{
		CString strfilepath = open.GetPathName();
		CString strfilename = open.GetFileName();
		m_List.InsertString(m_List.GetCount(), strfilename);
		List.insert(pair<int, CString>(m_List.GetCount() - 1, strfilepath));
	}
	if (pos == -1)//�����û��ѡ��������pos�Զ���λ����һ�����֣��Ա��ڵ�����Ű���ʱ������������
		pos = 0;
}


void CplayerDlg::OnBnClickedStop()//ֹͣ
{
	m_playbtn.SetBitmap(::LoadBitmap(AfxGetResourceHandle(), MAKEINTRESOURCE(IDB_BITMAP6)));//���ż���λ
	SetDlgItemText(IDC_NAME, "��ǰ�޲���");
	SetDlgItemText(IDC_TIME, "00:00");
	SetDlgItemText(IDC_NOW, "00:00");
	progress.SetPos(0);//��������λ
	theApp.Stop();//ֹͣ����
	KillTimer(0);//������ʱ
}



void CplayerDlg::OnLbnDblclkList()//˫�������б�����������
{
	pos = m_List.GetCurSel();
	PlayMusic(true);
	
}
void CplayerDlg::PlayMusic(bool isclick)//����posλ�õ�����
{
	CString strfilename;//�����ļ����ı���
	if (pos == -1)//���û��ѡ�����ֻ���û�����ֿɲ���
	{
		if (m_List.GetCount() ==0)
		{
			MessageBox("���������");
			return;
		}
		MessageBox("��ѡ������");
	}
	else
	{
		m_List.GetText(pos, strfilename);//�Ӳ����б���л�ȡ������
		SetDlgItemText(IDC_NAME, strfilename);//��ʾ������
		theApp.Stop();//ֹͣ��ǰ����
		if (theApp.Load(this->m_hWnd, List.at(pos)))//�����������ɹ�
		{
			long l = theApp.getinformation(MCI_STATUS_LENGTH);//��ȡ��������
			length = l / 1000;//ת��Ϊ��
			CString s;//������ʾʱ��
			CTime x(length);//��ʼ��Ϊʱ��
			s = x.Format("%M:%S");//��ʽ��Ϊ������ʽ(�������β���ô����T_T�����������������)
			SetDlgItemText(IDC_TIME, s);//��ʾ������

			theApp.Play();//��ʼ����
			SetVolumn(m_vol.GetPos());//��ȡ����������
			m_playbtn.SetBitmap(::LoadBitmap(AfxGetResourceHandle(), MAKEINTRESOURCE(IDB_BITMAP5)));
			//�ı䲥�Ű�ť��״̬
			SetTimer(0, 1000, NULL);//���ü�ʱ��
			OnTimer(0);//��ʱ��ʼ
		}
		else
		{
			if (isclick)
			{
				MessageBox( "��ʼ��MCIʱ�������⣬�޷����Ÿ�����", "����", MB_ICONHAND | MB_ICONERROR | MB_ICONSTOP);
				
			}
			if (m_List.GetCount() <= 1)//����ֻ��һ�׸���ʱ��ѭ��
				return;

			Remove(pos);//����MCI��ʼ��ʧ���Զ�������һ��
			
		}
	}
}

void CplayerDlg::OnTimer(UINT_PTR nIDEvent)//��ʱ��
{
	DWORD info = theApp.getinformation(MCI_STATUS_MODE);//��ȡ�豸��ǰ״̬
	if (info == MCI_MODE_STOP)//�����ǰ�������Ž���
	{
		OnBnClickedNext();//������һ��
		return;
	}
	if (info == MCI_MODE_PLAY || info == MCI_MODE_PAUSE)//������ڲ��Ż��Ѿ���ͣ
	{
	DWORD p_pos = theApp.getinformation(MCI_STATUS_POSITION);//��ȡ���ŵ�λ��
	double progress_pos = (p_pos/length) ;//ת��Ϊ�������ĳ��ȷ�Χ
	progress.SetPos(progress_pos);//���ý�����λ��
	long now = p_pos / 1000;//��ȡ��ǰ����ʱ�����
	CString s;//������ʾʱ��
	CTime x(now);//��ʼ��Ϊʱ��
	s = x.Format("%M:%S");//��ʽ��Ϊ������ʽ
	SetDlgItemText(IDC_NOW, s);//��ʾ������
	if (progress_pos >= progress.GetRangeMax()-5)//������Ž���
	{
		OnBnClickedNext();//������һ��
		return;
	}
	CDialogEx::OnTimer(nIDEvent);
	UpdateData(FALSE);
	}
	
}
void CplayerDlg::OnNMReleasedcaptureSlider2(NMHDR *pNMHDR, LRESULT *pResult)//�û��ı䲥������
{
	SetVolumn(m_vol.GetPos());//��ȡ�϶�����λ��
	UpdateData(false);
	*pResult = 0;
}
void CplayerDlg::SetVolumn(DWORD vol)//��������
{
	MCI_DGV_SETAUDIO_PARMS mcisetvolumn;
	mcisetvolumn.dwItem = MCI_DGV_SETAUDIO_VOLUME;
	mcisetvolumn.dwValue = vol;//����ֵ
	mciSendCommand(theApp.DeviceID,
		MCI_SETAUDIO, MCI_DGV_SETAUDIO_VALUE | MCI_DGV_SETAUDIO_ITEM, (DWORD)(LPVOID)&mcisetvolumn);

}

void CplayerDlg::PlayTo(DWORD pos)//��������
{
	

		MCI_PLAY_PARMS pp;
		pp.dwCallback = NULL;
		pp.dwFrom = pos;
		mciSendCommand(theApp.DeviceID, MCI_PLAY, MCI_FROM, (DWORD)&pp);

}

void CplayerDlg::OnNMReleasedcaptureProgress(NMHDR *pNMHDR, LRESULT *pResult)//�϶���������ָ���Ĳ���λ�ò���
{
	DWORD seekto = progress.GetPos()*length;//��ȡ�϶�����λ��
	PlayTo(seekto);//����
	*pResult = 0;
}

void CplayerDlg::OnBnClickedAddfile()//���ָ���ļ������mp3����
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

void CplayerDlg::getmusic(CString path)//��ȡ�ļ����������mp3����
{
	CFileFind ff;
	path += "\\";
	BOOL res = ff.FindFile(path + "*.mp3");
	int count = 0;
	while (res)
	{
		res = ff.FindNextFile();//��������ҵ�mp3�ļ�
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
		MessageBox("���ļ�����û�������ļ�!!-_-");
	else
	{
		if (pos == -1)//�����û��ѡ��������pos�Զ���λ����һ�����֣��Ա��ڵ�����Ű���ʱ������������
			pos = 0;
	}
	ff.Close();
}

void CplayerDlg::OnBnClickedClear()//��ղ����б�
{
	OnBnClickedStop();//ֹͣ����
	SetDlgItemText(IDC_NAME, "��ǰ�޲���");
	m_List.ResetContent();//����б������Ϣ
	List.clear();//�������·��map
}

void CplayerDlg::OnCbnSelchangePlayModel()//�޸Ĳ���ģʽ
{
	play_model = m_playmodel.GetCurSel();
}

void CplayerDlg::OnBnClickedRemove()//ɾ�������б���ָ������
{
	int x=m_List.GetCurSel();//��ø����б��б�ѡ�е�������
	if (x == -1)
	{
		MessageBox("δѡ������-_-");
		return;
	}
	Remove(x);
}
void CplayerDlg::Remove(int p)
{
	List.erase(p);//��·��map��ɾ������
	m_List.DeleteString(p);//���б���ɾ������
	map<int, CString>::iterator i;
	int index = 0;
	map<int, CString> temp;
	for (i = List.begin(); i != List.end(); i++)//���¸�·������map��ֵ
	{
		temp.insert((pair<int, CString>(index, i->second)));
		index++;
	}
	List = temp;
	if (pos == p)//���ɾ�����������ڲ��ŵ���
	{
		OnBnClickedNext();//��ʹ����λ�ù�����һ��
	}
}
void CplayerDlg::OnBnClickedAbout()//�������ڶԻ���
{
	CAboutDlg t;
	t.DoModal();
}
void CplayerDlg::OnBnClickedHelpbtn()//�򿪰����Ի���
{
	CDialogHelp x;
	x.DoModal();

}
void CplayerDlg::openList()//��ò����б�
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
void CplayerDlg::savelist()//���沥���б�
{
	if (m_List.GetCount() == 0 || List.empty())
		return;
	ofstream OutN("Name.cjh", ios::trunc | ios::left);
	ofstream OutP("Path.cjh", ios::trunc | ios::left);
	CString Cname, Cpath;
	int index = 0;
	char d = 3;
	map<int, CString>::iterator i;
	for (i = List.begin(); i != List.end(); i++)//���¸�·������map��ֵ
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
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	savelist();
	CDialogEx::OnClose();
}

void CplayerDlg::OnBnClickedExit()
{
	

	OnClose();
	OnCancel();
}


void CplayerDlg::OnBnClickedAdvance()//���
{
	int p = progress.GetPos();
	p += 50;
	progress.SetPos(p);
	DWORD seekto = progress.GetPos()*length;//��ȡ�϶�����λ��
	PlayTo(seekto);//����
}




void CplayerDlg::OnBnClickedBack()//����
{
	int p = progress.GetPos();
	p -= 50;
	progress.SetPos(p);
	DWORD seekto = progress.GetPos()*length;//��ȡ�϶�����λ��
	PlayTo(seekto);//����
}



