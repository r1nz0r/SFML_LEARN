#include "Math.h"

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