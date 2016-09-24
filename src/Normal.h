#ifndef NORMAL_H
#define NORMAL_H

#include "View_Base.h"

/*
    The normal is just regular top down player moves around the world
*/

class Normal : public View_Base
{
    public:
        void update     () override;

    protected:
        void drawPlayer () override;
        void drawWall   ( Wall& wall, int index ) override;
};


#endif // NORMAL_H
