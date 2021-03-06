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

AppCmds::AppCmds(AppWnd& appWnd)
	: CCmdControl(appWnd, IDR_APPTOOLBAR)
{
	// Define the command table.
	DEFINE_CMD_TABLE
		// File menu.
		CMD_ENTRY(ID_FILE_EXIT,		&AppCmds::onFileExit,	nullptr,	-1)
		// Help menu.
		CMD_ENTRY(ID_HELP_ABOUT,	&AppCmds::onHelpAbout,	nullptr,	 2)
	END_CMD_TABLE
}

////////////////////////////////////////////////////////////////////////////////
//! Destructor.

AppCmds::~AppCmds()
{
}

////////////////////////////////////////////////////////////////////////////////
//! Close the application.

void AppCmds::onFileExit()
{
	g_app.m_appWnd.Close();
}

////////////////////////////////////////////////////////////////////////////////
//! Show the about dialog.

void AppCmds::onHelpAbout()
{
	AboutDlg aboutDlg;

	aboutDlg.RunModal(g_app.m_appWnd);
}
