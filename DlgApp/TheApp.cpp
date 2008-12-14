////////////////////////////////////////////////////////////////////////////////
//! \file   TheApp.cpp
//! \brief  The TheApp class definition.
//! \author Chris Oldwood

#include "Common.hpp"
#include "TheApp.hpp"
#include <WCL/AppConfig.hpp>
#include <Core/ConfigurationException.hpp>

////////////////////////////////////////////////////////////////////////////////
// Global variables.

//! The application singleton instance.
TheApp g_app;

////////////////////////////////////////////////////////////////////////////////
// Constants.

//! The configuration data publisher name.
const tchar* PUBLISHER = TXT("Chris Oldwood");
//! The configuration data application name.
const tchar* APPLICATION = TXT("The Application");
//! The configuration data format version.
const tchar* CONFIG_VERSION = TXT("1.0");

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

	try
	{
		// Load settings.
		loadConfig();
	}
	catch (const Core::Exception& e)
	{
		FatalMsg(TXT("Failed to configure the application:-\n\n%s"), e.What());
		return false;
	}
	
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
	try
	{
		// Save settings.
		saveConfig();
	}
	catch (const Core::Exception& e)
	{
		FatalMsg(TXT("Failed to save the application configuration:-\n\n%s"), e.What());
		return false;
	}

	return true;
}

////////////////////////////////////////////////////////////////////////////////
//! Load the application settings.

void TheApp::loadConfig()
{
	WCL::AppConfig appConfig(PUBLISHER, APPLICATION);

	// Read the config data version.
	tstring version = appConfig.readString(appConfig.DEFAULT_SECTION, TXT("Version"), CONFIG_VERSION);

	if (version != CONFIG_VERSION)
		throw Core::ConfigurationException(Core::Fmt(TXT("The configuration data is incompatible - '%s'"), version.c_str()));
}

////////////////////////////////////////////////////////////////////////////////
//! Save the application settings.

void TheApp::saveConfig()
{
	WCL::AppConfig appConfig(PUBLISHER, APPLICATION);

	// Write the config data version.
	appConfig.writeString(appConfig.DEFAULT_SECTION, TXT("Version"), CONFIG_VERSION);
}
