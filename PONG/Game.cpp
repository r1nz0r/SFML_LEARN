#include "Game.h"

#include <iostream>

#include "Constants.h"
#include <SFML/Graphics/Text.hpp>

void StartGame(Game& game)
{    
    InitializePaddle(game.playerPaddle, PLAYER_START_POSITION);
    InitializePaddle(game.aiPaddle, AI_START_POSITION);
    
    const Vector2D playerScorePosition
    {
        SCREEN_WIDTH / 2.f - SCORE_TEXT_HORIZONTAL_OFFSET - static_cast<float>(game.playerScoreLabel.textSize),
        SCORE_TEXT_VERTICAL_OFFSET
    };    
    InitializeLabel(game.playerScoreLabel, playerScorePosition);

    const Vector2D aiScorePosition
    {
        SCREEN_WIDTH / 2.f + SCORE_TEXT_HORIZONTAL_OFFSET,
        SCORE_TEXT_VERTICAL_OFFSET
    };     
    InitializeLabel(game.aiScoreLabel, aiScorePosition);    

    RestartGame(game);
    
    game.line[0] = sf::Vertex(sf::Vector2f{SCREEN_WIDTH / 2.f, 0.f});
    game.line[1] = sf::Vertex(sf::Vector2f{SCREEN_WIDTH / 2.f, SCREEN_HEIGHT}); 
}

void RestartGame(Game& game)
{
    InitializeBall(game.ball);
    game.lastTime = game.clock.getElapsedTime().asSeconds();        
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
		
    DoBallCollisionTests(game.ball, game.playerPaddle, game.aiPaddle);
    MoveBall(game.ball, deltaTime);
    DrawBall(game.ball, window);
    
    if (CheckHorizontalBoundsCollision(game.ball))
    {
        if (game.ball.position.x < SCREEN_WIDTH / 2.f)        
            OnLabelChange(game.aiScoreLabel, std::to_string(++game.aiScore));     
        else
            OnLabelChange(game.playerScoreLabel, std::to_string(++game.playerScore));     
        
        RestartGame(game);
    }        

    DrawLabel(game.playerScoreLabel, window);
    DrawLabel(game.aiScoreLabel, window);
    
    window.draw(game.line, std::size(game.line), sf::Lines);
    game.lastTime = currentTime;
}

