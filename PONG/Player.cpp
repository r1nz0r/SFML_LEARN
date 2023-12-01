#include "Player.h"

#include <SFML/Window/Keyboard.hpp>

void CalculatePlayerMovement(Player& player, const float deltaTime)
{
    //Player movement calculation
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        player.direction = MoveDirection::Up;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        player.direction = MoveDirection::Down;

    float deltaY = 0;
    
    switch (player.direction)
    {   
    case MoveDirection::Down:
        {
            deltaY = 1.f;
            break;
        }
    case MoveDirection::Up:
        {
            deltaY = -1.f;
            break;
        }
    case MoveDirection::None:
        deltaY = 0.0f;
        break;
    }

    if (!CheckBoundsCollision(player))
    {
        player.lastPosition = player.position;
        player.position.y += deltaY * player.speed * deltaTime;
    }
    else
    {
        player.position.y = player.lastPosition.y;
        player.direction = MoveDirection::None;
    }
}
