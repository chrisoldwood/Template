/******************************************************************************
** (C) Chris Oldwood
**
** MODULE:		THEAPP.HPP
** COMPONENT:	The Application.
** DESCRIPTION:	The CTheApp class declaration.
**
*******************************************************************************
*/

// Check for previous inclusion
#ifndef THEAPP_HPP
#define THEAPP_HPP

/******************************************************************************
** 
** The application class.
**
*******************************************************************************
*/

class CTheApp : public CApp
{
public:
	//
	// Constructors/Destructor.
	//
	CTheApp();
	~CTheApp();

	//
	// Members
	//
	CAppWnd		m_AppWnd;			// Main window.
	CAppCmds	m_AppCmds;			// Command handler.

	//
	// Constants.
	//
	static const char* VERSION;

protected:
	//
	// Startup and Shutdown template methods.
	//
	virtual	bool OnOpen();
	virtual	bool OnClose();

	//
	// Preferences.
	//
	CIniFile	m_oIniFile;		// .INI FIle

	//
	// Internal methods.
	//
	void LoadConfig();
	void SaveConfig();

	//
	// Constants.
	//
	static const char* INI_FILE_VER;
};

/******************************************************************************
**
** Global variables.
**
*******************************************************************************
*/

// The application object.
extern CTheApp App;

/******************************************************************************
**
** Implementation of inline functions.
**
*******************************************************************************
*/


#endif //THEAPP_HPP
