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

//! The .ini file format version number.
const tchar* INI_FILE_VER = TXT("1.0");

//! The maximum size of the MRU list.
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

const tchar* TheApp::FileExts() const
{
	static tchar szExts[] = {	TXT("Text Files (*.txt)\0*.txt\0")
								TXT("All Files (*.*)\0*.*\0")
								TXT("\0\0")							};

	return szExts;
}

////////////////////////////////////////////////////////////////////////////////
//! Get the default file extension.

const tchar* TheApp::DefFileExt() const
{
	static tchar szDefExt[] = { TXT("txt") };

	return szDefExt;
}

////////////////////////////////////////////////////////////////////////////////
//! Load the application settings.

void TheApp::LoadConfig()
{
	CIniFile oIniFile;

	// Read the file version.
	CString strVer = oIniFile.ReadString(TXT("Version"), TXT("Version"), INI_FILE_VER);

	// Read the MRU list.
	m_MRUList.Load(oIniFile);
}

////////////////////////////////////////////////////////////////////////////////
//! Save the application settings.

void TheApp::SaveConfig()
{
	CIniFile oIniFile;

	// Write the file version.
	oIniFile.WriteString(TXT("Version"), TXT("Version"), INI_FILE_VER);

	// Save the MRU list.
	m_MRUList.Save(oIniFile);
}
