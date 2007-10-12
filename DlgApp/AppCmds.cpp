////////////////////////////////////////////////////////////////////////////////
//! \file   AppCmds.cpp
//! \brief  The AppCmds class definition.
//! \author Chris Oldwood

#include "Common.hpp"
#include "AppCmds.hpp"
#include "TheApp.hpp"
#include "AboutDlg.hpp"

////////////////////////////////////////////////////////////////////////////////
//! Constructor.

AppCmds::AppCmds()
{
	// Define the command table.
	DEFINE_CMD_TABLE
		// File menu.
		CMD_ENTRY(ID_FILE_EXIT,			OnFileExit,			NULL,				-1)
		// Help menu.
		CMD_ENTRY(ID_HELP_ABOUT,		OnHelpAbout,		NULL,				2)
	END_CMD_TABLE
}

////////////////////////////////////////////////////////////////////////////////
//! Destructor.

AppCmds::~AppCmds()
{
}

////////////////////////////////////////////////////////////////////////////////
//! Close the application.

void AppCmds::OnFileExit()
{
	App.m_oAppWnd.Close();
}

////////////////////////////////////////////////////////////////////////////////
//! Show the about dialog.

void AppCmds::OnHelpAbout()
{
	AboutDlg Dlg;

	Dlg.RunModal(App.m_oAppWnd);
}
