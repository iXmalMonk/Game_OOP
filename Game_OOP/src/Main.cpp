#include <SFML/Graphics.hpp>

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "GAME", Style::Fullscreen);

	while (window.isOpen())
	{
		if (Keyboard::isKeyPressed(Keyboard::Escape))
			window.close();

		window.clear();

		window.display();
	}

	return 0;
}