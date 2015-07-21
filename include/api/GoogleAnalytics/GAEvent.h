/*
	v=1             // Version.
	&tid=UA-XXXX-Y  // Tracking ID / Web property / Property ID.
	&cid=555        // Anonymous Client ID.
	&t=event        // Event hit type
	&ec=video       // Event Category. Required.
	&ea=play        // Event Action. Required.
	&el=holiday     // Event label.
	&ev=300         // Event value.
*/

#pragma once
#include "GAType.h"

class CGAEvent
{
public:
	CGAEvent(void);
	~CGAEvent(void);
	// Hit Type
	CString t;
	// Event Category
	CString ec;
	// Event Action
	CString ea;
	// Event Label
	CString el;
	// Event Value
	int ev;
};

