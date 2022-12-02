#include "../include/GameObject.h"
#include "../include/Player.h"

int main()
{
	RenderWindow window(VideoMode(640, 480), "Game_OOP");

	Clock clock;
	float time;

	GameObject* gameObject = new Player;

	while (window.isOpen())
	{
		time = clock.getElapsedTime().asMilliseconds();
		clock.restart();

		gameObject->update(time);

		window.clear();
		window.draw(gameObject->getSprite());
		window.display();
	}
}