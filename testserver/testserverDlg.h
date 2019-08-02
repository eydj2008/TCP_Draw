// testserverDlg.h : header file
//

#if !defined(AFX_TESTSERVERDLG_H__D61CB74F_D5E2_49A1_AFC7_2472604ED13E__INCLUDED_)
#define AFX_TESTSERVERDLG_H__D61CB74F_D5E2_49A1_AFC7_2472604ED13E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTestserverDlg dialog
#include "SocketServer.h"
#include "SocketClient.h"

typedef BYTE u8;
//=============================================================================
typedef struct tWifiTouch
{    
      u8  HEAD[2];
      u8  ID;   //´¥ÃþË÷ÒýºÅ
      u8  OP; //State; Command
      u8  xL;     
      u8  xH;
      u8  yL;
      u8  yH;
      u8  zL;    //Ñ¹¸ÐÖµ
      u8  zH;
 
} WifiTouch_type;

class CTestserverDlg : public CDialog
{
// Construction
public:
	WifiTouch_type WifiTouch;


	void AddRecData(BYTE* pbuf, LPARAM Length);
	void SetButtonState();
	void DelExistClient();
	void SetDisconnect();
	void SetNewConnected();
	CTestserverDlg(CWnd* pParent = NULL);	// standard constructor

	CSocketServer m_Server;
	CSocketClient* m_pClient;

// Dialog Data
	//{{AFX_DATA(CTestserverDlg)
	enum { IDD = IDD_TESTSERVER_DIALOG };
	CString	m_strEditRec;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestserverDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTestserverDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnButtonListen();
	afx_msg void OnButtonSend();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int m_iStarted;
public:
	afx_msg void OnBnClickedButtonDisconnect();
	afx_msg void OnBnClickedButtonClr();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTSERVERDLG_H__D61CB74F_D5E2_49A1_AFC7_2472604ED13E__INCLUDED_)
