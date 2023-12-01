#include "Math.h"

auto SetSpriteSize(sf::Sprite& sprite, const float desiredWidth, float desiredHeight) -> void
{
    const sf::FloatRect spriteRect = sprite.getLocalBounds();
    const sf::Vector2f scale = {desiredWidth / spriteRect.width, desiredHeight / spriteRect.height};
    sprite.setScale(scale);
}

void SetSpriteRelativeOrigin(sf::Sprite& sprite, const float originX, const float originY)
{
    const sf::FloatRect spriteRect = sprite.getLocalBounds();
    sprite.setOrigin(originX * spriteRect.width, originY * spriteRect.height);
}