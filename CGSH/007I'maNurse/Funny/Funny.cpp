#include "stdafx.h"
#include "windows.h"
#include "tchar.h"
#include "stdlib.h"
#include "Urlmon.h"

//link to urlmon.lib
#pragma comment(lib, "urlmon.lib")

#define DEF_URL (L"http://www.naver.com/index.html")
#define DEF_FILE_NAME (L"index.html")

//handle of module
HMODULE g_hMod = NULL;

//Thread procedure
DWORD WINAPI ThreadProc(LPVOID lParam) {
	TCHAR szPath[_MAX_PATH] = {0};

	if (!GetModuleFileName(g_hMod, szPath, MAX_PATH))
		return FALSE;
	TCHAR *p = _tcsrchr(szPath, '\\');
	if (!p)
		return FALSE;

	_tcscpy_s(p + 1, _MAX_PATH, DEF_FILE_NAME);

	URLDownloadToFile(NULL, DEF_URL, szPath, 0, NULL);

	return 0;
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
	HANDLE hThread = NULL;
	g_hMod = (HMODULE)hinstDLL;

	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		hThread = CreateThread(NULL, 0, ThreadProc, NULL, 0, NULL);
		CloseHandle(hThread);
		break;
	}

	return TRUE;
}