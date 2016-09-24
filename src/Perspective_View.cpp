#include "Perspective_View.h"

#include "Maths.h"

void Perspective_View::update ()
{

}

void Perspective_View::drawPlayer ()
{ }

#define FNcross(x1,y1, x2,y2) x1*y2 - y1*x2
void intersect ( const sf::Vector2f& vect1,
                 const sf::Vector2f& vect2,
                 const sf::Vector2f& vect3,
                 const sf::Vector2f& vect4,
                 float& x, float& y )
{
    x = FNcross( vect1.x, vect1.y, vect2.x, vect2.y );
    y = FNcross( vect3.x, vect3.y, vect4.x, vect4.y );

    float det = FNcross( vect1.x - vect2.x,
                         vect1.y - vect2.y,
                         vect3.x - vect4.x,
                         vect4.y - vect4.y);

    x = FNcross( x, vect1.x - vect2.x, y, vect3.x - vect4.x ) / det;
    y = FNcross( x, vect1.y - vect2.y, y, vect4.y - vect4.y ) / det;
}



void Perspective_View::drawWall ( Wall& wall, int index )
{
    //The "transforming" is the same as in the translate view
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


    //This is where transform view begins
    if ( wallStartZ > 0 || wallEndZ > 0 )
    {
        float ix1, ix2,
              iz1, iz2;
        intersect( { wallStart.x, wallStartZ}, {wallEnd.x, wallEndZ}, { -0.0001, 0.0001 }, { -20, 5 }, ix1, iz1 );
        intersect( { wallStart.x, wallStartZ}, {wallEnd.x, wallEndZ}, { 0.0001, 0.0001 },  { 20, 5 },  ix2, iz2 );

        if ( wallStartZ <= 0 )
        {
            if ( iz1 > 0 )
            {
                wallStart.x = ix1;
                wallStartZ  = iz1;
            }
            else
            {
                wallStart.x = ix2;
                wallStartZ  = iz2;
            }
        }
        if ( wallEndZ <= 0 )
        {
            if ( iz1 > 0 )
            {
                wallEnd.x = ix1;
                wallEndZ  = iz1;
            }
            else
            {
                wallEnd.x = ix2;
                wallEndZ  = iz2;
            }
        }

        float x1    = -wallStart.x * 16 / wallStartZ;
        float y1a   = -playerStartY      / wallStartZ;
        float y1b   = playerStartY      / wallStartZ;

        float x2    = -wallEnd.x * 16    / wallEndZ;
        float y2a   = -playerStartY      / wallEndZ;
        float y2b   = playerStartY       / wallEndZ;


        //The top of the wall
        sf::Vector2f topWallLeft  ( playerStartX + x1, playerStartY + y1a );
        sf::Vector2f topWallRight ( playerStartX + x2, playerStartY + y2a );
        drawLine ( topWallLeft,    topWallRight, colors.at( index ) );

        //The bottom of the wall
        sf::Vector2f bottomWallLeft  ( playerStartX + x1, playerStartY + y1b );
        sf::Vector2f bottomWallRight ( playerStartX + x2, playerStartY + y2b );
        drawLine ( bottomWallLeft, bottomWallRight, colors.at( index ) );

        //The left of the wall
        sf::Vector2f leftWallTop    ( playerStartX + x1, playerStartY + y1a );
        sf::Vector2f leftWallbottom ( playerStartX + x1, playerStartY + y1b );
        drawLine ( leftWallTop, leftWallbottom, colors.at( index ) );

        //The right of the wall
        sf::Vector2f rightWallTop    ( playerStartX + x2, playerStartY + y2a );
        sf::Vector2f rightWallbottom ( playerStartX + x2, playerStartY + y2b );
        drawLine ( rightWallTop, rightWallbottom, colors.at( index ) );

    }
}
