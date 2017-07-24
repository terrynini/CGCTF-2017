// 006WindowsHook.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include "stdio.h"
#include "windows.h"

//new type for function pointer
typedef void(*PFN_HOOKSTART)();
typedef void(*PFN_HOOKSTOP)();

int main()
{
	//handle of a module
	HMODULE handleOfDll = NULL;
	PFN_HOOKSTART HookStart = NULL;
	PFN_HOOKSTOP HookStop = NULL;

	//Load KeyboardHook.dll
	handleOfDll = LoadLibraryA("KeyboardHook.dll");

	if (!handleOfDll) { printf("KeyBoardHook.dll not found!!\n"); system("pause"); return 0; }

	//get the address of hookstart and hookstop in KeyboardHook.dll
	HookStart = (PFN_HOOKSTART)GetProcAddress(handleOfDll, "HookStart");
	HookStop = (PFN_HOOKSTOP)GetProcAddress(handleOfDll, "HookStop");

	if (!HookStart || !HookStop) { printf("Hookfunction was not founded\n"); system("pause"); return 0; }
	
	//use the function pointer as a function!!
	HookStart();

	printf("press ANYKEY to EXIT\n");
	getchar();

	HookStop();

	FreeLibrary(handleOfDll);

    return 0;
}

