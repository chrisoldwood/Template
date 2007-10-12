////////////////////////////////////////////////////////////////////////////////
//! \file   AppWnd.cpp
//! \brief  The AppWnd class definition.
//! \author Chris Oldwood

#include "Common.hpp"
#include "AppWnd.hpp"

////////////////////////////////////////////////////////////////////////////////
//! Constructor.

AppWnd::AppWnd()
	: CDlgFrame(IDR_APPICON, m_oAppDlg, false)
{
}

////////////////////////////////////////////////////////////////////////////////
//! Destructor.

AppWnd::~AppWnd()
{
}

////////////////////////////////////////////////////////////////////////////////
//! Handle window creation.

void AppWnd::OnCreate(const CRect& rcClient)
{
	//
	// Create and attach the components.
	//
	m_oAccel.LoadRsc(IDR_APPACCEL);
	Accel(&m_oAccel);

	m_oMenu.LoadRsc(IDR_APPMENU);
	Menu(&m_oMenu);

	m_oToolbar.Create(*this, IDC_TOOL_BAR, rcClient);
	ToolBar(&m_oToolbar);

	m_oStatusbar.Create(*this, IDC_STATUS_BAR, rcClient);
	StatusBar(&m_oStatusbar);

	m_oAppDlg.RunModeless(*this);

	// Call base class.
	CDlgFrame::OnCreate(rcClient);
}
