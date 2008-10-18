////////////////////////////////////////////////////////////////////////////////
//! \file   TheApp.cpp
//! \brief  The TheApp class definition.
//! \author Chris Oldwood

#include "Common.hpp"
#include "TheApp.hpp"
#include <WCL/IniFile.hpp>

////////////////////////////////////////////////////////////////////////////////
// Global variables.

//! The application singleton instance.
TheApp g_app;

////////////////////////////////////////////////////////////////////////////////
// Constants.

//! The .ini file format version number.
const tchar* INI_FILE_VER = TXT("1.0");

////////////////////////////////////////////////////////////////////////////////
//! Constructor.

TheApp::TheApp()
	: CApp(m_appWnd, m_appCmds)
{

}

////////////////////////////////////////////////////////////////////////////////
//! Destructor.

TheApp::~TheApp()
{

}

////////////////////////////////////////////////////////////////////////////////
//! Handle application startup.

bool TheApp::OnOpen()
{
	// Set the app title.
	m_strTitle = TXT("Example");

	// Load settings.
	loadConfig();
	
	// Load the toolbar bitmap.
	m_rCmdControl.CmdBitmap().LoadRsc(IDR_APPTOOLBAR);

	// Create the main window.
	if (!m_appWnd.Create())
		return false;

	// Show it.
	m_appWnd.Show(m_iCmdShow);

	// Update UI.
	m_appCmds.UpdateUI();

	return true;
}

////////////////////////////////////////////////////////////////////////////////
//! Handle application shutdown.

bool TheApp::OnClose()
{
	// Save settings.
	saveConfig();

	return true;
}

////////////////////////////////////////////////////////////////////////////////
//! Load the application settings.

void TheApp::loadConfig()
{
	CIniFile iniFile;

	// Read the file version.
	CString version = iniFile.ReadString(TXT("Version"), TXT("Version"), INI_FILE_VER);
}

////////////////////////////////////////////////////////////////////////////////
//! Save the application settings.

void TheApp::saveConfig()
{
	CIniFile iniFile;

	// Write the file version.
	iniFile.WriteString(TXT("Version"), TXT("Version"), INI_FILE_VER);
}
