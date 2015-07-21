#include "stdafx.h"
#include "OSDetector.h"
// #include "trace32/trace32.h"		// not using trace, so comment it

// 取得 OS 資訊
COSDetector::OS_Type COSDetector::GetOS()
{
	OSVERSIONINFOEX osvi;
	BOOL bOsVersionInfoEx;

	ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);

	if (!(bOsVersionInfoEx = GetVersionEx((OSVERSIONINFO *) &osvi)))  {
		osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
		if (! GetVersionEx((OSVERSIONINFO *) &osvi)) {
			return OS_Unknown;
		}
	}

	// pac 20130523 根據 http://msdn.microsoft.com/en-us/library/ms886768.aspx
	// VER_PLATFORM_WIN32s	Specifies the Windows 3.1 OS.
	// VER_PLATFORM_WIN32_WINDOWS	Specifies the Windows 95 or Windows 98 OS.
	// VER_PLATFORM_WIN32_NT	Specifies the Windows NT OS.
	// #24847 (accepted)[KKBOX Windows] osver 改傳版號
	switch (osvi.dwPlatformId) { // Test for the Windows NT product family.
		case VER_PLATFORM_WIN32_NT: // Test for the specific product.

			// http://en.wikipedia.org/wiki/Windows_10#Version_history
			if ((6 == osvi.dwMajorVersion && 3 < osvi.dwMinorVersion) || 6 < osvi.dwMajorVersion) {
				return OS_Windows10;
			}

			if (6 == osvi.dwMajorVersion && 3 == osvi.dwMinorVersion) {
				return OS_Windows8_1;
			}

			if (6 == osvi.dwMajorVersion && 2 == osvi.dwMinorVersion) {
				return OS_Windows8;
			}

			// 20090226 Vincent: 參考 Windows Application Quality Cookbook，得知 Windows7 是 Version 6.1
			if (6 == osvi.dwMajorVersion && 1 == osvi.dwMinorVersion) {
				return OS_Windows7;
			}

			if (6 == osvi.dwMajorVersion && 0 == osvi.dwMinorVersion) {
				return OS_WindowsVista;
			}

			if (5 == osvi.dwMajorVersion && 2 == osvi.dwMinorVersion) {
				return OS_WindowsServer2003;
			}

			if (5 == osvi.dwMajorVersion && 1 == osvi.dwMinorVersion) {
				return OS_WindowsXP;
			}

			if (5 == osvi.dwMajorVersion && 0 == osvi.dwMinorVersion) {
				return OS_Windows2000;
			}

			if (4 >= osvi.dwMajorVersion) {
				return OS_WindowsNT;
			}
			break;

		case VER_PLATFORM_WIN32_WINDOWS: // Test for the Windows Me/98/95.
			if (4 == osvi.dwMajorVersion && 0 == osvi.dwMinorVersion) {
				return OS_Windows95;
			}

			if (4 == osvi.dwMajorVersion && 10 == osvi.dwMinorVersion) {
				return OS_Windows98;
			}

			if (4 == osvi.dwMajorVersion && 90 == osvi.dwMinorVersion) {
				return OS_WindowsMe;
			}
			break;

		case VER_PLATFORM_WIN32s:
			return OS_Win32s;
			break;
	}

	return OS_Unknown;
}

// 取得 OS 的字串
CString COSDetector::GetOSVerString()
{
	//	CString strOS = GetOS();
	OSVERSIONINFOEX osvi;
	BOOL bOsVersionInfoEx;

	ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);

	if (!(bOsVersionInfoEx = GetVersionEx((OSVERSIONINFO *) &osvi)))  {
		osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
		if (! GetVersionEx((OSVERSIONINFO *) &osvi)) {
			//			return OS_Unknown;
			return _T("");
		}
	}
	// #24847 (accepted)[KKBOX Windows] osver 改傳版號
	CString sVersion;
	sVersion.Format(_T("%d.%d"), osvi.dwMajorVersion, osvi.dwMinorVersion);
	//int iOS = GetOS();
	//CString strResult;
	//switch (iOS) {
	//	case OS_Win32s:
	//		{
	//			strResult = _T("Win32s");
	//			break;
	//		}
	//	case OS_Windows95:
	//		{
	//			strResult = _T("Windows95");
	//			break;
	//		}
	//	case OS_Windows98:
	//		{
	//			strResult = _T("Windows98");
	//			break;
	//		}
	//	case OS_WindowsMe:
	//		{
	//			strResult = _T("WindowsMe");
	//			break;
	//		}
	//	case OS_WindowsNT:
	//		{
	//			strResult = _T("WindowsNT");
	//			break;
	//		}
	//	case OS_Windows2000:
	//		{
	//			strResult = _T("Windows2000");
	//			break;
	//		}
	//	case OS_WindowsXP:
	//		{
	//			strResult = _T("WindowsXP");
	//			break;
	//		}
	//	case OS_WindowsServer2003:
	//		{
	//			strResult = _T("WindowsServer2003");
	//			break;
	//		}
	//	case OS_WindowsVista:
	//		{
	//			strResult = _T("WindowsVista");
	//			break;
	//		}
	//	case OS_Windows7:
	//		{
	//			strResult = _T("Windows7");
	//			break;
	//		}
	//	case OS_Windows8:
	//		{
	//			strResult = _T("Windows8");
	//			break;
	//		}
	//	case OS_Unknown:
	//	default:
	//		{
	//			strResult = _T("Unknown");
	//			break;
	//		}
	//}
	//return strResult;
	return sVersion;
}

