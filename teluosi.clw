; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTeluosiView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "teluosi.h"
LastPage=0

ClassCount=5
Class1=CTeluosiApp
Class2=CTeluosiDoc
Class3=CTeluosiView
Class4=CMainFrame

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDD_DIALOG2
Class5=CAboutDlg
Resource3=IDD_DIALOG1
Resource4=IDR_MAINFRAME
Resource5=IDD_DIALOG3

[CLS:CTeluosiApp]
Type=0
HeaderFile=teluosi.h
ImplementationFile=teluosi.cpp
Filter=N

[CLS:CTeluosiDoc]
Type=0
HeaderFile=teluosiDoc.h
ImplementationFile=teluosiDoc.cpp
Filter=N

[CLS:CTeluosiView]
Type=0
HeaderFile=teluosiView.h
ImplementationFile=teluosiView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CTeluosiView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=ID_MENU_DSTART




[CLS:CAboutDlg]
Type=0
HeaderFile=teluosi.cpp
ImplementationFile=teluosi.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_MENU_START
Command2=ID_MENU_DSTART
Command3=ID_MENU_TSTART
Command4=ID_INTER
Command5=ID_MENU_PAUSE
Command6=ID_APP_EXIT
Command7=ID_VIEW_1
Command8=ID_VIEW_2
Command9=ID_APP_ABOUT
CommandCount=9

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[DLG:IDD_DIALOG1]
Type=1
Class=?
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[DLG:IDD_DIALOG2]
Type=1
Class=?
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT1,edit,1350631552

[DLG:IDD_DIALOG3]
Type=1
Class=?
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT1,edit,1350631552

