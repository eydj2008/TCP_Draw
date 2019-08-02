// testserverDlg.cpp : implementation file
//

#include "stdafx.h"
#include "testserver.h"
#include "testserverDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestserverDlg dialog

CTestserverDlg::CTestserverDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestserverDlg::IDD, pParent),m_pClient(NULL),m_iStarted(0)
{
	//{{AFX_DATA_INIT(CTestserverDlg)
	m_strEditRec = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestserverDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestserverDlg)
	DDX_Text(pDX, IDC_EDIT_REC, m_strEditRec);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTestserverDlg, CDialog)
	//{{AFX_MSG_MAP(CTestserverDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_BUTTON_LISTEN, OnButtonListen)
	ON_BN_CLICKED(IDC_BUTTON_SEND, OnButtonSend)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON_DISCONNECT, &CTestserverDlg::OnBnClickedButtonDisconnect)
	ON_BN_CLICKED(IDC_BUTTON_CLR, &CTestserverDlg::OnBnClickedButtonClr)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestserverDlg message handlers

BOOL CTestserverDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	GetDlgItem(IDC_EDIT_PORT)->SetWindowText("8080");
	SetButtonState();
	m_Server.SetMsgWnd(m_hWnd);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTestserverDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTestserverDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTestserverDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTestserverDlg::OnOK() 
{
	// TODO: Add extra validation here
	
//	CDialog::OnOK();
}

void CTestserverDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	if(m_iStarted)
		OnButtonListen();
	
	CDialog::OnCancel();
}

void CTestserverDlg::OnButtonListen() //建立端口
{
	// TODO: Add your control notification handler code here
	if(m_iStarted)
	{
		DelExistClient();
		m_Server.Close();
		m_iStarted=0;
	}
	else
	{
		CString str;
		GetDlgItem(IDC_EDIT_PORT)->GetWindowText(str);
		if(!m_Server.Create(atoi(str),SOCK_STREAM,FD_ACCEPT))  ///建立端口
		{
			MessageBox("创建服务器失败");
			return;
		}
		m_Server.Listen();
		m_iStarted=1;
	}
	SetButtonState();
}

LRESULT CTestserverDlg::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(message==WM_MSG_ADDCLIENT)//这里只保留最后一个连接
	{
		DelExistClient();
		m_pClient=(CSocketClient*)wParam;
		SetNewConnected();

		return 0;
	}
	else if(message==WM_MSG_REMOVECLIENT)
	{
		DelExistClient();
		SetDisconnect();

		return 0;
	}
	else if(message==WM_MSG_RECDATA)
	{
		AddRecData((BYTE*)wParam, lParam);
		return 0;
	}
	
	return CDialog::WindowProc(message, wParam, lParam);
}

void CTestserverDlg::SetNewConnected()
{
	SetButtonState();
}

void CTestserverDlg::SetDisconnect()
{
	SetButtonState();
}

void CTestserverDlg::DelExistClient()
{
	if(m_pClient!=NULL)//删除客户端
	{
		m_pClient->Close();
		delete m_pClient;
		m_pClient=NULL;
	}
}

void CTestserverDlg::SetButtonState()
{
	GetDlgItem(IDC_BUTTON_LISTEN)->SetWindowText(m_iStarted?"停止":"启动服务器");
	GetDlgItem(IDC_BUTTON_DISCONNECT)->ShowWindow(m_pClient!=NULL);
	GetDlgItem(IDC_BUTTON_SEND)->EnableWindow(m_pClient!=NULL);
	
	CString str;
	if(m_pClient!=NULL)
	{
		str.Format("%s 已经连接上",m_pClient->GetAddr());
	}
	GetDlgItem(IDC_STATIC_CONNECTED)->SetWindowText(str);   //显示连接IP
}

void CTestserverDlg::OnButtonSend() 
{
	// TODO: Add your control notification handler code here
	int len;
	CString str;
	GetDlgItem(IDC_EDIT_SEND)->GetWindowText(str);
	len=str.GetLength();
	int off=0;
	while(off<len)
	{
		int res=m_pClient->Send(((LPCTSTR)str)+off,len-off);
		if(res<=0)
		{
			MessageBox("发送失败");
			break;
		}
		off+=res;
	}
}

void CTestserverDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	CString str;
	
	//POINT   point;
	//LPPOINT pPoint=&point;
	//GetCursorPos(pPoint);  //得到鼠标位置
	str.Format("%03d,%03d", point.x, point.y);
	GetDlgItem(IDC_STATIC_POINT1)->SetWindowText(str);

#if 0
	int x,y;
	CRect rectDlg;
	//GetClientRect(rectDlg);//获得窗体的大小
	//GetWindowRect(rectDlg);//获得窗体在屏幕上的位置

	GetDlgItem(IDC_STATIC2)->GetWindowRect(&rectDlg);//获取控件基于全屏的位置
    ScreenToClient(rectDlg);//转换为对话框上的相对位置


	int DrawLinewidth = 3;
	//CPoint ptDrawOrigin;
	//ptDrawOrigin.x = x;
	//ptDrawOrigin.y = y;
	x = point.x;
	y = point.y;

	CPen pen1(PS_DOT, DrawLinewidth, RGB(255, 0, 0));//构造画笔对象  
    CClientDC dc1(this);  
    CPen *pOldPen = dc1.SelectObject(&pen1);//将画笔选入DC  
    //dc1.MoveTo(ptDrawOrigin);    ////当前线段的起始点

	int r = 5;
	int px,py;

	if (x>rectDlg.left && x<rectDlg.right && y>rectDlg.top && y<rectDlg.bottom)
	{
		dc1.MoveTo( x, y);
		for(int i = 0; i < 360; i ++)
		{
			px = x + r * cos((i * 1.0) / 180 * PI);
			py = y + r * sin((i * 1.0) / 180 * PI);

			dc1.LineTo( px, py);

			//int temp = i % 18;
			//if (temp > 7)
			//    dc1.LineTo(px, py, pz);
			//else
			//    dc1.MoveTo(px, py, pz);
		}
	}
	else
	{
		//FloodFill(dc1,0,0, RGB(230, 230, 230));   //CLR
		//SendMessage(WM_PAINT, (WPARAM) dc1.GetSafeHdc(), 0);
		dc1.FillSolidRect(rectDlg.left,rectDlg.top,rectDlg.Width(),rectDlg.Height(),RGB(190, 190, 190));
	}

	dc1.SelectObject(pOldPen);//恢复先前的画笔

	UpdateData(FALSE);
#endif

}

void CTestserverDlg::AddRecData(BYTE *pbuf, LPARAM Length)
{
	BYTE showdata[256];
	BYTE* pData = &showdata[0];
	int x=0,y=0;
	CString str;

	//对话框窗体大小及其屏幕坐标
	CRect rectDlg;
	//GetClientRect(rectDlg);//获得窗体的大小
	//GetWindowRect(rectDlg);//获得窗体在屏幕上的位置
	GetDlgItem(IDC_STATIC2)->GetWindowRect(&rectDlg);//获取控件基于全屏的位置
    ScreenToClient(rectDlg);//转换为对话框上的相对位置

	if (Length > 255) Length = 255;
	memcpy(showdata,  pbuf, Length);

	UpdateData(TRUE);
	
	for (UINT i=0; i<(UINT)Length; i++)
	{
		str.Format("%02X,",*(pbuf+i));
		m_strEditRec += str;
	}
	str.Format("\r\n");
	m_strEditRec += str;

	//------------------------------------------------------------------------

	//------------------------------------------------------------------------
	int DrawLinewidth = 3;
	static CPoint ptDrawOrigin;

	CPen pen1(PS_DOT, DrawLinewidth, RGB(255, 0, 0));//构造画笔对象  
    CClientDC dc1(this);  
    CPen *pOldPen = dc1.SelectObject(&pen1);//将画笔选入DC  

	WifiTouch_type* pTouch = (WifiTouch_type *)pData;              //强制成wifi格式

	x += ((pTouch->xH<<8)|pTouch->xL)*1.0/50;
	y += ((pTouch->yH<<8)|pTouch->yL)*1.0/50;

	if (ptDrawOrigin.x==0 || ptDrawOrigin.y==0)
	{
		ptDrawOrigin.x = x;  
		ptDrawOrigin.y = y; 
	}

	dc1.MoveTo(ptDrawOrigin);   ////当前线段的起始点

	if (pTouch->HEAD[0]==0xFD && pTouch->HEAD[1]==0xFD)
	{
		if (pTouch->ID==0x02)
		{
			if (pTouch->OP==0xA0)  //悬浮状态
			{
				dc1.MoveTo( x, y);
			}
			else if (pTouch->OP==0xA1)  //按下
			{
				dc1.LineTo( x, y);				
			}
			else //0xc0
			{
			    dc1.MoveTo( x, y);
			}	
		}
	}

    dc1.SelectObject(pOldPen);//恢复先前的画笔  
    ptDrawOrigin.x = x;  
	ptDrawOrigin.y = y; 

	str.Format("%03d,%03d", x, y);
	GetDlgItem(IDC_STATIC_POINT2)->SetWindowText(str);


	UpdateData(FALSE);

}


void CTestserverDlg::OnBnClickedButtonDisconnect()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CTestserverDlg::OnBnClickedButtonClr()
{
	// TODO: 在此添加控件通知处理程序代码

	int DrawLinewidth=3;
	CPen pen(PS_DOT, DrawLinewidth, RGB(255, 0, 0));//构造画笔对象  
    CClientDC dc(this);  
    CPen *pOldPen = dc.SelectObject(&pen);//将画笔选入DC  

	//对话框窗体大小及其屏幕坐标
	CRect rectDlg;
	//GetClientRect(rectDlg);//获得窗体的大小
	//GetWindowRect(rectDlg);//获得窗体在屏幕上的位置

	GetDlgItem(IDC_STATIC2)->GetWindowRect(&rectDlg);//获取控件基于全屏的位置
    ScreenToClient(rectDlg);//转换为对话框上的相对位置
	//FloodFill(dc1,0,0, RGB(230, 230, 230));   //CLR
		//SendMessage(WM_PAINT, (WPARAM) dc1.GetSafeHdc(), 0);
     dc.FillSolidRect(rectDlg.left,rectDlg.top,rectDlg.Width(),rectDlg.Height(),RGB(100, 100, 100));

	 UpdateData(FALSE);

}
