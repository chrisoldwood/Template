////////////////////////////////////////////////////////////////////////////////
//! \file   AppCmds.hpp
//! \brief  The AppCmds class declaration.
//! \author Chris Oldwood

// Check for previous inclusion
#ifndef APP_APPCMDS_HPP
#define APP_APPCMDS_HPP

#if _MSC_VER > 1000
#pragma once
#endif

#include <WCL/SDICmds.hpp>

// Forward declarations.
class AppWnd;

////////////////////////////////////////////////////////////////////////////////
//! The application command controller.

class AppCmds : public CSDICmds
{
public:
	//! Constructor.
	AppCmds(AppWnd& appWnd);

	//! Destructor.
	virtual ~AppCmds();

	//
	// Commands.
	//

	//! Create a new document.
	void onFileNew();

	//! Open an existing document.
	void onFileOpen();

	//! Save the current document.
	void onFileSave();

	//! Save the current document with another filename.
	void onFileSaveAs();

	//! Close the current document.
	void onFileClose();

	//! Open one of the previous documents.
	void onFileOpenMRU(uint cmd);

	//! Close the application.
	void onFileExit();

	//! Show the about dialog.
	void onHelpAbout();

	//
	// UI handlers.
	//

	//! Update the command UI.
	void onUIFileSave();

	//! Update the command UI.
	void onUIFileSaveAs();

	//! Update the command UI.
	void onUIFileClose();

	//! Update the command UI.
	void onUIFileOpenMRU();
};

#endif // APP_APPCMDS_HPP
