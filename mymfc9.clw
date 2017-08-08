; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDieViewer
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "mymfc9.h"
LastPage=0

ClassCount=6
Class1=CMymfc9App
Class2=CMymfc9Doc
Class3=CMymfc9View
Class4=CMainFrame

ResourceCount=3
Resource1=IDR_MAINFRAME
Resource2=IDD_ABOUTBOX
Class5=CAboutDlg
Class6=CDieViewer
Resource3=IDD_DieViewer

[CLS:CMymfc9App]
Type=0
HeaderFile=mymfc9.h
ImplementationFile=mymfc9.cpp
Filter=N

[CLS:CMymfc9Doc]
Type=0
HeaderFile=mymfc9Doc.h
ImplementationFile=mymfc9Doc.cpp
Filter=N

[CLS:CMymfc9View]
Type=0
HeaderFile=mymfc9View.h
ImplementationFile=mymfc9View.cpp
Filter=C
LastObject=CMymfc9View
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=mymfc9.cpp
ImplementationFile=mymfc9.cpp
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
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY
Command10=ID_EDIT_PASTE
Command11=ID_VIEW_TOOLBAR
Command12=ID_VIEW_STATUS_BAR
Command13=ID_APP_ABOUT
CommandCount=13

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

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

[DLG:IDD_DieViewer]
Type=1
Class=CDieViewer
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_PATH,edit,1350631552
Control5=IDC_DiePic,static,1342177294
Control6=IDC_BTNLAUNCH,button,1342242816

[CLS:CDieViewer]
Type=0
HeaderFile=DieViewer.h
ImplementationFile=DieViewer.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CDieViewer

