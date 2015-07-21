/*
	v=1                        // Version.
	&tid=UA-XXXX-Y             // Tracking ID / Web property / Property ID.
	&cid=555                   // Anonymous Client ID.
	&t=screenview              // Screenview hit type.
	&an=funTimes               // App name.
	&av=4.2.0                  // App version.
	&aid=com.foo.App           // App Id.
	&aiid=com.android.vending  // App Installer Id.
	&cd=Home                   // Screen name / content description.
*/

#pragma once
#include "GAType.h"

class CGAScreenView
{
public:
	CGAScreenView(void);
	~CGAScreenView(void);

	// Hit Type
	CString t;
	// Application Name
	CString an;
	// Application Version
	CString av;
	// Application identifier
	CString aid;
	// Application installer identifier
	CString aiid;
	// Screen Name
	CString cd;
};

