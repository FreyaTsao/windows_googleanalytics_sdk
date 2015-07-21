/*
這裡放 OS 版本偵測函式
*/

#pragma once

class COSDetector
{
public:
	typedef enum OS_Type {
		OS_Unknown, OS_Win32s, OS_Windows95, OS_Windows98, OS_WindowsMe,
		OS_WindowsNT, OS_Windows2000, OS_WindowsXP, OS_WindowsServer2003, OS_WindowsVista,
		OS_Windows7, OS_Windows8, OS_Windows8_1, OS_Windows10
	} OS_Classify;

	static OS_Type GetOS();
	static CString GetOSVerString();	// 取得 OS 的字串
private:
	COSDetector() {};		// static class, private constructor
	~COSDetector() {};	// static class, private destructor
};