////////////////////////////////////////////////////////////////////////////////
//! \file   TheDoc.hpp
//! \brief  The TheDoc class declaration.
//! \author Chris Oldwood

// Check for previous inclusion
#ifndef APP_THEDOC_HPP
#define APP_THEDOC_HPP

#if _MSC_VER > 1000
#pragma once
#endif

#include <WCL/SDIDoc.hpp>

////////////////////////////////////////////////////////////////////////////////
//! The document.

class TheDoc : public CSDIDoc
{
public:
	//! Constructor.
	TheDoc();

	//! Destructor.
	virtual ~TheDoc();

	//
	// Properties.
	//

	//! Checks if the document has been modified.
	virtual bool Modified() const;

	//
	// Methods.
	//

	//! Load the document from a stream.
	virtual void Read (WCL::IInputStream& rStream);

	//! Save the document to a stream.
	virtual void Write(WCL::IOutputStream& rStream);

private:
	//
	// Members.
	//
};

#endif // APP_THEDOC_HPP
