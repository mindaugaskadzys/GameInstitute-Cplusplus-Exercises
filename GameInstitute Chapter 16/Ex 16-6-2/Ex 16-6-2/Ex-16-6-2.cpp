#include <windows.h>
#include <string>
#include <vector>
#include "resource.h"
#include <iostream>
using namespace std;

// Dialog handle.
HWND ghDlg = 0;

//Ex 16.6.2 - Checkboxes

// Dialog window procedure.
BOOL CALLBACK
MsgDlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	// Text buffer to be filled with string user entered
	// into edit control.
	char msgText[256];

	// Handles to the list box controls.
	static HWND hLight = 0;
	static HWND hHiDetTex = 0;
	static HWND hWireframe = 0;
	static HWND hShadows = 0;
	static HWND hGetButton = 0;

	wstring checkedItems = L"";

	switch (msg)
	{
	case WM_INITDIALOG:
		// Controls are child windows to the dialog they lie on.
		// In order to get and send information to and from a
		// control we will need a handle to it.  So save a handle
		// to the controls as the dialog is being initialized. 
		// Recall that we get a handle to a child control on a 
		// dialog box with the GetDlgItem.
		hLight = GetDlgItem(hDlg, IDC_LIGHTING_EN);
		hHiDetTex = GetDlgItem(hDlg, IDC_HI_DET_TEX);
		hWireframe = GetDlgItem(hDlg, IDC_WIREFRAME);
		hShadows = GetDlgItem(hDlg, IDC_SHADOWS_EN);
		hGetButton = GetDlgItem(hDlg, IDC_GET_DETAILS);

		return true;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_GET_DETAILS:
			if (SendMessage(hLight, BM_GETCHECK, 0, 0) == BST_CHECKED)
				checkedItems.append(L"Lighting on");
			if (SendMessage(hHiDetTex, BM_GETCHECK, 0, 0) == BST_CHECKED)
			{
				if (checkedItems.length() > 1)
					checkedItems.append(L", ");
				checkedItems.append(L"High Detail Textures on");
			}
			if (SendMessage(hWireframe, BM_GETCHECK, 0, 0) == BST_CHECKED)
			{
				if (checkedItems.length() > 1)
					checkedItems.append(L", ");
				checkedItems.append(L"Wireframe Mode on");
			}
			if (SendMessage(hShadows, BM_GETCHECK, 0, 0) == BST_CHECKED)
			{
				if (checkedItems.length() > 1)
					checkedItems.append(L", ");
				checkedItems.append(L"Shadows on");
			}
			if (checkedItems.length() > 1)
				checkedItems.append(L".");
			else
				checkedItems = L"All settings disabled.";
			MessageBox(0, checkedItems.c_str(), L"Checkbox Message", MB_OK);
			
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

