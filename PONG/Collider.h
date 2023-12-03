#pragma once

struct Ball;
enum class BounceDirection;
using Vector2D = sf::Vector2<float>;

struct Circle
{
    Vector2D position; // position is center of circle
    float radius;
};

struct Rectangle 
{
    Vector2D position; // position is left top corner
    Vector2D size;
};   

bool CheckCollision(const Circle& object, const Rectangle& other);
bool CheckBoundsCollision(const Circle& object);
bool CheckBoundsCollision(const Rectangle& object);
bool CheckHorizontalBoundsCollision(const Circle& object);
bool CheckVerticalBoundsCollision(const Circle& object);