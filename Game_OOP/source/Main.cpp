#include "..\include\Game.h"

int main()
{
	const auto game = Game::create()->entry();
	return game->destroy()->exit() ? 0 : 1;
}