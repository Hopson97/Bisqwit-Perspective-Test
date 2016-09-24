#ifndef VIEW_BASE_H
#define VIEW_BASE_H

/* This is just a prototype/ test, so I'm just gunna make the stuff protected or public mostly */

#include <SFML/Graphics.hpp>

#include "Player.h"

struct Wall
{
    Wall ( const sf::Vector2f& start, const sf::Vector2f& end )
    :   start   ( start )
    ,   end     ( end )
    {}

    sf::Vector2f start;
    sf::Vector2f end;
};

class View_Base
{
    public:
        View_Base       ();

        void input      ();
        void draw       ();
        virtual void update     () = 0;

        void clear      ();
        void display    ();
        void checkForClose();
        bool open       ();

    protected:
        virtual void drawPlayer () = 0;
        virtual void drawWall   ( Wall& wall, int index ) = 0;

        void drawLine ( const sf::Vector2f& start, const sf::Vector2f& end, sf::Color c = sf::Color::White );

        Player player;

        sf::RenderWindow window;

        std::vector<Wall>       walls;
        std::vector<sf::Color>  colors;

        static constexpr int    gap = 5,
                                WIDTH  = 630,
                                HEIGHT = 480;
        static int currPos;

        constexpr static float playerStartX =  WIDTH  / 2,
                               playerStartY =  HEIGHT / 2;

};

#endif // VIEW_BASE_H
