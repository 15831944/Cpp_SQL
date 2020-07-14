
// TEST_CREATEDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TEST_CREATE.h"
#include "TEST_CREATEDlg.h"
#include "afxdialogex.h"
#include <iostream>
#include <cstring>
#include <atlstr.h>
#include <WinBase.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTEST_CREATEDlg dialog



CTEST_CREATEDlg::CTEST_CREATEDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TEST_CREATE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTEST_CREATEDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_strFFolder);
	DDX_Control(pDX, IDC_EDIT2, m_strFPath);
	DDX_Control(pDX, IDC_EDIT3, m_strFName);
}

BEGIN_MESSAGE_MAP(CTEST_CREATEDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CTEST_CREATEDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CTEST_CREATEDlg message handlers

BOOL CTEST_CREATEDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTEST_CREATEDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTEST_CREATEDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTEST_CREATEDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTEST_CREATEDlg::OnBnClickedButton1()
{/*
	//char szFilter[20]  ;
	CString szFilter = _T("txt file(*.txt)|*.txt; |ALL File(*.*(|*.*||");
	CFileDialog dlg(FALSE, _T(""), NULL, OFN_OVERWRITEPROMPT, szFilter);
	//CFileDialog dlg(FALSE, "bmp", "pcmon", OFN_OVERWRITEPROMPT, szFilter);
	// TODO: Add your control notification handler code here
	CString strFolder;
	CString strPath;
	CString strFileName;
	CString strFolderPath;
	if (IDOK == dlg.DoModal())
	{
		strFolder = dlg.GetFolderPath();
		strPath = dlg.GetPathName();
		strFileName = dlg.GetFileName();

		m_strFFolder.SetWindowTextW(strFolder);
		m_strFPath.SetWindowTextW(strPath);
		m_strFName.SetWindowTextW(strFileName); 
		int temp = strPath.ReverseFind('\\');
		CString re = strPath.Mid(0, strPath.ReverseFind('\\'));
		CString res = strPath.Mid(strPath.ReverseFind('\\')+1, strPath.GetLength());
	}*/
	

	//ini ���� ����
	CString pah;
	CString asdf;
	char buff[256];
	TCHAR sDIr[260];
	ITEMIDLIST  *pidlBrowse;
	TCHAR        pszPathname[MAX_PATH];
	BROWSEINFO  BrInfo;
	BrInfo.hwndOwner = GetSafeHwnd();
	BrInfo.pidlRoot = NULL;
	memset(&BrInfo, 0, sizeof(BrInfo));
	BrInfo.pszDisplayName = (LPWSTR)pszPathname;

	BrInfo.lpszTitle = L"������ ������ �ֽʽÿ�.";
	BrInfo.ulFlags = BIF_EDITBOX;
	// ���̾�α� ����
	pidlBrowse = SHBrowseForFolder(&BrInfo);

	if (pidlBrowse != NULL)
	{
		// ������ ������θ� ����
		BOOL bSuccess = ::SHGetPathFromIDListW(pidlBrowse, pszPathname);

		if (bSuccess)
		{
			//m_SelectedFolder = pszPathname;   //<-- ���⼭ ���� �Է�
			UpdateData(FALSE);
		}
		else
		{
			MessageBox(L"�߸��� �������Դϴ�.", L"", MB_OKCANCEL | MB_ICONASTERISK);
		}
	}



	char *cBuf = NULL; 
	CString* dd[256] ;
 

	cBuf = (char *)malloc(sizeof(char) * 256); 
	memset(cBuf, 0x00, sizeof(cBuf));


	pah.Format(_T("C:\\Users\\mnsoft\\Desktop\\temp3\\test.ini"));

	//WritePrivateProfileString(_T("Section_1"), _T("key_1"), _T("True"), pah);
	//WritePrivateProfileString(_T("Section_2"), _T("key_1"), _T("True"), pah);
	//GetPrivateProfileString(_T("Section_1"), _T("key_1"), _T("��Ͼ���") , sDIr,260 ,_T("C:\\Users\\mnsoft\\Desktop\\temp3\\test.ini"));
	

	TCHAR path[260];
	GetModuleFileName(NULL, path, sizeof path);
	CString strPath = path;

	int i = strPath.ReverseFind('\\'); //���� ���� �̸��� ����� ���� 
	strPath = strPath.Left(i); //�ڿ��ִ� ���� ���� ���� �̸��� �����.
	//AfxMessageBox(strPath);


	//�ش��ο� �����ִ��� Ȯ���ϴ� ��
	CFileFind  cFileFinder;
	bool temp=  cFileFinder.FindFile(_T("C:\\Users\\SW\\Desktop"));
 
	CString tempSrt = _T("abcd    abc");
	tempSrt.Remove(_T(' '));

	//MessageBox(tempSrt);
}
 

BOOL CTEST_CREATEDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
	{
		if (GetDlgItem(IDC_BUTTON1) == GetFocus())
		{
			OnBnClickedButton1();
			//		 return TRUE;


		}

	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
