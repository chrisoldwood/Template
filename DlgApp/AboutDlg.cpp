////////////////////////////////////////////////////////////////////////////////
//! \file   AboutDlg.cpp
//! \brief  The AboutDlg class definition.
//! \author Chris Oldwood

#include "Common.hpp"
#include "AboutDlg.hpp"
#include "TheApp.hpp"

////////////////////////////////////////////////////////////////////////////////
//! Constructor.

AboutDlg::AboutDlg()
	: CDialog(IDD_ABOUT)
{
	DEFINE_CTRL_TABLE
		CTRL(IDC_VERSION,	&m_txtVersion)
		CTRL(IDC_EMAIL,		&m_txtEmail  )
		CTRL(IDC_WEBSITE,	&m_txtWebSite)
	END_CTRL_TABLE

	// Set the URL label protocols.
	m_txtEmail.Protocol(TXT("mailto:"));
	m_txtWebSite.Protocol(TXT("http://"));
}

////////////////////////////////////////////////////////////////////////////////
//! Destructor.

AboutDlg::~AboutDlg()
{
}

////////////////////////////////////////////////////////////////////////////////
//! Handle dialog creation.

void AboutDlg::OnInitDialog()
{
	m_txtVersion.Text(App.VERSION);
}
