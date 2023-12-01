#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include "Collider.h"

namespace sf
{
    class RenderWindow;
}


struct Platform : Rectangle
{
    sf::RectangleShape shape;
};

void InitializePlatform(Platform& platform, const Vector2D& startPosition);
void SetPlatformPosition(Platform& platform, const Vector2D& newPosition);
void DrawPlatform(const Platform& platform, sf::RenderWindow& window);
