////////////////////////////////////////////////////////////////////////////////
//! \file   TheApp.hpp
//! \brief  The TheApp class declaration.
//! \author Chris Oldwood

// Check for previous inclusion
#ifndef APP_THEAPP_HPP
#define APP_THEAPP_HPP

#if _MSC_VER > 1000
#pragma once
#endif

#include <WCL/App.hpp>
#include "AppWnd.hpp"
#include "AppCmds.hpp"

////////////////////////////////////////////////////////////////////////////////
//! The application singleton.

class TheApp : public CApp
{
public:
	//! Constructor.
	TheApp();

	//! Destructor.
	virtual ~TheApp();

	//
	// Public members.
	//
	AppWnd		m_oAppWnd;		//!< The main window.
	AppCmds		m_oAppCmds;		//!< The command handler.

	//
	// Public Constants.
	//

	//! The application version string.
	static const char* VERSION;

private:
	//
	// Template methods.
	//

	//! Handle application startup.
	virtual	bool OnOpen();

	//! Handle application shutdown.
	virtual	bool OnClose();

	//
	// Internal methods.
	//

	//! Load the application settings.
	void LoadConfig();

	//! Save the application settings.
	void SaveConfig();

	//
	// Constants.
	//

	//! The .ini file format version number.
	static const char* INI_FILE_VER;
};

//! The application singleton instance.
extern TheApp App;

#endif // APP_THEAPP_HPP
