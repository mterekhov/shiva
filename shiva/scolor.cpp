#include "scolor.h"

//==============================================================================

namespace spcShiva
{
    
//==============================================================================
    
SColor SColor::blueColor()
{
    return SColor(0.0f, 0.0f, 1.0f, 1.0f);
}

//==============================================================================

SColor SColor::greenColor()
{
    return SColor(0.0f, 1.0f, 0.0f, 1.0f);
}

//==============================================================================

SColor SColor::redColor()
{
    return SColor(1.0f, 0.0f, 0.0f, 1.0f);
}

//==============================================================================

SColor SColor::whiteColor()
{
    return SColor(1.0f, 1.0f, 1.0f, 1.0f);
}

//==============================================================================

SColor SColor::blackColor()
{
    return SColor();
}

//==============================================================================

SColor::SColor() : red(0.0f), green(0.0f), blue(0.0f), alpha(1.0f)
{
}

//==============================================================================

SColor::SColor(const SFloat _red, const SFloat _green, const SFloat _blue, const SFloat _alpha) : red(_red), green(_green), blue(_blue), alpha(_alpha)
{
}

//==============================================================================

SColor::SColor(const SColor& color)
{
    red = color.red;
    green = color.green;
    blue = color.blue;
    alpha = color.alpha;
}

//==============================================================================

SColor::~SColor()
{
}

//==============================================================================
    
}   //  namespace spcShiva
