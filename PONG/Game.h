#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include "Paddle.h"
#include "Ball.h"

struct Game
{
    Paddle playerPaddle;
    Paddle aiPaddle;
    Ball ball;
    sf::Vertex line[2];
    sf::Clock clock;
    float lastTime;
};

void StartGame(Game& game);
void UpdateGame(Game& game, sf::RenderWindow& window);