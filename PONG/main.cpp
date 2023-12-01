#include <SFML\Graphics.hpp>
#include "Constants.h"
#include "Platform.h"
#include "Player.h"

/*
Две прямоугольных платформы размещены в противоположных краях экрана. Одной с помощью стрелок клавиатуры управляет игрок, другой – ИИ
Движение платформы ограничено некоторой максимальной скоростью и ускорением.
Из центра экрана в случайном направлении (вправо или влево) и со случайной скоростью вылетает шарик.
Если он сталкивается с одной из платформ – он отскакивает в противоположную сторону (учитывая текущую скорость платформы).
Если шар сталкивается с краями экрана между платформами – он отскакивает от них.
Если же залетает за край, вдоль которого ездит одна из платформ, – засчитывается очко противоположной стороне и игра начинается сначала.
Статья про отражение мяча - https://yvision.kz/post/pong-raschet-otrazheniya-myacha-pri-soudarenii-s-poverhnostyu-361897
Видео оригинальной игры - https://www.youtube.com/watch?v=fiShX2pTz9A&ab_channel=andys-arcade
*/

int main()
{
	sf::RenderWindow window;
	window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Pong");

	Player player;
	InitializePlatform(player, PLAYER_START_POSITION);

	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f{SCREEN_WIDTH / 2.f, 0.f}),
		sf::Vertex(sf::Vector2f{SCREEN_WIDTH / 2.f, SCREEN_HEIGHT})
	};
	
	auto clock = sf::Clock();
	float lastTime = clock.getElapsedTime().asSeconds();
	
	while (window.isOpen())
	{
		window.clear();
		
		sf:: Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		float currentTime = clock.getElapsedTime().asSeconds();
		float deltaTime = currentTime - lastTime;
		lastTime = currentTime;

		CalculatePlayerMovement(player, deltaTime);
		SetPlatformPosition(player, player.position);
		DrawPlatform(player, window);
		window.draw(line, std::size(line), sf::Lines);
		window.display();
	}

	return 0;
}