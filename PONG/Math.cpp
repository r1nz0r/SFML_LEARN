#include "Math.h"

auto SetSpriteSize(sf::Sprite& sprite, const float desiredWidth, float desiredHeight) -> void
{
	const sf::FloatRect spriteRect = sprite.getLocalBounds();
	const sf::Vector2f scale = { desiredWidth / spriteRect.width, desiredHeight / spriteRect.height };
	sprite.setScale(scale);
}

void SetSpriteRelativeOrigin(sf::Sprite& sprite, const float originX, const float originY)
{
	const sf::FloatRect spriteRect = sprite.getLocalBounds();
	sprite.setOrigin(originX * spriteRect.width, originY * spriteRect.height);
}

Vector2D GetNormalizedVector(const Vector2D& baseVector)
{
	const float length = sqrt(baseVector.x * baseVector.x + baseVector.y * baseVector.y);
	return Vector2D{ baseVector.x / length, baseVector.y / length };
}

bool IsNearlyEqual(const float numOne, const float numTwo)
{
	return (std::fabs(numOne - numTwo) <= FLOAT_TOLERANCE);
}

float GetRadiansFromDegrees(const float degrees)
{
	return degrees * PI / STRAIGHT_ANGLE;
}

float GetRandomFloat(const float minValue, const float maxValue)
{
	return minValue + rand() / static_cast<float>((RAND_MAX)) * (maxValue - minValue);
}
bool GetRandomBool()
{
	return static_cast<bool>(rand() % 2);
}