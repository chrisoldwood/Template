////////////////////////////////////////////////////////////////////////////////
//! \file   TheApp.cpp
//! \brief  The TheApp class definition.
//! \author Chris Oldwood

#include "Common.hpp"
#include "TheApp.hpp"
#include "TheDoc.hpp"
#include "TheView.hpp"
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

//! The maximum size of the MRU list.
const int MRU_LIST_SIZE = ID_FILE_MRU_9-ID_FILE_MRU_1+1;

////////////////////////////////////////////////////////////////////////////////
//! Constructor.

TheApp::TheApp()
	: CSDIApp(m_appWnd, m_appCmds, MRU_LIST_SIZE)
	, m_appWnd(m_MainThread, m_appCmds)
	, m_appCmds(m_appWnd)
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
	if (!loadConfig())
		return false;
	
	// Create the main window.
	if (!m_appWnd.Open(m_iCmdShow))
		return false;

	// Update UI.
	m_appCmds.InitialiseUI();

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
		FatalMsg(TXT("Failed to save the application configuration:-\n\n%s"), e.twhat());
		return false;
	}

	return true;
}

////////////////////////////////////////////////////////////////////////////////
//! Create a document object.

CSDIDoc* TheApp::CreateDoc() const
{
	return new TheDoc;
}

////////////////////////////////////////////////////////////////////////////////
//! Create a view for the document.

CView* TheApp::CreateView(CDoc& doc) const
{
	return new TheView(static_cast<TheDoc&>(doc));
}

////////////////////////////////////////////////////////////////////////////////
//! Get the list of supported file extendsions.

const tchar* TheApp::FileExts() const
{
	static tchar s_exts[] = {	TXT("Text Files (*.txt)\0*.txt\0")
								TXT("All Files (*.*)\0*.*\0")
								TXT("\0\0")							};

	return s_exts;
}

////////////////////////////////////////////////////////////////////////////////
//! Get the default file extension.

const tchar* TheApp::DefFileExt() const
{
	static tchar s_defExt[] = { TXT("txt") };

	return s_defExt;
}

////////////////////////////////////////////////////////////////////////////////
//! Load the application settings.

bool TheApp::loadConfig()
{
	try
	{
		WCL::AppConfig appConfig(PUBLISHER, APPLICATION);

		// Read the config data version.
		tstring version = appConfig.readString(appConfig.DEFAULT_SECTION, TXT("Version"), CONFIG_VERSION);

		if (version != CONFIG_VERSION)
			throw Core::ConfigurationException(Core::fmt(TXT("The configuration data is incompatible - '%s'"), version.c_str()));

		// Read the MRU list.
		m_MRUList.Read(appConfig);
	}
	catch (const Core::Exception& e)
	{
		FatalMsg(TXT("Failed to configure the application:-\n\n%s"), e.twhat());
		return false;
	}

	return true;
}

////////////////////////////////////////////////////////////////////////////////
//! Save the application settings.

void TheApp::saveConfig()
{
	WCL::AppConfig appConfig(PUBLISHER, APPLICATION);

	// Write the config data version.
	appConfig.writeString(appConfig.DEFAULT_SECTION, TXT("Version"), CONFIG_VERSION);

	// Write the MRU list.
	m_MRUList.Write(appConfig);
}
