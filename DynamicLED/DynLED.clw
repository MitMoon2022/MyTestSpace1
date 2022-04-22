; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDynLEDDlg
LastTemplate=CStatic
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "DynLED.h"

ClassCount=3
Class1=CDynLEDApp
Class2=CDynLEDDlg

ResourceCount=2
Resource1=IDR_MAINFRAME
Class3=CDynamicLED
Resource2=IDD_DYNLED_DIALOG

[CLS:CDynLEDApp]
Type=0
HeaderFile=DynLED.h
ImplementationFile=DynLED.cpp
Filter=N

[CLS:CDynLEDDlg]
Type=0
HeaderFile=DynLEDDlg.h
ImplementationFile=DynLEDDlg.cpp
Filter=D
LastObject=IDC_STATIC_LED_BLUE
BaseClass=CDialog
VirtualFilter=dWC



[DLG:IDD_DYNLED_DIALOG]
Type=1
Class=CDynLEDDlg
ControlCount=10
Control1=IDC_STATIC_LED_BLUE,static,1342177298
Control2=IDC_STATIC_LED,static,1342177298
Control3=IDC_STATIC_LED_RED,static,1342177298
Control4=IDC_STATIC_LED_YELLOW,static,1342177298
Control5=IDOK,button,1342242816
Control6=IDCANCEL,button,1342242816
Control7=IDC_BTN_SWITCHON,button,1342242816
Control8=IDC_BTN_SWITCHOFF,button,1342242816
Control9=IDC_BTN_CHANGESHAPE,button,1342242816
Control10=IDC_STATIC,button,1342177287

[CLS:CDynamicLED]
Type=0
HeaderFile=DynamicLED.h
ImplementationFile=DynamicLED.cpp
BaseClass=CStatic
Filter=W
LastObject=CDynamicLED
VirtualFilter=WC

