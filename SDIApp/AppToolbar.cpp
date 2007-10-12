////////////////////////////////////////////////////////////////////////////////
//! \file   AppToolbar.cpp
//! \brief  The AppToolbar class definition.
//! \author Chris Oldwood

#include "Common.hpp"
#include "AppToolbar.hpp"

////////////////////////////////////////////////////////////////////////////////
//! Constructor.

AppToolbar::AppToolbar()
{
	// Define the toolbar.
	DEFINE_TOOLBAR
		TBCTL(&m_btnNew,	ID_FILE_NEW)
		TBCTL(&m_btnOpen,	ID_FILE_OPEN)
		TBCTL(&m_btnSave,	ID_FILE_SAVE)
		TBGAP()
		TBCTL(&m_btnHelp,	ID_HELP_ABOUT)
	END_TOOLBAR
}

////////////////////////////////////////////////////////////////////////////////
//! Destructor.

AppToolbar::~AppToolbar()
{
}
