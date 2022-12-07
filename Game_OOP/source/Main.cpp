#include "..\include\Game.h"

int main()
{
	return Game::getInstance()->entry()->exit() ? 0 : 1;
}