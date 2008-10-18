////////////////////////////////////////////////////////////////////////////////
//! \file   TheApp.cpp
//! \brief  The TheApp class definition.
//! \author Chris Oldwood

#include "Common.hpp"
#include "TheApp.hpp"
#include "TheDoc.hpp"
#include "TheView.hpp"
#include <WCL/IniFile.hpp>

////////////////////////////////////////////////////////////////////////////////
// Global variables.

//! The application singleton instance.
TheApp g_app;

////////////////////////////////////////////////////////////////////////////////
// Constants.

//! The .ini file format version number.
const tchar* INI_FILE_VER = TXT("1.0");

//! The maximum size of the MRU list.
const int MRU_LIST_SIZE = ID_FILE_MRU_4-ID_FILE_MRU_1+1;

////////////////////////////////////////////////////////////////////////////////
//! Constructor.

TheApp::TheApp()
	: CSDIApp(m_appWnd, m_appCmds, MRU_LIST_SIZE)
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

void TheApp::loadConfig()
{
	CIniFile iniFile;

	// Read the file version.
	CString version = iniFile.ReadString(TXT("Version"), TXT("Version"), INI_FILE_VER);

	// Read the MRU list.
	m_MRUList.Load(iniFile);
}

////////////////////////////////////////////////////////////////////////////////
//! Save the application settings.

void TheApp::saveConfig()
{
	CIniFile iniFile;

	// Write the file version.
	iniFile.WriteString(TXT("Version"), TXT("Version"), INI_FILE_VER);

	// Save the MRU list.
	m_MRUList.Save(iniFile);
}
