#ifndef _CONSOLE_H
#define _CONSOLE_H

#include "..\Main.h"

namespace console
{
	enum class Color { BLACK = 0,
		GRAY = 7,
		GREEN = 10,
		RED = 12,
		WHITE = 15,
		YELLOW = 14 };

	void hide();
	void print(string _text,
		Color _font,
		Color _background);
	void show();
}

#endif // !_CONSOLE_H