#if !defined(AFX_MINIT_H__CF7165EA_E82A_4776_A6A7_FE27BF8D772A__INCLUDED_)
#define AFX_MINIT_H__CF7165EA_E82A_4776_A6A7_FE27BF8D772A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// mINIT.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// mINIT dialog
#include "resource.h"

class mINIT : public CDialog
{
// Construction
public:
	mINIT(CWnd* pParent = NULL);   // standard constructor
	virtual	void  OnBtnRead(CString  CmdID);
	virtual	void  OnBtnwrite();	
// Dialog Data
	//{{AFX_DATA(mINIT)
	enum { IDD = IDD_mINIT };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


   CString score_Chinese, score_Mathematics,m_resulf;  

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(mINIT)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(mINIT)
		virtual BOOL OnInitDialog();
			afx_msg void OnUpdateStatus();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
		int m_iIndex;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MINIT_H__CF7165EA_E82A_4776_A6A7_FE27BF8D772A__INCLUDED_)
