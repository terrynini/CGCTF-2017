// 006KeyboardHook.cpp : 定義 DLL 應用程式的匯出函式。
//
#include "stdafx.h"
#include "stdio.h"
#include "windows.h"

HINSTANCE g_hInstance = NULL;
HHOOK g_hHook = NULL;
HWND g_hWnd = NULL;

//(handle of dll, why the DLLMain is being called, Reserved)
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD dwReason, LPVOID lpvReserved) {
	switch (dwReason)
	{
		case DLL_PROCESS_ATTACH:
			g_hInstance = hinstDLL;
			break;
		case DLL_PROCESS_DETACH:
			break;
	}

	return TRUE;
}

//callback function  (how to process message ,virtual key code , different meanings in different situations)
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
	char szPath[MAX_PATH] = {0};
	char *p = NULL;

	if (nCode >= 0)
	{
		// lParam : 32bit
		// bit 32 == 0 means the key is being pressed
		// 32 bit = 4 byte 
		if (!(lParam & 0x80000000)) {
			// get the current program ,you know
			GetModuleFileNameA(NULL, szPath, MAX_PATH);
			p = strrchr(szPath, '\\');
			//compare the name with our target, you know (stricmp is not case sensitive)
			if (!_stricmp(p + 1, "notepad++.exe"))
				return 1;
		}
	}

	//pass to the next hook, you know
	return CallNextHookEx(g_hHook, nCode, wParam, lParam);
}

#ifdef __cplusplus
extern "C" {
#endif
	__declspec(dllexport) void HookStart()
	{
		//SetWindowsHookEx(hooktype, callback function, handle of dll, ThreadID)
		g_hHook = SetWindowsHookEx(WH_KEYBOARD, KeyboardProc, g_hInstance, 0);
	}
	__declspec(dllexport) void HookStop()
	{
		if (g_hHook)
		{
			UnhookWindowsHookEx(g_hHook);
			g_hHook = NULL;
		}
	}
#ifdef __cplusplus
}
#endif
