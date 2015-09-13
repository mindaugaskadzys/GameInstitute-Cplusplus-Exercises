#include <windows.h>
#include <string>
#include <vector>
#include "resource.h"
#include <iostream>
using namespace std;

// Dialog handle.
HWND ghDlg = 0;

//Ex 16.6.1 - Rewrite Combo box example to use list box

// Dialog window procedure.
BOOL CALLBACK
MsgDlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	// Text buffer to be filled with string user entered
	// into edit control.
	char msgText[256];

	// Handles to the list box controls.
	static HWND hListBox  = 0;
	static HWND hEditBox   = 0;
	static HWND hAddButton = 0;

	int count = 0;
	int* selectedIndexes = 0;

	switch( msg )
	{
	case WM_INITDIALOG:
		// Controls are child windows to the dialog they lie on.
		// In order to get and send information to and from a
		// control we will need a handle to it.  So save a handle
		// to the controls as the dialog is being initialized. 
		// Recall that we get a handle to a child control on a 
		// dialog box with the GetDlgItem.
		hListBox  = GetDlgItem(hDlg, IDC_LISTBOX);
	    hEditBox   = GetDlgItem(hDlg, IDC_EDIT_MSG);
	    hAddButton = GetDlgItem(hDlg, IDC_ADDBUTTON);	

		return true;
	case WM_COMMAND:
		switch(HIWORD(wParam))
		{
		// User selected a list box item.
		case LBN_SELCHANGE:
			//get the number of selected items
			//NOTE: accidentally made a multi-selection list box, decided to stick with it as it looks cool
			count = (int)SendMessage(hListBox, LB_GETSELCOUNT, 0, 0);
			delete[] selectedIndexes;
			selectedIndexes = 0;
			selectedIndexes = new int[count];
			SendMessage(hListBox, LB_GETSELITEMS, (WPARAM)count, (LPARAM)selectedIndexes);
			string selItems = "";
			for (int i = 0; i < count; i++) {
				SendMessage(hListBox, LB_GETTEXT, (WPARAM)selectedIndexes[i], (LPARAM)msgText);
				selItems.append(msgText);
				selItems.append("\n");
			}
			MessageBox(0, selItems.c_str(), "List Message", MB_OK);
			return true;
		}
		switch(LOWORD(wParam))
		{
		// User pressed the "Add" button.
		case IDC_ADDBUTTON:
			// Get the text from the edit box.
			GetWindowText(hEditBox, msgText, 256);

			// Add the text to the list box only if the user entered
			// a string that is greater than zero.
			if( strlen(msgText) > 0 )
				SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)msgText);

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
		MAKEINTRESOURCE(IDD_COMBODLG), // Dialog resource ID.
		0,  // Parent window--null for no parent.
		MsgDlgProc); // Dialog window procedure.

	// Show the dialog.
	ShowWindow(ghDlg, showCmd);

	// Enter the message loop.
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));
	while( GetMessage( &msg, 0, 0, 0 ) )
	{
		// Is the message a dialog message?  If so the function
		// IsDialogMessage will return true and then dispatch
		// the message to the dialog window procedure.  
		// Otherwise, we process as the message as normal.
		if( ghDlg == 0 || !IsDialogMessage(ghDlg, &msg ) )
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return (int)msg.wParam;
}
			
