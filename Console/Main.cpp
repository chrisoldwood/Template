////////////////////////////////////////////////////////////////////////////////
//! \file   Main.cpp
//! \brief  The console application entry point.
//! \author Chris Oldwood

#include "Common.hpp"
#include <tchar.h>
#include "TheApp.hpp"

//! The application.
static TheApp g_oApp;

////////////////////////////////////////////////////////////////////////////////
//! The process entry point.

int _tmain(int nArgc, tchar* apszArgv[])
{
	return g_oApp.Main(nArgc, apszArgv);
}
