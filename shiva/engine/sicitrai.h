#ifndef SPCSHIVA_SICITRAI_H
#define SPCSHIVA_SICITRAI_H

#include "sicolor.h"
#include "sipoint2d.h"

namespace spcShiva {

/// Canvas interface. It implements basic draw functionality
class SICitraI {
public:

    //  Draw a pixel
    virtual void colorPixel(const SIPoint2D& point, const SIColor& color) = 0;
};

};  //  namespace spcShiva

#endif  //  SPCSHIVA_SICITRAI_H
