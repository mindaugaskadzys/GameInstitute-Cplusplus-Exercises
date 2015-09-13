#include <windows.h>
#include <string>
#include <vector>
#include <iostream>
#include <commdlg.h>
#include <fstream>
using namespace std;


//Ex 16.6.4 - Choose color dialogs

int WINAPI
WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
PSTR cmdLine, int showCmd)
{
	CHOOSECOLOR cc;                 // common dialog box structure 
	static COLORREF acrCustClr[16]; // array of custom colors 
	HBRUSH hbrush;                  // brush handle
	static DWORD rgbCurrent;        // initial color selection

	//initialise the openfilename struct
	ZeroMemory(&cc, sizeof(cc));
	cc.lStructSize = sizeof(cc); //size of struct
	cc.hwndOwner = NULL; //no owner here
	cc.lpCustColors = (LPDWORD)acrCustClr; //array to keep custom colors in
	cc.rgbResult = rgbCurrent; //previous color/color selected storage
	cc.Flags = CC_FULLOPEN | CC_RGBINIT; //define full menu with custom colors + use color specified by rgbResult

	if (ChooseColor(&cc) == TRUE) //invoke dialog
	{
		//do nothing
	}

	//disclaimer: ripped straight from MSDN, but comments added because I had to figure out what the struct members are.
}

