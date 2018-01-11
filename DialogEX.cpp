// DialogEX.cpp : implementation file
//

#include "stdafx.h"
//#include "camerainterface.h"
#include "DialogEX.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogEX dialog


DialogEX::DialogEX(CWnd* pParent /*=NULL*/)
	: CDialog(DialogEX::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogEX)
	m_iIndex=0;
	//}}AFX_DATA_INIT
}


void DialogEX::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogEX)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogEX, CDialog)
	//{{AFX_MSG_MAP(DialogEX)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogEX message handlers
/*
BOOL DialogEX::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDialog::Create(IDD, pParentWnd);
}
*/
BOOL DialogEX::DestroyWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDialog::DestroyWindow();
}

int DialogEX::DoModal() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDialog::DoModal();
}
