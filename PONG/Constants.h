#pragma once
#include <SFML/System/Vector2.hpp>

const std::string RESOURCES_PATH = "Resources/";
const std::string FONT_NAME = "/Fonts/Roboto-Black.ttf";

constexpr float SCORE_TEXT_HORIZONTAL_OFFSET = 100.f;
constexpr float SCORE_TEXT_VERTICAL_OFFSET = 20.f;

constexpr int SCREEN_HEIGHT = 600;
constexpr int SCREEN_WIDTH = 1000;

constexpr float PADDLE_WIDTH = 5.f;
constexpr float PADDLE_HEIGHT = 60.f;
constexpr float PADDLE_MOVE_SPEED = 300.f;
constexpr float PADDLE_SCREEN_OFFSET = 15.f;

const sf::Vector2f PLAYER_START_POSITION {
    PADDLE_SCREEN_OFFSET,
    SCREEN_HEIGHT / 2.f - PADDLE_HEIGHT / 2.f};

const sf::Vector2f AI_START_POSITION {
    SCREEN_WIDTH - PADDLE_WIDTH - PADDLE_SCREEN_OFFSET,
    SCREEN_HEIGHT / 2.f - PADDLE_HEIGHT / 2.f};

constexpr float BALL_RADIUS = 7.f;
constexpr float BALL_SPEED = 500.f;
const sf::Vector2f BALL_START_POSITION {
    SCREEN_WIDTH / 2.f,
    SCREEN_HEIGHT / 2.f};