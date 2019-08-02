// SocketServer.cpp : implementation file
//

#include "stdafx.h"
#include "testserver.h"
#include "SocketServer.h"
#include "SocketClient.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSocketServer

CSocketServer::CSocketServer()
{
}

CSocketServer::~CSocketServer()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CSocketServer, CAsyncSocket)
	//{{AFX_MSG_MAP(CSocketServer)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CSocketServer member functions

void CSocketServer::OnAccept(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(nErrorCode==0)
	{
		CSocketClient* pclient=new CSocketClient;
		SOCKADDR addr;
		int addrlen=sizeof(SOCKADDR);
		if(Accept(*pclient,&addr,&addrlen))
		{
			sockaddr_in* p=(sockaddr_in*)&addr;
			CString str;
			str.Format("%d.%d.%d.%d",p->sin_addr.S_un.S_un_b.s_b1,
				p->sin_addr.S_un.S_un_b.s_b2,p->sin_addr.S_un.S_un_b.s_b3,
				p->sin_addr.S_un.S_un_b.s_b4);
			pclient->SetAddr(str);
			pclient->SetMsgHwnd(m_hWndMsg);
			pclient->AsyncSelect(FD_READ|FD_CLOSE);
			::PostMessage(m_hWndMsg,WM_MSG_ADDCLIENT,(WPARAM)pclient,0);
		}
	}
	
	CAsyncSocket::OnAccept(nErrorCode);
}

void CSocketServer::SetMsgWnd(HWND hwnd)
{
	m_hWndMsg=hwnd;
}
