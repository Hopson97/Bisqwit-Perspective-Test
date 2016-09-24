#ifndef TRANSFORM_VIEW_H
#define TRANSFORM_VIEW_H

#include <View_Base.h>


class Transform_View : public View_Base
{
    public:
        void update     () override;

    private:
        void drawPlayer () override;
        void drawWall   ( Wall& wall, int index ) override;

};

#endif // TRANSFORM_VIEW_H
