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
TheApp App;

////////////////////////////////////////////////////////////////////////////////
// Constants.

#ifdef _DEBUG
//! The application version string.
const tchar* TheApp::VERSION = TXT("v1.0 [Debug]");
#else
//! The application version string.
const tchar* TheApp::VERSION = TXT("v1.0");
#endif

//! The .ini file format version number.
const tchar* TheApp::INI_FILE_VER = TXT("1.0");

////////////////////////////////////////////////////////////////////////////////
//! Constructor.

TheApp::TheApp()
	: CApp(m_oAppWnd, m_oAppCmds)
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
	LoadConfig();
	
	// Load the toolbar bitmap.
	m_rCmdControl.CmdBitmap().LoadRsc(IDR_APPTOOLBAR);

	// Create the main window.
	if (!m_oAppWnd.Create())
		return false;

	// Show it.
	m_oAppWnd.Show(m_iCmdShow);

	// Update UI.
	m_oAppCmds.UpdateUI();

	return true;
}

////////////////////////////////////////////////////////////////////////////////
//! Handle application shutdown.

bool TheApp::OnClose()
{
	// Save settings.
	SaveConfig();

	return true;
}

////////////////////////////////////////////////////////////////////////////////
//! Load the application settings.

void TheApp::LoadConfig()
{
	CIniFile oIniFile;

	// Read the file version.
	CString strVer = oIniFile.ReadString(TXT("Version"), TXT("Version"), INI_FILE_VER);
}

////////////////////////////////////////////////////////////////////////////////
//! Save the application settings.

void TheApp::SaveConfig()
{
	CIniFile oIniFile;

	// Write the file version.
	oIniFile.WriteString(TXT("Version"), TXT("Version"), INI_FILE_VER);
}
