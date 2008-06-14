////////////////////////////////////////////////////////////////////////////////
//! \file   AboutDlg.cpp
//! \brief  The AboutDlg class definition.
//! \author Chris Oldwood

#include "Common.hpp"
#include "AboutDlg.hpp"
#include "TheApp.hpp"
#include <WCL/Path.hpp>
#include <WCL/VerInfoReader.hpp>

////////////////////////////////////////////////////////////////////////////////
//! Constructor.

AboutDlg::AboutDlg()
	: CDialog(IDD_ABOUT)
{
	DEFINE_CTRL_TABLE
		CTRL(IDC_VERSION,	&m_txtVersion)
		CTRL(IDC_COPYRIGHT,	&m_txtCopyright)
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
	// Extract details from the resources.
	tstring strFileName  = CPath::Application();
	tstring strVersion   = WCL::VerInfoReader::GetStringValue(strFileName, WCL::VerInfoReader::PRODUCT_VERSION);
	tstring strCopyright = WCL::VerInfoReader::GetStringValue(strFileName, WCL::VerInfoReader::LEGAL_COPYRIGHT);

#ifdef _DEBUG
	strVersion += TXT(" [Debug]");
#endif

	// Update UI.
	m_txtVersion.Text(strVersion.c_str());
	m_txtCopyright.Text(strCopyright.c_str());
}
