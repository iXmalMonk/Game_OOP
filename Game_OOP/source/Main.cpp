#include "..\include\Game.h"

int main()
{
	return Game::getInstance()->entry()->destroy()->exit();
}