#include <SFMl/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include "Collider.h"
#include "Constants.h"
#include "Ball.h"

bool CheckCollision(const Circle& object, const Rectangle& other)
{
    const float rectangleX = std::max(
        other.position.x, std::min(object.position.x, other.position.x + other.size.x));
    const float dx = object.position.x - rectangleX;

    const float rectangleY = std::max(
        other.position.y, std::min(object.position.y, other.position.y + other.size.y));
    const float dy = object.position.y - rectangleY;
    
    return (dx * dx + dy * dy) < (object.radius * object.radius);
}

bool CheckBoundsCollision(const Circle& object)
{
    if (object.position.x - object.radius <= 0 ||
        object.position.x + object.radius >= SCREEN_WIDTH ||
        object.position.y - object.radius <= 0 ||
        object.position.y + object.radius >= SCREEN_HEIGHT)
    {
        return true;
    }

    return false;
}

bool CheckBoundsCollision(const Rectangle& object)
{
    if (object.position.x <= 0 ||
        object.position.x + object.size.x >= SCREEN_WIDTH ||
        object.position.y <= 0 ||
        object.position.y + object.size.y >= SCREEN_HEIGHT)
    {
        return true;
    }

    return false;
}

bool CheckHorizontalBoundsCollision(const Circle& object)
{
    if (object.position.x + object.radius >= SCREEN_WIDTH ||
        object.position.x - object.radius <= 0)
        return true;

    return false;
}

bool CheckVerticalBoundsCollision(const Circle& object)
{
    if (object.position.y + object.radius >= SCREEN_HEIGHT ||
        object.position.y - object.radius <= 0)
            return true;

    return false;
}