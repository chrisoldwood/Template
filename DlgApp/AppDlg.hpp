////////////////////////////////////////////////////////////////////////////////
//! \file   AppDlg.hpp
//! \brief  The AppDlg class declaration.
//! \author Chris Oldwood

// Check for previous inclusion
#ifndef APP_APPDLG_HPP
#define APP_APPDLG_HPP

#if _MSC_VER > 1000
#pragma once
#endif

#include <WCL/Maindlg.hpp>

////////////////////////////////////////////////////////////////////////////////
//! The application main dialog. This is the dialog that sits in the centre of
//! application window.

class AppDlg : public CMainDlg
{
public:
	//! Constructor.
	AppDlg();

	//! Destructor.
	virtual ~AppDlg();
	
private:
	//
	// Message processors.
	//

	//! Handle dialog creation.
	virtual void OnInitDialog();
};

#endif // APP_APPDLG_HPP
