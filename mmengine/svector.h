#ifndef SPCSHIVA_SVECTOR_H
#define SPCSHIVA_SVECTOR_H

//==============================================================================

#include "shivatypes.h"

//==============================================================================

namespace spcShiva
{
    
//==============================================================================
    
class SVector
{
public:
    SVector();
    SVector(const SFloat x, const SFloat y, const SFloat z);
    SVector(const SVector& vector);
    ~SVector();
    
    void normalize();

    SFloat x;
    SFloat y;
    SFloat z;
};

//==============================================================================

}   //  namespace spcShiva

//==============================================================================
    
#endif  //  SPCSHIVA_SVECTOR_H
