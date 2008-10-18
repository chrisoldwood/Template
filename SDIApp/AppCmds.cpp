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
		CMD_ENTRY(ID_FILE_NEW,					&AppCmds::onFileNew,		NULL,						 0)
		CMD_ENTRY(ID_FILE_OPEN,					&AppCmds::onFileOpen,		NULL,						 1)
		CMD_ENTRY(ID_FILE_SAVE,					&AppCmds::onFileSave,		&AppCmds::onUIFileSave,		 2)
		CMD_ENTRY(ID_FILE_SAVEAS,				&AppCmds::onFileSaveAs,		&AppCmds::onUIFileSaveAs,	-1)
		CMD_ENTRY(ID_FILE_CLOSE,				&AppCmds::onFileClose,		&AppCmds::onUIFileClose,	 1)
		CMD_RANGE(ID_MRU_FIRST,	ID_MRU_LAST,	&AppCmds::onFileOpenMRU,	&AppCmds::onUIFileOpenMRU,	-1)
		CMD_ENTRY(ID_FILE_EXIT,					&AppCmds::onFileExit,		NULL,						-1)
		// Help menu.
		CMD_ENTRY(ID_HELP_ABOUT,				&AppCmds::onHelpAbout,		NULL,						10)
	END_CMD_TABLE
}

////////////////////////////////////////////////////////////////////////////////
//! Destructor.

AppCmds::~AppCmds()
{
}

////////////////////////////////////////////////////////////////////////////////
//! Create a new document.

void AppCmds::onFileNew()
{
	NewFile();
}

////////////////////////////////////////////////////////////////////////////////
//! Open an existing document.

void AppCmds::onFileOpen()
{
	OpenFile();
}

////////////////////////////////////////////////////////////////////////////////
//! Save the current document.

void AppCmds::onFileSave()
{
	SaveFile();
}

////////////////////////////////////////////////////////////////////////////////
//! Save the current document with another filename.

void AppCmds::onFileSaveAs()
{
	SaveFileAs();
}

////////////////////////////////////////////////////////////////////////////////
//! Close the current document.

void AppCmds::onFileClose()
{
	CloseFile();
}

////////////////////////////////////////////////////////////////////////////////
//! Open one of the previous documents.

void AppCmds::onFileOpenMRU(uint cmd)
{
	OpenMRUFile(cmd - ID_MRU_FIRST);
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

////////////////////////////////////////////////////////////////////////////////
//! Update the command UI.

void AppCmds::onUIFileSave()
{
	bool isDocOpen  = (g_app.m_pDoc != NULL);
	bool isModified = (isDocOpen && g_app.m_pDoc->Modified());

	g_app.m_appWnd.m_menu.EnableCmd(ID_FILE_SAVE, (isDocOpen && isModified));
	g_app.m_appWnd.m_toolbar.m_save.Enable(isDocOpen && isModified);
}

////////////////////////////////////////////////////////////////////////////////
//! Update the command UI.

void AppCmds::onUIFileSaveAs()
{
	bool isDocOpen = (g_app.m_pDoc != NULL);

	g_app.m_appWnd.m_menu.EnableCmd(ID_FILE_SAVEAS, isDocOpen);
}

////////////////////////////////////////////////////////////////////////////////
//! Update the command UI.

void AppCmds::onUIFileClose()
{
	bool isDocOpen = (g_app.m_pDoc != NULL);

	g_app.m_appWnd.m_menu.EnableCmd(ID_FILE_CLOSE, isDocOpen);
}

////////////////////////////////////////////////////////////////////////////////
//! Update the command UI.

void AppCmds::onUIFileOpenMRU()
{
	g_app.m_MRUList.UpdateMenu(g_app.m_appWnd.m_menu, ID_MRU_FIRST);
}
