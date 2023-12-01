#include "Platform.h"
#include "Constants.h"
#include <SFML/Graphics/RenderWindow.hpp>

void InitializePlatform(Platform& platform, const Vector2D& startPosition)
{
    SetPlatformPosition(platform, startPosition);
    platform.size = Vector2D(PLATFORM_WIDTH, PLATFORM_HEIGHT);
    
    platform.shape.setSize(platform.size);
    platform.shape.setPosition(platform.position);
    platform.shape.setFillColor(sf::Color::Cyan);
}

void SetPlatformPosition(Platform& platform, const Vector2D& newPosition)
{
    platform.position = newPosition;
    platform.shape.setPosition(newPosition);
}

void DrawPlatform(const Platform& platform, sf::RenderWindow& window)
{
    window.draw(platform.shape);
}
