#include <SFMl/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include "Math.h"
#include "Collider.h"
#include "Constants.h"


bool CheckCollision(const Circle& object, const Circle& other)
{
    const float squareDistance = (object.position.x - other.position.x) * (object.position.x - other.position.x) +
        (object.position.y - other.position.y) * (object.position.y - other.position.y);
    const float squareRadiusSum = (object.radius + other.radius) * (object.radius + other.radius);

    if (squareDistance <= squareRadiusSum)
    {
        return true;
    }

    return false;
}

bool CheckCollision(const Rectangle& object, const Rectangle& other)
{
    if (fabs(object.position.x - other.position.x) <= (object.size.x + other.size.x) / 2.0f &&
        fabs(object.position.y - other.position.y) <= (object.size.y + other.size.y) / 2.0f)
    {
        return true;
    }

    return false;
}

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