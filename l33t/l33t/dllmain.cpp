/*
	Absolutely amazing
*/

/* 
	
		LEET IS VERY FUN
		LEET IS VERY FUN
		LEET IS VERY FUN
		LEET IS VERY FUN
		LEET IS VERY FUN
		LEET IS VERY FUN
		LEET IS VERY FUN
		LEET IS VERY FUN
		LEET IS VERY FUN

*/

#include <Windows.h>
#include <thread>

using namespace std::this_thread;
using namespace std::chrono;

HMODULE g_hDll = NULL;

void cleanup(void);

DWORD WINAPI Init(LPVOID lpThreadParams)
{
	for (;;)
	{
		if(GetAsyncKeyState(VK_END) & 0x8000)
		{
			while (GetAsyncKeyState(VK_END) & 0x8000)
				sleep_for(5ms);

			cleanup();
			break;
		}

		sleep_for(50ms);
	}

	return 1;
}

void cleanup(void)
{
	TerminateThread(Init, 0);
	FreeLibraryAndExitThread(g_hDll, 0);
}

BOOL APIENTRY DllMain(_In_ HMODULE hMod, _In_ DWORD fdwReason, _In_ LPVOID lpReserved)
{
	if(fdwReason == DLL_PROCESS_ATTACH)
	{
		g_hDll = hMod;
		DisableThreadLibraryCalls(hMod);
		CreateThread(nullptr, NULL, &Init, nullptr, NULL, nullptr);
	}

	return TRUE;
}