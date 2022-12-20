#include "..\include\Console.h"

void console::hide()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);
}

void console::show()
{
	ShowWindow(GetConsoleWindow(), SW_SHOW);
}