////////////////////////////////////////////////////////////////////////////////
//! \file   TheView.hpp
//! \brief  The TheView class declaration.
//! \author Chris Oldwood

// Check for previous inclusion
#ifndef APP_THEVIEW_HPP
#define APP_THEVIEW_HPP

#include <WCL/View.hpp>

// Forward declarations.
class TheDoc;

////////////////////////////////////////////////////////////////////////////////
//! The view for the document.

class TheView : public CView
{
public:
	//! Constructor.
	TheView(TheDoc& doc);

	//! Destructor.
	virtual ~TheView();
	
private:
	//
	// Members.
	//

	//
	// Message handler.
	//

	//! Handle window creation.
	virtual void OnCreate(const CRect& clientRect);

	//! Handle window resizing.
	virtual void OnResize(int flag, const CSize& newSize);
};

#endif // APP_THEVIEW_HPP
