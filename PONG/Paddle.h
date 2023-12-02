#pragma once
#include <SFML/Graphics/RectangleShape.hpp>

#include "Collider.h"
#include "Constants.h"

struct Ball;

namespace sf
{
    class RenderWindow;
}

enum class MoveDirection
{
    Up,
    Down,
    None
};


struct Paddle : Rectangle
{
    sf::RectangleShape shape;
    MoveDirection direction;
    float speed = PADDLE_MOVE_SPEED;
    Vector2D lastPosition;
};

void InitializePaddle(Paddle& paddle, const Vector2D& startPosition);
void SetPaddlePosition(Paddle& paddle, const Vector2D& newPosition);
void DrawPaddle(const Paddle& paddle, sf::RenderWindow& window);
void CalculatePlayerMovement(Paddle& paddle, const float deltaTime);
void CalculateAiMovement(Paddle& paddle, const Ball& ball, const float deltaTime);
void SetPaddleDirection(Paddle& paddle, const float deltaTime);
