#include "Transform_View.h"

#include <iostream>

#include "Maths.h"

void Transform_View::update()
{

}

void Transform_View::drawPlayer()
{
    drawLine(  { playerStartX, playerStartY},
               { playerStartX, playerStartY + player.length }, { 150, 255, 200 } );
}


void Transform_View::drawWall( Wall& wall, int index )
{
    sf::Vector2f wallStart;
    sf::Vector2f wallEnd;

    float px = player.position.x;
    float py = player.position.y;

    //Get the difference in position between the player's current position and the original wall position
    wallStart.x = px - wall.start.x;
    wallStart.y = py - wall.start.y;

    wallEnd.x = px - wall.end.x;
    wallEnd.y = py - wall.end.y;

    //Rotate
    float wallStartZ    = wallStart.x * Maths::cos( player.angle + 90 ) + wallStart.y * Maths::sin( player.angle + 90  );
    float wallEndZ      = wallEnd.x   * Maths::cos( player.angle + 90 ) + wallEnd.y   * Maths::sin( player.angle + 90  );

    wallStart.x         = wallStart.x * Maths::sin( player.angle + 90  ) - wallStart.y * Maths::cos( player.angle + 90  );
    wallEnd.x           = wallEnd.x   * Maths::sin( player.angle + 90  ) - wallEnd.y   * Maths::cos( player.angle + 90  );


    drawLine ( { playerStartX - wallStart.x, playerStartY - wallStartZ },
               { playerStartX - wallEnd.x,   playerStartY - wallEndZ   },
                 colors.at( index ) );
}


