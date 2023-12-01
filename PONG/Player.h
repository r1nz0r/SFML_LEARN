#pragma once
#include "Constants.h"
#include "Platform.h"

enum class MoveDirection
{
    Up,
    Down,
    None
};

struct Player : Platform
{
    MoveDirection direction = MoveDirection::None;
    Vector2D lastPosition;
    float speed = PLATFORM_MOVE_SPEED;
};

void CalculatePlayerMovement(Player& player, const float deltaTime);
