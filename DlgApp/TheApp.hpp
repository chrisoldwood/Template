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
	AppWnd		m_appWnd;		//!< The main window.
	AppCmds		m_appCmds;		//!< The command handler.

private:
	//
	// CApp overriden methods.
	//

	//! Handle application startup.
	virtual	bool OnOpen();

	//! Handle application shutdown.
	virtual	bool OnClose();

	//
	// Internal methods.
	//

	//! Load the application settings.
	void loadConfig();

	//! Save the application settings.
	void saveConfig();
};

//! The application singleton instance.
extern TheApp g_app;

#endif // APP_THEAPP_HPP
