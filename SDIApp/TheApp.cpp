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
TheApp App;

////////////////////////////////////////////////////////////////////////////////
// Constants.

#ifdef _DEBUG
//! The application version string.
const char* TheApp::VERSION      = "v1.0 [Debug]";
#else
//! The application version string.
const char* TheApp::VERSION      = "v1.0";
#endif

//! The .ini file format version number.
const char* TheApp::INI_FILE_VER = "1.0";

const int MRU_LIST_SIZE = ID_FILE_MRU_4-ID_FILE_MRU_1+1;

////////////////////////////////////////////////////////////////////////////////
//! Constructor.

TheApp::TheApp()
	: CSDIApp(m_oAppWnd, m_oAppCmds, MRU_LIST_SIZE)
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
	m_strTitle = "Example";

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
//! Create a document object.

CSDIDoc* TheApp::CreateDoc() const
{
	return new TheDoc;
}

////////////////////////////////////////////////////////////////////////////////
//! Create a view for the document.

CView* TheApp::CreateView(CDoc& rDoc) const
{
	return new TheView(static_cast<TheDoc&>(rDoc));
}

////////////////////////////////////////////////////////////////////////////////
//! Get the list of supported file extendsions.

const char* TheApp::FileExts() const
{
	static char szExts[] = {	"Text Files (*.txt)\0*.txt\0"
								"All Files (*.*)\0*.*\0"
								"\0\0"							};

	return szExts;
}

////////////////////////////////////////////////////////////////////////////////
//! Get the default file extension.

const char* TheApp::DefFileExt() const
{
	static char szDefExt[] = { "txt" };

	return szDefExt;
}

////////////////////////////////////////////////////////////////////////////////
//! Load the application settings.

void TheApp::LoadConfig()
{
	CIniFile oIniFile;

	// Read the file version.
	CString strVer = oIniFile.ReadString("Version", "Version", INI_FILE_VER);
}

////////////////////////////////////////////////////////////////////////////////
//! Save the application settings.

void TheApp::SaveConfig()
{
	CIniFile oIniFile;

	// Write the file version.
	oIniFile.WriteString("Version", "Version", INI_FILE_VER);
}
