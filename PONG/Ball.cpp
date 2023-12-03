#include <SFML/Graphics/RenderWindow.hpp>
#include "Ball.h"
#include "Math.h"
#include "Constants.h"
#include "Paddle.h"

void InitializeBall(Ball& ball)
{
    ball.radius = BALL_RADIUS;
    SetBallPosition(ball, BALL_START_POSITION);

    const float ballStartAngle = (GetRadiansFromDegrees(GetRandomFloat(-ANGLE_MAX, ANGLE_MAX)));
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

void OnBallPaddleCollision(Ball& ball, Paddle& paddle)
{    
    const float angle = GetBallPaddleBounceAngle(ball, paddle);
    ball.moveDirection.x = std::cos(angle);
    ball.moveDirection.y = -std::sin(angle);
    ball.moveDirection = GetNormalizedVector(ball.moveDirection);
    
    if (ball.position.x < SCREEN_WIDTH / 2.f)    
        ball.bounceDirection |= (int)BounceDirectionBitMask::Right;    
    else    
        ball.bounceDirection |= (int)BounceDirectionBitMask::Left;    
    
    SetBallBounceDirection(ball);
}

void OnBallBoundsCollision(Ball& ball)
{
    if (ball.position.y > SCREEN_HEIGHT / 2.f)
        ball.bounceDirection |= static_cast<int>(BounceDirectionBitMask::Down);
    else
        ball.bounceDirection |= static_cast<int>(BounceDirectionBitMask::Up);

    SetBallBounceDirection(ball);
}

void MoveBall(Ball& ball, const float deltaTime)
{
    ball.position += ball.speed * ball.moveDirection * deltaTime;
    ball.shape.setPosition(ball.position);
}

void SetBallBounceDirection(Ball& ball)
{
    if (ball.bounceDirection & ((int)BounceDirectionBitMask::Left))
        ball.moveDirection.x = -ball.moveDirection.x;
    if (ball.bounceDirection & ((int)BounceDirectionBitMask::Up | (int)BounceDirectionBitMask::Down))
        ball.moveDirection.y = -ball.moveDirection.y; 

    ball.bounceDirection &= (int)BounceDirectionBitMask::None;
}

void DoBallCollisionTests(Ball& ball, Paddle& leftPaddle, Paddle& rightPaddle)
{
    if (CheckCollision(ball, leftPaddle))
        OnBallPaddleCollision(ball, leftPaddle);
    if (CheckCollision(ball, rightPaddle))
        OnBallPaddleCollision(ball, rightPaddle);
    else if (CheckVerticalBoundsCollision(ball))
        OnBallBoundsCollision(ball);        
}

float GetBallPaddleBounceAngle(const Ball& ball, const Paddle& paddle)
{
    const float relativeHitPositionY = (paddle.position.y + PADDLE_HEIGHT / 2.f) - ball.position.y;
    const float normalizeHitPositionY = relativeHitPositionY / (PADDLE_HEIGHT / 2.f);
    return GetRadiansFromDegrees(normalizeHitPositionY * ANGLE_MAX);    
}
