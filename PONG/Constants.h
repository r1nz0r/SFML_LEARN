#pragma once
#include <SFML/System/Vector2.hpp>

constexpr int SCREEN_HEIGHT = 600;
constexpr int SCREEN_WIDTH = 1000;

constexpr float PADDLE_WIDTH = 10.f;
constexpr float PADDLE_HEIGHT = 100.f;
constexpr float PADDLE_MOVE_SPEED = 200.0f;
constexpr float PADDLE_SCREEN_OFFSET = 15.f;

const sf::Vector2f PLAYER_START_POSITION {
    PADDLE_SCREEN_OFFSET,
    SCREEN_HEIGHT / 2.f - PADDLE_HEIGHT / 2.f};

const sf::Vector2f AI_START_POSITION {
    SCREEN_WIDTH - PADDLE_WIDTH - PADDLE_SCREEN_OFFSET,
    SCREEN_HEIGHT / 2.f - PADDLE_HEIGHT / 2.f};

constexpr float BALL_RADIUS = 10.f;
constexpr float BALL_SPEED = 500.f;
const sf::Vector2f BALL_START_POSITION {
    SCREEN_WIDTH / 2.f,
    SCREEN_HEIGHT / 2.f};