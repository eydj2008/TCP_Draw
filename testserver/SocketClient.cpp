// SocketClient.cpp : implementation file
//

#include "stdafx.h"
#include "testserver.h"
#include "SocketClient.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSocketClient

CSocketClient::CSocketClient()
{
}

CSocketClient::~CSocketClient()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CSocketClient, CAsyncSocket)
	//{{AFX_MSG_MAP(CSocketClient)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CSocketClient member functions

void CSocketClient::OnReceive(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(nErrorCode==0)
	{
		BYTE buffer[1025]={0};
		int res=Receive(buffer,1024);
		if(res>0)  //res 数据长度
		{
			buffer[res]=0;
			::SendMessage(m_hWndMsg,WM_MSG_RECDATA,(WPARAM)buffer,(LPARAM)res);        //发送接收信息
		}
	}
		
	CAsyncSocket::OnReceive(nErrorCode);
}

void CSocketClient::OnClose(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	::PostMessage(m_hWndMsg,WM_MSG_REMOVECLIENT,(WPARAM)this,0);
	
	CAsyncSocket::OnClose(nErrorCode);
}

void CSocketClient::SetAddr(CString str)
{
	m_strIP=str;
}

CString CSocketClient::GetAddr()
{
	return m_strIP;
}

void CSocketClient::SetMsgHwnd(HWND hwnd)
{
	m_hWndMsg=hwnd;
}
