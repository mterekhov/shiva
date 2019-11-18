#ifndef SPCSHIVA_SDRAWAPI_H
#define SPCSHIVA_SDRAWAPI_H

//=============================================================================

#include "shivatypes.h"
#include "scolor.h"
#include "spoint2d.h"
#include "spoint.h"

//=============================================================================

namespace spcShiva
{

//==============================================================================

class SDrawAPI
{
public:
    SDrawAPI();
    virtual ~SDrawAPI();
    
    virtual void currentColor(const SColor& color);
    virtual SColor currentColor();
    virtual SFloat viewportHeight();
    virtual SFloat viewportWidth();
    
    virtual void setupViewport(const SFloat width, const SFloat height);
    virtual void setupIsometricProjection();
    virtual void setupOthoProjection();
    
    virtual void pushMatrices();
    virtual void popMatrices();
    virtual void multMatrices(SFloat *matrix);
    virtual void translate(const SPoint& point);

    virtual void clearScreen();
    virtual void drawPoints(const SFloat *points, const SInt pointsCount);
    virtual void drawLine2D(const SPoint2D& p1, const SPoint2D& p2);
    virtual void drawLine(const SPoint& p1, const SPoint& p2);
};

//=============================================================================

}   //  namespace spcShiva

//==============================================================================

#endif  //  SPCSHIVA_SDRAWAPI_H
