#include <SFML\Graphics.hpp>
#include "Constants.h"
#include "Platform.h"
#include "Player.h"

/*
��� ������������� ��������� ��������� � ��������������� ����� ������. ����� � ������� ������� ���������� ��������� �����, ������ � ��
�������� ��������� ���������� ��������� ������������ ��������� � ����������.
�� ������ ������ � ��������� ����������� (������ ��� �����) � �� ��������� ��������� �������� �����.
���� �� ������������ � ����� �� �������� � �� ����������� � ��������������� ������� (�������� ������� �������� ���������).
���� ��� ������������ � ������ ������ ����� ����������� � �� ����������� �� ���.
���� �� �������� �� ����, ����� �������� ����� ���� �� ��������, � ������������� ���� ��������������� ������� � ���� ���������� �������.
������ ��� ��������� ���� - https://yvision.kz/post/pong-raschet-otrazheniya-myacha-pri-soudarenii-s-poverhnostyu-361897
����� ������������ ���� - https://www.youtube.com/watch?v=fiShX2pTz9A&ab_channel=andys-arcade
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