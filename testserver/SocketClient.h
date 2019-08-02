#if !defined(AFX_SOCKETCLIENT_H__27590025_AEFC_4A85_83B6_0CA6C32D5BC9__INCLUDED_)
#define AFX_SOCKETCLIENT_H__27590025_AEFC_4A85_83B6_0CA6C32D5BC9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SocketClient.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CSocketClient command target
#define WM_MSG_REMOVECLIENT	WM_USER+104
#define WM_MSG_RECDATA		WM_USER+105

class CSocketClient : public CAsyncSocket
{
// Attributes
public:

// Operations
public:
	CSocketClient();
	virtual ~CSocketClient();

// Overrides
public:
	void SetMsgHwnd(HWND hwnd);
	CString GetAddr();
	void SetAddr(CString str);
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSocketClient)
	public:
	virtual void OnReceive(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CSocketClient)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
private:
	HWND m_hWndMsg;
	CString m_strIP;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SOCKETCLIENT_H__27590025_AEFC_4A85_83B6_0CA6C32D5BC9__INCLUDED_)
