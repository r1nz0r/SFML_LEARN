#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include "Paddle.h"
#include "Ball.h"
#include "UI.h"

struct Game
{
    Paddle playerPaddle;
    Paddle aiPaddle;
    Ball ball;
    Label playerScoreLabel;
    Label aiScoreLabel;
    sf::Vertex line[2];
    sf::Clock clock;
    float lastTime;
    
    int playerScore = 0;
    int aiScore = 0;
};

void StartGame(Game& game);
void RestartGame(Game& game);
void UpdateGame(Game& game, sf::RenderWindow& window);