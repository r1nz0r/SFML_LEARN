#include <process.h>
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Game.h"

int main()
{
	sf::RenderWindow window;
	window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Pong");
	
	std::srand(_getpid());
	
	Game game;
	StartGame(game);	
	
	while (window.isOpen())
	{
		window.clear();
		
		sf:: Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				window.close();
		}

		UpdateGame(game, window);
		window.display();
	}

	return 0;
}