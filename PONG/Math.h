#pragma once
#include <SFML/Graphics.hpp>

constexpr float FLOAT_TOLERANCE = 0.001f;
constexpr float PI = 3.14f;
constexpr float STRAIGHT_ANGLE = 180.f;

typedef sf::Vector2f Vector2D;

bool IsNearlyEqual(const float numOne, const float numTwo);
Vector2D GetNormalizedVector(const Vector2D& baseVector);
float GetRadiansFromDegrees(const float degrees);
float GetRandomFloat(const float minValue, const float maxValue);
bool GetRandomBool();