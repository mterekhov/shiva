#ifndef SPCSHIVA_SPOINT2D_H
#define SPCSHIVA_SPOINT2D_H

//==============================================================================

#include <vector>

#include "shivatypes.h"

//==============================================================================

namespace spcShiva
{
    
//==============================================================================
    
class SPoint2D
{
public:
    SPoint2D();
    SPoint2D(const SFloat x, const SFloat y);
    SPoint2D(const SPoint2D& point);
    ~SPoint2D();

    SFloat x;
    SFloat y;
};

//==============================================================================

typedef std::vector<SPoint2D> TPoints2DList;

//==============================================================================

}   //  namespace spcShiva

//==============================================================================
    
#endif  //  SPCSHIVA_SPOINT2D_H
