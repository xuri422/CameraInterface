#if !defined(AFX_DIALOGEX_H__837C02D0_C884_48FE_9957_75F1A62C9CB9__INCLUDED_)
#define AFX_DIALOGEX_H__837C02D0_C884_48FE_9957_75F1A62C9CB9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DialogEX.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DialogEX dialog

#include "resource.h"

class DialogEX : public CDialog
{
// Construction
public:
	DialogEX(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DialogEX)
	enum { IDD = IDD_DIALOGEX };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DialogEX)
	public:
//	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	virtual BOOL DestroyWindow();
	virtual int DoModal();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DialogEX)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

 private:
		int m_iIndex;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGEX_H__837C02D0_C884_48FE_9957_75F1A62C9CB9__INCLUDED_)
