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
		TBCTL(&m_new,	ID_FILE_NEW)
		TBCTL(&m_open,	ID_FILE_OPEN)
		TBCTL(&m_save,	ID_FILE_SAVE)
		TBGAP()
		TBCTL(&m_help,	ID_HELP_ABOUT)
	END_TOOLBAR
}

////////////////////////////////////////////////////////////////////////////////
//! Destructor.

AppToolbar::~AppToolbar()
{
}
