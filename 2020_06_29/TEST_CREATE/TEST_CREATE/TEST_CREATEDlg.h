
// TEST_CREATEDlg.h : header file
//

#pragma once
#include "afxwin.h"

#define _MAX_PATH 260;
// CTEST_CREATEDlg dialog
class CTEST_CREATEDlg : public CDialogEx
{
// Construction
public:
	CTEST_CREATEDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEST_CREATE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CEdit m_strFFolder;
	CEdit m_strFPath;
	CEdit m_strFName;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
