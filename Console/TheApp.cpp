////////////////////////////////////////////////////////////////////////////////
//! \file   TheApp.cpp
//! \brief  The TheApp class definition.
//! \author Chris Oldwood

#include "Common.hpp"
#include "TheApp.hpp"
#include <Core/tiostream.hpp>
#include <WCL/Path.hpp>
#include <WCL/VerInfoReader.hpp>

////////////////////////////////////////////////////////////////////////////////
// Local variables.

static tstring s_strAppName(TXT("Application"));

////////////////////////////////////////////////////////////////////////////////
// The table of command line switches.

enum
{
	USAGE	= 0,	//!< Show the program options syntax.
	VERSION	= 1,	//!< Show the program version and copyright.
};

static Core::CmdLineSwitch s_aoSwitches[] = 
{
	{ USAGE,	TXT("?"),	NULL,			Core::CmdLineSwitch::ONCE,	Core::CmdLineSwitch::NONE,	NULL,	TXT("Display the program options syntax")	},
	{ VERSION,	TXT("v"),	TXT("version"),	Core::CmdLineSwitch::ONCE,	Core::CmdLineSwitch::NONE,	NULL,	TXT("Display the program version")			},
};
static size_t s_nCount = ARRAY_SIZE(s_aoSwitches);

////////////////////////////////////////////////////////////////////////////////
//! Default constructor.

TheApp::TheApp()
	: m_oParser(s_aoSwitches, s_aoSwitches+s_nCount)
{
}

////////////////////////////////////////////////////////////////////////////////
//! Destructor.

TheApp::~TheApp()
{
}

////////////////////////////////////////////////////////////////////////////////
//! Run the application.

int TheApp::Run(int nArgc, tchar* apszArgv[])
{
	m_oParser.Parse(nArgc, apszArgv, Core::CmdLineParser::ALLOW_UNIX_FORMAT);

	// Request for help?
	if (m_oParser.IsSwitchSet(USAGE))
	{
		ShowUsage();
		return EXIT_SUCCESS;
	}
	// Request for version?
	else if (m_oParser.IsSwitchSet(VERSION))
	{
		ShowVersion();
		return EXIT_SUCCESS;
	}

	return EXIT_SUCCESS;
}

////////////////////////////////////////////////////////////////////////////////
//! Display the program options syntax.

void TheApp::ShowUsage()
{
	tcout << std::endl;
	tcout << TXT("USAGE: Application [options] ...") << std::endl;
	tcout << std::endl;

	tcout << m_oParser.FormatSwitches(Core::CmdLineParser::UNIX);
}

////////////////////////////////////////////////////////////////////////////////
//! Display the program version.

void TheApp::ShowVersion()
{
	// Extract details from the resources.
	tstring strFileName  = CPath::Application();
	tstring strVersion   = WCL::VerInfoReader::GetStringValue(strFileName, WCL::VerInfoReader::PRODUCT_VERSION);
	tstring strCopyright = WCL::VerInfoReader::GetStringValue(strFileName, WCL::VerInfoReader::LEGAL_COPYRIGHT);

#ifdef _DEBUG
	strVersion += TXT(" [Debug]");
#endif

	// Display version etc.
	tcout << std::endl;
	tcout << s_strAppName << TXT(" v") << strVersion << std::endl;
	tcout << strCopyright << std::endl;
}
