
# Install the SDK manually

## 1. Download files
Include api folder, cpprestsdk folder, gasdk folder and jsoncpp folder.


## 2. Add all files into project
Project > Add > Existing item...

## 3. Edit the project property pages
- In C/C++ > General page, add api, cpprestsdk, and gasdk path into "Additional Include Directories".

- In C/C++ > Code Generation page, choose "Multi-threaded Debug (/MTd)" runtime library.

- In C/C++ > Preprocessor page, add _NO_ASYNCRTIMP into "Preprocessor Definitions".
GoogleAnalytics SDK uses [C++ REST SDK](https://casablanca.codeplex.com/) to connect to GA servers, you need to turn off exporting functions from the C++ Rest SDK dll, which is why it is applicable for static linking.

- In Linker > Input page, add cpprest110_2_0.lib and winhttp.lib into "Additional Dependencies".


## 4. Include header files and declare a GoogleAnalytics object 
Add the statements into your code:

    #include "GoogleAnalytics.h"
    GoogleAnalytics googleAnalytics;

## 5.  Define your Tracking ID
Define your Tracking ID in GAType.h.   

	// Tracking ID
	static const CString GA_Tid = _T("UA-XXXXXX-X");

To find yours, select your app in the ga dashboard, and click Admin. Under Property, click Property Settings.

## 6.  Set user client ID
Using *extern* to specify linkage of the clientID variable.

	extern CString GA_Cid;

Then, you can set the client ID into GA_Cid variable.

## 7. Create and define GAEvent/GAScreenView variables
GAEvent and GAScreenView are the data structures for event and screenview types. And the member variables of each structure are parameters in Measurement Protocol. 

	GAEvent
		CString ec; //Event Category. Required.
		CString ea; //Event Action. Required.
		CString el; //Event label.
		int ev; //Event value.
	GAScreenView 
		CString cd; //Screen name. Required.
		CString an; //Application name. Required.
		CString av; //Application version.
		CString aid; //Application identifier.
		CString aiid; //Application installer identifier.

## 8. Set other parameters
Except above parameters, you can use SetOtherParameters() function to set any other parameters. If there are more than one parameter you want to set, please use "&" to connect them.

	CString str = _T("ua=(Windows NT 6.2)&ul=en-us");
	SetOtherParameters(str);

## 9. Send the data to Google Analytics
Send() is an overloaded function. No matter which hit type you want to send, you can call Send() to send to GA server.

	void Send(CGAEvent &gaEvent);
	void Send(CGAScreenView &gaScreenView);

## 10. Run your project
