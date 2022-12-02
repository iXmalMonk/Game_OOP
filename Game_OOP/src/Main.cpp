#include "../include/GameObject.h"
#include "../include/Player.h"
#include "../include/Enemy.h"

#include <list>

using namespace std;

int main()
{
	RenderWindow window(VideoMode(WINDOW_W, WINDOW_H), "Game_OOP", Style::Fullscreen);

	Event event;

	Clock clock;
	float time;

	list<GameObject*> gameObjects;
	gameObjects.push_back(new Player);
	gameObjects.push_back(new Enemy);

	while (window.isOpen())
	{
		while (window.pollEvent(event))
			if (event.type == Event::KeyPressed and event.key.code == Keyboard::Escape)
					window.close();

		time = clock.getElapsedTime().asMicroseconds() / FPS;
		clock.restart();

		for (auto gameObject : gameObjects)
			gameObject->update(time);

		window.clear();

		for (auto gameObject : gameObjects)
			window.draw(gameObject->getSprite());

		window.display();
	}

	return 0;
}