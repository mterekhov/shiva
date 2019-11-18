#ifndef SPCSHIVA_SDRAWAPI_H
#define SPCSHIVA_SDRAWAPI_H

//=============================================================================

#include "shivatypes.h"
#include "scolor.h"
#include "spoint2d.h"

//=============================================================================

namespace spcShiva
{

//==============================================================================

class SDrawAPI
{
public:
    SDrawAPI();
    virtual ~SDrawAPI();
    
    virtual SFloat viewportHeight();
    virtual SFloat viewportWidth();
    virtual void setupViewport(const SFloat width, const SFloat height);
    virtual void setupIsometricProjection();
    virtual void setupOthoProjection();
    
    virtual void currentColor(const SColor& color);
    virtual SColor currentColor();
    virtual void pushMatrices();
    virtual void popMatrices();
    virtual void clearScreen();
    virtual void drawPoints(const SFloat *points, const SInt pointsCount);
    virtual void drawLine2D(const SPoint2D& p1, const SPoint2D& p2);
};

//=============================================================================

}   //  namespace spcShiva

//==============================================================================

#endif  //  SPCSHIVA_SDRAWAPI_H
