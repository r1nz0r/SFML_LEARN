#include <SFML/Graphics/RenderWindow.hpp>
#include <math.h>
#include "Ball.h"
#include "Math.h"
#include "Constants.h"
#include "Game.h"
#include "Paddle.h"

void InitializeBall(Ball& ball)
{    
    ball.radius = BALL_RADIUS;
    SetBallPosition(ball, BALL_START_POSITION);

    const float ballStartAngle = (GetRadiansFromDegrees(GetRandomFloat(ANGLE_MIN, ANGLE_MAX)));
    const bool negateDirection = GetRandomBool();    
    ball.moveDirection = {std::cos(ballStartAngle), std::sin(ballStartAngle)};
    
    if (negateDirection)
        ball.moveDirection.x = -ball.moveDirection.x;
    
    ball.shape.setRadius(ball.radius);
    ball.shape.setFillColor(sf::Color::Green);
    ball.shape.setOrigin(ball.radius, ball.radius);
}

void SetBallPosition(Ball& ball, const Vector2D& newPosition)
{
    ball.position = newPosition;
    ball.shape.setPosition(newPosition);
}

void DrawBall(const Ball& ball, sf::RenderWindow& window)
{
    window.draw(ball.shape);
}

void SetBallMoveDirection(Ball& ball, const Paddle& leftPaddle, const Paddle& rightPaddle)
{
    ball.bounceDirection = BounceDirection::None;

    if (CheckCollision(ball, leftPaddle))    
        ball.bounceDirection = BounceDirection::Right;    
    else if (CheckCollision(ball, rightPaddle))
        ball.bounceDirection = BounceDirection::Left;
    else    
        ball.bounceDirection = CheckVerticalBoundsCollision(ball);

    switch (ball.bounceDirection)
    {
    case BounceDirection::Down:
    case BounceDirection::Up:
        ball.moveDirection.y = -ball.moveDirection.y;
        break;
    case BounceDirection::Left:
    case BounceDirection::Right:
        ball.moveDirection.x = -ball.moveDirection.x;
        break;
    case BounceDirection::None:
        break;
    }

    ball.moveDirection = GetNormalizedVector(ball.moveDirection);
}


void MoveBall(Ball& ball, const float deltaTime)
{
    ball.position += ball.speed * ball.moveDirection * deltaTime;
    ball.shape.setPosition(ball.position);
}