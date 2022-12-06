#include "..\include\Game.h"

int main()
{
	//const auto game = Game::create()->entry();
	//return game->destroy()->exit() ? 0 : 1;
	return Game::create()->entry()->destroy()->exit() ? 0 : 1;
}