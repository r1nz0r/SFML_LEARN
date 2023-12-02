#include <process.h>
#include <SFML/Graphics.hpp>

#include "Ball.h"
#include "Constants.h"
#include "Game.h"
#include "Paddle.h"

/*
Две прямоугольных платформы размещены в противоположных краях экрана.
Одной с помощью стрелок клавиатуры управляет игрок, другой – ИИ
Движение платформы ограничено некоторой максимальной скоростью и ускорением.
Из центра экрана в случайном направлении (вправо или влево) и со случайной скоростью вылетает шарик.
Если он сталкивается с одной из платформ – он отскакивает в противоположную сторону
(учитывая текущую скорость платформы).
Если шар сталкивается с краями экрана между платформами – он отскакивает от них.
Если же залетает за край, вдоль которого ездит одна из платформ, – засчитывается очко противоположной стороне
и игра начинается сначала.
Статья про отражение мяча - https://yvision.kz/post/pong-raschet-otrazheniya-myacha-pri-soudarenii-s-poverhnostyu-361897
Видео оригинальной игры - https://www.youtube.com/watch?v=fiShX2pTz9A&ab_channel=andys-arcade
*/

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