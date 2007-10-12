////////////////////////////////////////////////////////////////////////////////
//! \file   TheView.cpp
//! \brief  The TheView class definition.
//! \author Chris Oldwood

#include "Common.hpp"
#include "TheView.hpp"
#include "TheDoc.hpp"

////////////////////////////////////////////////////////////////////////////////
//! Constructor.

TheView::TheView(TheDoc& rDoc)
	: CView(rDoc)
{
}

////////////////////////////////////////////////////////////////////////////////
//! Destructor.

TheView::~TheView()
{
}

////////////////////////////////////////////////////////////////////////////////
//! Handle window creation.

void TheView::OnCreate(const CRect& /*rcClient*/)
{
}

////////////////////////////////////////////////////////////////////////////////
//! Handle window resizing.

void TheView::OnResize(int /*iFlag*/, const CSize& /*rNewSize*/)
{
}