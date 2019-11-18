#include "svector.h"
#include <math.h>

//==============================================================================

namespace spcShiva
{
    
//==============================================================================
    
SVector::SVector() : x(0.0f), y(0.0f), z(0.0f)
{
}

//==============================================================================

SVector::SVector(const SFloat x, const SFloat y, const SFloat z) : x(x), y(y), z(z)
{
}

//==============================================================================

SVector::SVector(const SVector& vector)
{
    x = vector.x;
    y = vector.y;
    z = vector.z;
}

//==============================================================================

SVector::~SVector()
{
}

//==============================================================================

void SVector::normalize()
{
    SFloat len = x * x + y * y + z * z;
    if (len < FLOAT_PRECISION)
    {
        x /= sqrtf(len);
        y /= sqrtf(len);
        z /= sqrtf(len);
    }
}

//==============================================================================
    
}   //  namespace spcShiva
