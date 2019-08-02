#if !defined(AFX_SOCKETSERVER_H__14D34788_FE48_4EAE_B33A_9E5F08EA5C46__INCLUDED_)
#define AFX_SOCKETSERVER_H__14D34788_FE48_4EAE_B33A_9E5F08EA5C46__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SocketServer.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CSocketServer command target
#define	WM_MSG_ADDCLIENT	WM_USER+103

class CSocketServer : public CAsyncSocket
{
// Attributes
public:

// Operations
public:
	CSocketServer();
	virtual ~CSocketServer();

// Overrides
public:
	void SetMsgWnd(HWND hwnd);
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSocketServer)
	public:
	virtual void OnAccept(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CSocketServer)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
private:
	HWND m_hWndMsg;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SOCKETSERVER_H__14D34788_FE48_4EAE_B33A_9E5F08EA5C46__INCLUDED_)
