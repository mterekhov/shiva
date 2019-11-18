#ifndef SPCSHIVA_SPOINT_H
#define SPCSHIVA_SPOINT_H

//==============================================================================

#include <vector>
#include "shivatypes.h"

//==============================================================================

namespace spcShiva
{
    
//==============================================================================
    
class SPoint
{
public:
    SPoint();
    SPoint(const SFloat x, const SFloat y, const SFloat z);
    SPoint(const SPoint& point);
    ~SPoint();

    SFloat x;
    SFloat y;
    SFloat z;
};

//==============================================================================

typedef std::vector<SPoint> TPointsList;

//==============================================================================

}   //  namespace spcShiva

//==============================================================================
    
#endif  //  SPCSHIVA_SPOINT_H
