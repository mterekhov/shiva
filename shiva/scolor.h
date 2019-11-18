#ifndef SPCSHIVA_SCOLOR_H
#define SPCSHIVA_SCOLOR_H

//==============================================================================

#include "shivatypes.h"

//==============================================================================

namespace spcShiva
{
    
//==============================================================================
    
class SColor
{
public:
    static SColor whiteColor();
    static SColor blackColor();
    static SColor redColor();
    static SColor greenColor();
    static SColor blueColor();

    SColor();
    SColor(const SFloat _red, const SFloat _green, const SFloat _blue, const SFloat _alpha);
    SColor(const SColor& color);
    ~SColor();

    SFloat red;
    SFloat green;
    SFloat blue;
    SFloat alpha;
};

//==============================================================================

}   //  namespace spcShiva

//==============================================================================
    
#endif  //  SPCSHIVA_SCOLOR_H
