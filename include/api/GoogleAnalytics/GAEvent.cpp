#include "stdafx.h"
#include "GAEvent.h"

CGAEvent::CGAEvent(void)
{
	t = GA_Type_Event;
	ec = _T("");
	ea = _T("");
	el = _T("");
	ev = 0;
}

CGAEvent::~CGAEvent(void)
{
}
