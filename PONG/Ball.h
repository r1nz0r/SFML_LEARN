#pragma once
#include <SFML/Graphics/CircleShape.hpp>
#include "Collider.h"
#include "Constants.h"

struct Paddle;

//degree
constexpr float ANGLE_MIN = -75;
constexpr float ANGLE_MAX = 75;

namespace sf
{
    class RenderWindow;
}

enum class BounceDirection
{
    Up,
    Down,
    Right,
    Left,
    None
};

struct Ball : Circle
{
    sf::CircleShape shape;
    float speed = BALL_SPEED;
    Vector2D moveDirection;
    BounceDirection bounceDirection = BounceDirection::None;
};

void InitializeBall(Ball& ball);
void SetBallPosition(Ball& ball, const Vector2D& newPosition);
void SetBallMoveDirection(Ball& ball, const Paddle& leftPaddle, const Paddle& rightPaddle);
void MoveBall(Ball& ball, const float deltaTime);
void DrawBall(const Ball& ball, sf::RenderWindow& window);
