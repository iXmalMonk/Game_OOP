#include "..\include\Console.h"

void Console::HideConsole()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);
}

void Console::ShowConsole()
{
	ShowWindow(GetConsoleWindow(), SW_SHOW);
}
