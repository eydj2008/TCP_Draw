// testserver.h : main header file for the TESTSERVER application
//

#if !defined(AFX_TESTSERVER_H__8511118A_6109_4A5E_9FF5_C03D593C2315__INCLUDED_)
#define AFX_TESTSERVER_H__8511118A_6109_4A5E_9FF5_C03D593C2315__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTestserverApp:
// See testserver.cpp for the implementation of this class
//

class CTestserverApp : public CWinApp
{
public:
	CTestserverApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestserverApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTestserverApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTSERVER_H__8511118A_6109_4A5E_9FF5_C03D593C2315__INCLUDED_)
