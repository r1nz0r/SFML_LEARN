#include <SFML\Graphics.hpp>
#include "Constants.h"

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

typedef sf::Vector2f Position2D;

class Platform
{
	Position2D position;
};

int main()
{
	sf::Window window;
	window.create(sf::VideoMode(WIDTH, HEIGHT), "Pong");

	while (window.isOpen())
	{
		sf:: Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}

	return 0;
}