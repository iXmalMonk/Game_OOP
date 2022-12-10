#include "..\include\Console.h"

//void Console::hideConsole()
//{
//	ShowWindow(GetConsoleWindow(), SW_HIDE);
//}
//
//void Console::showConsole()
//{
//	ShowWindow(GetConsoleWindow(), SW_SHOW);
//}

void console::hide()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);
}

void console::show()
{
	ShowWindow(GetConsoleWindow(), SW_SHOW);
}