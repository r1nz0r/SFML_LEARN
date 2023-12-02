#include "Game.h"

void StartGame(Game& game)
{
    InitializePaddle(game.playerPaddle, PLAYER_START_POSITION);
    InitializePaddle(game.aiPaddle, AI_START_POSITION);
    InitializeBall(game.ball);

    game.lastTime = game.clock.getElapsedTime().asSeconds();
    
    game.line[0] = sf::Vertex(sf::Vector2f{SCREEN_WIDTH / 2.f, 0.f});
    game.line[1] = sf::Vertex(sf::Vector2f{SCREEN_WIDTH / 2.f, SCREEN_HEIGHT}); 
}

void UpdateGame(Game& game, sf::RenderWindow& window)
{    
    const float currentTime = game.clock.getElapsedTime().asSeconds();
    const float deltaTime = currentTime - game.lastTime;

    CalculatePlayerMovement(game.playerPaddle, deltaTime);
    SetPaddlePosition(game.playerPaddle, game.playerPaddle.position);
    DrawPaddle(game.playerPaddle, window);
		
    CalculateAiMovement(game.aiPaddle, game.ball, deltaTime);
    SetPaddlePosition(game.aiPaddle, game.aiPaddle.position);
    DrawPaddle(game.aiPaddle, window);		
		
    SetBallMoveDirection(game.ball, game.playerPaddle, game.aiPaddle);
    MoveBall(game.ball, deltaTime);
    DrawBall(game.ball, window);

    if (CheckHorizontalBoundsCollision(game.ball))
        StartGame(game);
    
    window.draw(game.line, std::size(game.line), sf::Lines);
    game.lastTime = currentTime;
}

