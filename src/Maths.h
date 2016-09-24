#ifndef MATHS_H_INCLUDED
#define MATHS_H_INCLUDED

#include <cmath>
#include <SFML/Graphics.hpp>

namespace Maths
{

constexpr float PI = 3.14159265359;

template <typename T>
T toRadians ( T angle )
{
    return angle * ( PI / 180 );
}

template <typename T>
T sin ( T value )
{
    return std::sin( toRadians( value ) );
}

template <typename T>
T cos ( T value )
{
    return std::cos( toRadians( value ) );
}

template <typename T>
T asin ( T value )
{
    return std::asin( toRadians( value ) );
}

template <typename T>
T acos ( T value )
{
    return std::acos( toRadians( value ) );
}

}

#endif // MATHS_H_INCLUDED
