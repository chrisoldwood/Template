////////////////////////////////////////////////////////////////////////////////
//! \file   TheApp.hpp
//! \brief  The TheApp class declaration.
//! \author Chris Oldwood

// Check for previous inclusion
#ifndef THEAPP_HPP
#define THEAPP_HPP

#if _MSC_VER > 1000
#pragma once
#endif

#include <WCL/ConsoleApp.hpp>

////////////////////////////////////////////////////////////////////////////////
//! The application.

class TheApp : public WCL::ConsoleApp
{
public:
	//! Default constructor.
	TheApp();

	//! Destructor.
	virtual ~TheApp();
	
protected:
	//
	// ConsoleApp methods.
	//

	//! Run the application.
	virtual int run(int argc, tchar* argv[], tistream& in, tostream& out, tostream& err);

	//! Display the program options syntax.
	virtual void showUsage(tostream& out);

private:
	//
	// Members.
	//
	Core::CmdLineParser m_parser;		//!< The command line parser.

	//
	// Internal methods.
	//

	//! Display the program version.
	void showVersion(tostream& out);
};

#endif // THEAPP_HPP
