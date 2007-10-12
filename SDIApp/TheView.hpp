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
	TheView(TheDoc& rDoc);

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
	virtual void OnCreate(const CRect& rcClient);

	//! Handle window resizing.
	virtual void OnResize(int iFlag, const CSize& rNewSize);
};

#endif // APP_THEVIEW_HPP
