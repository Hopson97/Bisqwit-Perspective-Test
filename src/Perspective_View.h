#ifndef PERSPECTIVE_VIEW_H
#define PERSPECTIVE_VIEW_H

#include <View_Base.h>


class Perspective_View : public View_Base
{
    public:
        void update     () override;

    private:
        void drawPlayer () override;
        void drawWall   ( Wall& wall, int index ) override;

};

#endif // PERSPECTIVE_VIEW_H
