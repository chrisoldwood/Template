////////////////////////////////////////////////////////////////////////////////
//! \file   AppCmds.cpp
//! \brief  The AppCmds class definition.
//! \author Chris Oldwood

#include "Common.hpp"
#include "AppCmds.hpp"
#include "TheApp.hpp"
#include "TheDoc.hpp"
#include "AboutDlg.hpp"

//! The ID of the first MRU command.
const int ID_MRU_FIRST = ID_FILE_MRU_1;

//! The ID of the last MRU command.
const int ID_MRU_LAST = ID_FILE_MRU_4;

////////////////////////////////////////////////////////////////////////////////
//! Constructor.

AppCmds::AppCmds()
{
	// Define the command table.
	DEFINE_CMD_TABLE
		// File menu.
		CMD_ENTRY(ID_FILE_NEW,					&AppCmds::OnFileNew,		NULL,						 0)
		CMD_ENTRY(ID_FILE_OPEN,					&AppCmds::OnFileOpen,		NULL,						 1)
		CMD_ENTRY(ID_FILE_SAVE,					&AppCmds::OnFileSave,		&AppCmds::OnUIFileSave,		 2)
		CMD_ENTRY(ID_FILE_SAVEAS,				&AppCmds::OnFileSaveAs,		&AppCmds::OnUIFileSaveAs,	-1)
		CMD_ENTRY(ID_FILE_CLOSE,				&AppCmds::OnFileClose,		&AppCmds::OnUIFileClose,	 1)
		CMD_RANGE(ID_MRU_FIRST,	ID_MRU_LAST,	&AppCmds::OnFileOpenMRU,	&AppCmds::OnUIFileOpenMRU,	-1)
		CMD_ENTRY(ID_FILE_EXIT,					&AppCmds::OnFileExit,		NULL,						-1)
		// Help menu.
		CMD_ENTRY(ID_HELP_ABOUT,				&AppCmds::OnHelpAbout,		NULL,						10)
	END_CMD_TABLE
}

////////////////////////////////////////////////////////////////////////////////
//! Destructor.

AppCmds::~AppCmds()
{
}

////////////////////////////////////////////////////////////////////////////////
//! Create a new document.

void AppCmds::OnFileNew()
{
	NewFile();
}

////////////////////////////////////////////////////////////////////////////////
//! Open an existing document.

void AppCmds::OnFileOpen()
{
	OpenFile();
}

////////////////////////////////////////////////////////////////////////////////
//! Save the current document.

void AppCmds::OnFileSave()
{
	SaveFile();
}

////////////////////////////////////////////////////////////////////////////////
//! Save the current document with another filename.

void AppCmds::OnFileSaveAs()
{
	SaveFileAs();
}

////////////////////////////////////////////////////////////////////////////////
//! Close the current document.

void AppCmds::OnFileClose()
{
	CloseFile();
}

////////////////////////////////////////////////////////////////////////////////
//! Open one of the previous documents.

void AppCmds::OnFileOpenMRU(uint iCmdID)
{
	OpenMRUFile(iCmdID - ID_MRU_FIRST);
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

////////////////////////////////////////////////////////////////////////////////
//! Update the command UI.

void AppCmds::OnUIFileSave()
{
	bool bDocOpen  = (App.m_pDoc != NULL);
	bool bModified = (bDocOpen && App.m_pDoc->Modified());

	App.m_oAppWnd.m_oMenu.EnableCmd(ID_FILE_SAVE, (bDocOpen && bModified));
	App.m_oAppWnd.m_oToolbar.m_btnSave.Enable(bDocOpen && bModified);
}

////////////////////////////////////////////////////////////////////////////////
//! Update the command UI.

void AppCmds::OnUIFileSaveAs()
{
	bool bDocOpen = (App.m_pDoc != NULL);

	App.m_oAppWnd.m_oMenu.EnableCmd(ID_FILE_SAVEAS, bDocOpen);
}

////////////////////////////////////////////////////////////////////////////////
//! Update the command UI.

void AppCmds::OnUIFileClose()
{
	bool bDocOpen = (App.m_pDoc != NULL);

	App.m_oAppWnd.m_oMenu.EnableCmd(ID_FILE_CLOSE, bDocOpen);
}

////////////////////////////////////////////////////////////////////////////////
//! Update the command UI.

void AppCmds::OnUIFileOpenMRU()
{
	App.m_MRUList.UpdateMenu(App.m_oAppWnd.m_oMenu, ID_MRU_FIRST);
}
