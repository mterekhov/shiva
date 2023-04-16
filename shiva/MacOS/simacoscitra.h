#ifndef SPCSHIVASIMACOSCITRA_H
#define SPCSHIVASIMACOSCITRA_H

#include "sicitrai.h"

namespace spcShiva {

class SIMacOSCitra: public SICitraI {
public:
    SIMacOSCitra();
    virtual ~SIMacOSCitra();
    
    virtual void colorPixel(const SIPoint2D& point, const SIColor& color);
};

};  //  namespace spcShiva

#endif  //  SPCSHIVASIMACOSCITRA_H
