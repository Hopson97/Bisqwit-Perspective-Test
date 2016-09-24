#include "View_Base.h"

#include <vector>
#include "Maths.h"

int View_Base::currPos = 5;

View_Base::View_Base()
:   player ( { playerStartX, playerStartY } )
{
    window.create( sf::VideoMode ( WIDTH, HEIGHT ), "Window", sf::Style::Close );
    window.setPosition( { currPos, 1080 / 2 - HEIGHT / 1.5 } );
    window.setFramerateLimit( 60 );

    //This is for other views
    currPos += WIDTH + gap;

    walls.push_back( Wall ( { 120, 170 }, { 400, 170 } ) );
    walls.push_back( Wall ( { 400, 170 }, { 380, 300 } ) );
    walls.push_back( Wall ( { 380, 300 }, { 120, 300 } ) );
    walls.push_back( Wall ( { 120, 300 }, { 120, 170 } ) );

    for ( sf::Uint8 i = 0 ; i < walls.size() ; i++ )
    {
        sf::Uint8 div = 255 / walls.size();

        colors.push_back( { 255, div * i, -div * i } );
    }
}

void View_Base::input()
{
    float x = 0;
    float y = 0;
    float speed = 1;

    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::W ) )
    {
        x = Maths::sin( player.angle ) * speed;
        y = Maths::cos( player.angle ) * speed;
    }
    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::S ) )
    {
        x = -Maths::sin( player.angle ) * speed;
        y = -Maths::cos( player.angle ) * speed;
    }
    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::A ) )
    {
        player.angle -= 1;
    }
    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::D ) )
    {
        player.angle += 1;
    }


    player.position += { x, -y };
}

void View_Base::draw()
{
    drawPlayer();
    for ( size_t i = 0 ; i < walls.size() ; i++ )
    {
        drawWall( walls[i], i );
    }
}

void View_Base::clear()
{
    window.clear();
}

void View_Base::display()
{
    window.display();
}

void View_Base::checkForClose()
{
    sf::Event e;
    while ( window.pollEvent( e ) )
    {
        if ( e.type == sf::Event::Closed )
        {
            window.close();
        }
    }
}

void View_Base::drawLine(const sf::Vector2f& start, const sf::Vector2f& end, sf::Color c )
{
    std::vector < sf::Vertex> line;
    sf::Vertex v;
    v.position  = start;
    v.color     = c;
    line.push_back ( v );

    sf::Vertex v1;
    v1.position = end;
    v1.color    = c;
    line.push_back( v1 );

    window.draw( line.data(), 2, sf::Lines );
    //line.clear();
}


bool View_Base::open()
{
    return window.isOpen();
}
