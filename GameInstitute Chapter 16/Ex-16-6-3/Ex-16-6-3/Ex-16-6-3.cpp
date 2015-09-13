#include <windows.h>
#include <string>
#include <vector>
#include "resource.h"
#include <iostream>
#include <commdlg.h>
#include <fstream>
using namespace std;

// Dialog handle.
HWND ghDlg = 0;
OPENFILENAME ofn;
wchar_t fileName[255];

//Ex 16.6.3 - Save/Load dialogs

// Dialog window procedure.
BOOL CALLBACK
MsgDlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	// Text buffer to be filled with string user entered
	// into edit control.
	char msgText[256];

	// Handles to the list box controls.
	static HWND hEdit = 0;

	wifstream inputStream;
	wofstream outputStream;

	switch (msg)
	{
	case WM_INITDIALOG:
		// Controls are child windows to the dialog they lie on.
		// In order to get and send information to and from a
		// control we will need a handle to it.  So save a handle
		// to the controls as the dialog is being initialized. 
		// Recall that we get a handle to a child control on a 
		// dialog box with the GetDlgItem.
		hEdit = GetDlgItem(hDlg, IDC_EDIT_BOX);

		return true;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_OPEN:
			GetOpenFileName(&ofn);
			inputStream.open(fileName);
			if (inputStream) {
				//determine length of file
				streamsize length = inputStream.gcount();
				wstring contents((istreambuf_iterator<wchar_t>(inputStream)),
					istreambuf_iterator<wchar_t>());

				SetWindowText(hEdit, contents.c_str());
				inputStream.close();
			}
			else {
				MessageBox(ghDlg, L"Could not open file!", L"Error", MB_OK);
			}
			return true;
		case IDC_SAVE:
			GetSaveFileName(&ofn);
			outputStream.open(fileName);
			if (outputStream) {
				int length = GetWindowTextLength(hEdit);
				wchar_t* buffer = new wchar_t[length+1];
				GetWindowText(hEdit, buffer, length+1);
				outputStream.write(buffer, length+1);
				delete[] buffer;
				outputStream.close();
			}
			else {
				MessageBox(ghDlg, L"Could not open file!", L"Error", MB_OK);
			}
			return true;
		}
		return true;
	case WM_CLOSE:
		DestroyWindow(hDlg);
		return true;
	case WM_DESTROY:
		PostQuitMessage(0);
		return true;
	}

	return false;
}

int WINAPI
WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
PSTR cmdLine, int showCmd)
{
	//initialise the openfilename struct
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL;
	ofn.lpstrFile = fileName;
	ofn.lpstrFile[0] = '\0';
	ofn.nMaxFile = sizeof(fileName);
	ofn.lpstrFilter = L"All\0*.*\0Text\0*.TXT\0";
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	// Create the modeless dialog window.
	ghDlg = CreateDialog(
		hInstance, // Application instance.
		MAKEINTRESOURCE(IDD_DIALOG1), // Dialog resource ID.
		0,  // Parent window--null for no parent.
		MsgDlgProc); // Dialog window procedure.

	// Show the dialog.
	ShowWindow(ghDlg, showCmd);

	// Enter the message loop.
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));
	while (GetMessage(&msg, 0, 0, 0))
	{
		// Is the message a dialog message?  If so the function
		// IsDialogMessage will return true and then dispatch
		// the message to the dialog window procedure.  
		// Otherwise, we process as the message as normal.
		if (ghDlg == 0 || !IsDialogMessage(ghDlg, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}

