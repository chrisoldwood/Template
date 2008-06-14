////////////////////////////////////////////////////////////////////////////////
//! \file   AboutDlg.hpp
//! \brief  The AboutDlg class declaration.
//! \author Chris Oldwood

// Check for previous inclusion
#ifndef APP_ABOUTDLG_HPP
#define APP_ABOUTDLG_HPP

#if _MSC_VER > 1000
#pragma once
#endif

#include <WCL/CommonUI.hpp>

////////////////////////////////////////////////////////////////////////////////
//! The dialog used to display the version number and copyright message.

class AboutDlg : public CDialog
{
public:
	//! Constructor.
	AboutDlg();

	//! Destructor.
	virtual ~AboutDlg();
	
protected:
	//
	// Controls.
	//
	CLabel		m_txtVersion;		//!< The version label.
	CLabel		m_txtCopyright;		//!< The copyright label.
	CURLLabel	m_txtEmail;			//!< The email address label.
	CURLLabel	m_txtWebSite;		//!< The website label.
	
	//
	// Message processors.
	//

	//! Handle dialog creation.
	virtual void OnInitDialog();
};

#endif // APP_ABOUTDLG_HPP
