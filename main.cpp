#include <SFML/Graphics.hpp>

#include "View_Base.h"
#include "Normal.h"
#include "Transform_View.h"
#include "Perspective_View.h"

bool updateView ( View_Base& view );

int main()
{
    Normal            normalView;
    Transform_View    transformView;
    Perspective_View  perspectiveView;

    while ( true )
    {
        if ( !updateView( normalView        ) ) break;
        if ( !updateView( transformView     ) ) break;
        if ( !updateView( perspectiveView   ) ) break;
    }
}

bool updateView ( View_Base& view )
{
    view.clear();
    view.input();
    view.update();
    view.draw();
    view.display();
    view.checkForClose();

    return ( view.open() );
}
