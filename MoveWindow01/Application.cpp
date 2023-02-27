#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <iostream>
#include <string>


std::wstring spotify(L"Spotify Premium"); 
BOOL CALLBACK EnumXWindows(_In_ HWND hwnd, _In_ LPARAM lParam)
{
	
	std::wstring title;
	auto len = GetWindowTextLengthW(hwnd);
	if (len != 0)
	{
		title.resize(255, 0);
		auto textLen = GetWindowTextW(hwnd, title.data(), title.size());
		//title.shrink_to_fit();
		if (textLen != 0) { 
			if (title.find(spotify) != std::wstring::npos)
			{
				RECT rct;
				GetWindowRect(hwnd, &rct);
				std::wcout << title.c_str() << L": " << (rct.right - rct.left) << "," << (rct.bottom - rct.top) << "\n";
			}
		}		
	}
	
	
	return TRUE; // continue enumeration
}
int wmain(int argc, wchar_t* argv[])
{
	
	EnumWindows(EnumXWindows, 0);
	/*auto spotifyWnd = FindWindowEx(HWND_DESKTOP, nullptr, L"Chrome_WidgetWin_0", nullptr);
	FindWindowExW()

		if (spotifyWnd != nullptr)
		{
			OutputDebugString(L"Found Window and will move it\n");
			SetWindowPos(spotifyWnd, nullptr, 5, 5, 0, 0, SWP_NOSIZE);
		}*/
	return 0;
}