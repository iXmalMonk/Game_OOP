#include "..\..\include\utilts\Console.h"

void console::hide()
{
	ShowWindow(GetConsoleWindow(),
		SW_HIDE);
}

void console::print(string _text, Color _font, Color _background)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,
		int(_font) + (int(_background) << 4));
	cout << _text;
	SetConsoleTextAttribute(hConsole,
		int(Color::GRAY));
}

void console::show()
{
	ShowWindow(GetConsoleWindow(),
		SW_SHOW);
}