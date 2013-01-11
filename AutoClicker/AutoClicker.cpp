// AutoClicker.cpp : main project file.
#include "stdafx.h"
#include <Windows.h>
#include <iostream>

#ifndef _USE_OLD_OSTREAMS
using namespace std;
#endif

using namespace AutoClicker;

[STAThreadAttribute]
int main()
{

	//Redirect the IO to Console.
	//#ifdef _DEBUG
	RedirectIOToConsole();
	//#endif

	fprintf(stdout, "Thank you for using my autoclicker\n");
	fprintf(stdout, "Any output will be printed here.\n");
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	// Create the main window and run it
	Application::Run(gcnew Form1());

	return 0;
}
