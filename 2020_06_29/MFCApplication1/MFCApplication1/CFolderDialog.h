#pragma once
#pragma once

#include "afxdlgs.h"



class CFolderDialog : public CCommonDialog

{

public:

	CFolderDialog(CWnd* pParentWnd);



	CString m_sPath;

	BROWSEINFO  m_bi;



	static INT CALLBACK BrowseCallbackProc(IN HWND   hWnd, IN UINT   uMsg, IN LPARAM lParam, IN LPARAM lpData);

	int DoModal();

};



