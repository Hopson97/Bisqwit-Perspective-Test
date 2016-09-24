#include "Normal.h"

#include <iostream>

#include "Maths.h"

void Normal::update()
{

}

void Normal::drawPlayer()
{
    float xd = Maths::cos ( player.angle - 90 ) * player.length;
    float yd = Maths::sin ( player.angle - 90 ) * player.length;

    drawLine( player.position, { player.position.x + xd, player.position.y + yd }, { 150, 255, 200 } );
}

void Normal::drawWall(Wall& wall, int index )
{
    drawLine( wall.start, wall.end, colors.at( index ) );
}
