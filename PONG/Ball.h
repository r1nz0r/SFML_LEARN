#pragma once
#include <SFML/Graphics/CircleShape.hpp>
#include "Collider.h"
#include "Constants.h"

struct Paddle;

//degree
constexpr float ANGLE_MAX = 50;

namespace sf
{
    class RenderWindow;
}

enum class BounceDirectionBitMask
{
    Up = 1 << 0,
    Down = 1 << 1,
    Right = 1 << 2,
    Left = 1 << 3,
    None = 0
};

struct Ball : Circle
{
    sf::CircleShape shape;
    float speed = BALL_SPEED;
    Vector2D moveDirection;
    int bounceDirection = 0;
};

void InitializeBall(Ball& ball);
void SetBallPosition(Ball& ball, const Vector2D& newPosition);
void OnBallPaddleCollision(Ball& ball, Paddle& paddle);
void MoveBall(Ball& ball, const float deltaTime);
void DrawBall(const Ball& ball, sf::RenderWindow& window);
void DoBallCollisionTests(Ball& ball, Paddle& leftPaddle, Paddle& rightPaddle);
void OnBallBoundsCollision(Ball& ball);
void SetBallBounceDirection(Ball& ball);
float GetBallPaddleBounceAngle(const Ball& ball, const Paddle& paddle);