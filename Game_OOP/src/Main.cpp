#include "..\include\Game.h"

int main()
{
	const auto game = (new Game)->entry();
	return game->exit() ? 0 : 1;
}