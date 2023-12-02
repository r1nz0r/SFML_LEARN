#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Paddle.h"
#include "Constants.h"
#include "Ball.h"
#include "Math.h"

void InitializePaddle(Paddle& paddle, const Vector2D& startPosition)
{
    SetPaddlePosition(paddle, startPosition);
    paddle.size = Vector2D(PADDLE_WIDTH, PADDLE_HEIGHT);
    
    paddle.shape.setSize(paddle.size);
    paddle.shape.setPosition(paddle.position);
    paddle.shape.setFillColor(sf::Color::Cyan);
}

void SetPaddlePosition(Paddle& paddle, const Vector2D& newPosition)
{
    paddle.position = newPosition;
    paddle.shape.setPosition(newPosition);
}

void DrawPaddle(const Paddle& paddle, sf::RenderWindow& window)
{
    window.draw(paddle.shape);
}

void CalculatePlayerMovement(Paddle& paddle, const float deltaTime)
{
    //Player movement calculation
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        paddle.direction = MoveDirection::Up;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        paddle.direction = MoveDirection::Down;
    else
        paddle.direction = MoveDirection::None;
    
    SetPaddleDirection(paddle, deltaTime);
}

void CalculateAiMovement(Paddle& paddle, const Ball& ball, const float deltaTime)
{
    const float lastCenterY = paddle.lastPosition.y + paddle.size.y / 2.f;
    
    if (lastCenterY > ball.position.y)
        paddle.direction = MoveDirection::Up;
    else if (lastCenterY < ball.position.y)
        paddle.direction = MoveDirection::Down;
    else
        paddle.direction = MoveDirection::None;
    
    SetPaddleDirection(paddle, deltaTime);
}

void LimitPaddleMovement(Paddle& paddle)
{
    paddle.position.y = paddle.lastPosition.y;
    paddle.direction = MoveDirection::None;
}

void SetPaddleDirection(Paddle& paddle, const float deltaTime)
{
    float deltaY = 0;
    
    switch (paddle.direction)
    {   
    case MoveDirection::Down:
        {
            deltaY = 1.f;
            break;
        }
    case MoveDirection::Up:
        {
            deltaY = -1.f;
            break;
        }
    case MoveDirection::None:
        deltaY = 0.0f;
        break;
    }

    if (!CheckBoundsCollision(paddle))
    {
        paddle.lastPosition = paddle.position;
        paddle.position.y += deltaY * paddle.speed * deltaTime;
    }
    else
    {
        LimitPaddleMovement(paddle);
    }
}


