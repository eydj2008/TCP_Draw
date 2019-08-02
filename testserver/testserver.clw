; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTestserverDlg
LastTemplate=CAsyncSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "testserver.h"

ClassCount=5
Class1=CTestserverApp
Class2=CTestserverDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CSocketClient
Class4=CSocketServer
Resource3=IDD_TESTSERVER_DIALOG

[CLS:CTestserverApp]
Type=0
HeaderFile=testserver.h
ImplementationFile=testserver.cpp
Filter=N

[CLS:CTestserverDlg]
Type=0
HeaderFile=testserverDlg.h
ImplementationFile=testserverDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CTestserverDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=testserverDlg.h
ImplementationFile=testserverDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_TESTSERVER_DIALOG]
Type=1
Class=CTestserverDlg
ControlCount=12
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT_PORT,edit,1350631552
Control3=IDC_BUTTON_LISTEN,button,1342242816
Control4=IDC_STATIC,static,1342177296
Control5=IDC_STATIC_CONNECTED,static,1342308352
Control6=IDC_BUTTON_DISCONNECT,button,1342242816
Control7=IDC_STATIC,static,1342177296
Control8=IDC_EDIT_SEND,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_BUTTON_SEND,button,1342242816
Control11=IDC_EDIT_REC,edit,1352728580
Control12=IDC_STATIC,button,1342177287

[CLS:CSocketServer]
Type=0
HeaderFile=SocketServer.h
ImplementationFile=SocketServer.cpp
BaseClass=CAsyncSocket
Filter=N
VirtualFilter=q
LastObject=CSocketServer

[CLS:CSocketClient]
Type=0
HeaderFile=SocketClient.h
ImplementationFile=SocketClient.cpp
BaseClass=CAsyncSocket
Filter=N
LastObject=CSocketClient
VirtualFilter=q

