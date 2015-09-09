#include <windows.h>
#include <string>
#include "resource.h"
// Store handles to the main window and application
// instance globally.
HWND ghWnd[3];
HINSTANCE ghAppInst = 0;
HICON gIcon;

void handleKeyDown(WPARAM key, int windowNumber) {
	if (key == VK_ESCAPE) {
		//Ex 14.6.1 - Exit Message
		int selection = MessageBox(0, L"Do you really want to quit?", L"Confirm", MB_YESNO);
		if (selection == IDYES)
			DestroyWindow(ghWnd[windowNumber-1]);
	}
}

void handleLeftClick(int windowNumber) {
	std::wstring message = L"You clicked on Window " + std::to_wstring(windowNumber);
	MessageBox(0, message.c_str(), L"Msg", MB_OK);
}

//Define common behaviour between the window procedures
LRESULT WndProc_Common(int windowNumber, HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
		// Handle left mouse button click message.
	case WM_LBUTTONDOWN:
	{
		handleLeftClick(windowNumber);
		return 0;
		// Handle key down message.
	}
	case WM_KEYDOWN:
		handleKeyDown(wParam, windowNumber);
		return 0;
		// Handle destroy window message.
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	// Forward any other messages we didn't handle to the
	// default window procedure.
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

//Ex 14.6.3 - Multiple Windows
//Could re-use same window procedure for all 3 windows by specifying window no. in wParam or lParam probably
//But the Exercise asks to define 3 separate window procedures, so I guess it wants me to practice doing that.
LRESULT CALLBACK
Wnd1Proc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return WndProc_Common(1, hWnd, msg, wParam, lParam);
}
LRESULT CALLBACK
Wnd2Proc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return WndProc_Common(2, hWnd, msg, wParam, lParam);
}
LRESULT CALLBACK
Wnd3Proc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return WndProc_Common(3, hWnd, msg, wParam, lParam);
}

//Take the given code to create a window and try to make it re-usable for multiple windows
//Ex 14.6.5 - Add background colour parameter
bool makeWindow(WNDPROC wndProc, int showCmd, int wndNumber, int x, int y, int h, int w, COLORREF bgColor)
{
	// Step 2: Fill out a WNDCLASS instance.
	WNDCLASS wc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = wndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = ghAppInst;
	wc.hIcon = gIcon;
	//Ex 14.6.4 - Mouse Cursor
	wc.hCursor = ::LoadCursor(0, IDC_HAND);
	//Ex 14.6.5 - Background colour
	LOGBRUSH lb;
	lb.lbStyle = BS_SOLID;
	lb.lbColor = bgColor;
	HBRUSH brush = CreateBrushIndirect(&lb);
	wc.hbrBackground = brush;
	wc.lpszMenuName = 0;
	//define class name
	std::wstring className = L"MyWndClassName" + std::to_wstring(wndNumber);
	wc.lpszClassName = className.c_str();
	// Step 3: Register the WNDCLASS instance with Windows.
	RegisterClass(&wc);
	// Step 4: Create the window, and save handle in globla
	// window handle variable ghMainWnd.

	//define window name
	std::wstring wndName = L"MyWindow " + std::to_wstring(wndNumber);
	//Ex 14.6.2 - Vertical and Horizontal scroll bars
	ghWnd[wndNumber-1] = ::CreateWindow(wc.lpszClassName, wndName.c_str(),
		(WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL), x, y, w, h, 0, 0, ghAppInst, 0);
	if (ghWnd[wndNumber-1] == 0)
	{
		::MessageBox(0, L"CreateWindow - Failed", 0, 0);
		return false;
	}
	// Step 5: Show and update the window.
	ShowWindow(ghWnd[wndNumber-1], showCmd);
	UpdateWindow(ghWnd[wndNumber-1]);

	return true;
}

// WinMain: Entry point for a Windows application.
int WINAPI
WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
PSTR cmdLine, int showCmd)
{
	// Save handle to application instance.
	ghAppInst = hInstance;
	//Ex 14.6.6 - Custom Icon
	LPCWSTR iconName = MAKEINTRESOURCE(IDI_ICON1);
	gIcon = ::LoadIcon(ghAppInst, iconName);
	
	//Ex 14.6.3 - Multiple Windows and Ex 14.6.5 - Background colours
	makeWindow(Wnd1Proc, showCmd, 1, 0, 0, 200, 200, RGB(255,0,0));
	makeWindow(Wnd2Proc, showCmd, 2, 200, 200, 200, 200, RGB(0,255,0));
	makeWindow(Wnd3Proc, showCmd, 3, 400, 400, 200, 200, RGB(0,0,255));

	// Step 6: Enter the message loop and don't quit until
	// a WM_QUIT message is received.
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));
	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	// Return exit code back to operating system.
	return (int)msg.wParam;
}