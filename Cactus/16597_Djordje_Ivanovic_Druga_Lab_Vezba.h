
// 16597_Djordje_Ivanovic_Druga_Lab_Vezba.h : main header file for the 16597_Djordje_Ivanovic_Druga_Lab_Vezba application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMy16597DjordjeIvanovicDrugaLabVezbaApp:
// See 16597_Djordje_Ivanovic_Druga_Lab_Vezba.cpp for the implementation of this class
//

class CMy16597DjordjeIvanovicDrugaLabVezbaApp : public CWinAppEx
{
public:
	CMy16597DjordjeIvanovicDrugaLabVezbaApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy16597DjordjeIvanovicDrugaLabVezbaApp theApp;
