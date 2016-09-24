#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

struct Player
{
    Player ( const sf::Vector2f& pos)
    :   position ( pos )
    {

    }

    sf::Vector2f position;
    float angle;

    constexpr static float length = 10;
};

#endif // PLAYER_H
