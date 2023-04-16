#ifndef SPCSHIVA_SIPOINT2D_H
#define SPCSHIVA_SIPOINT2D_H

#include "shivatypes.h"

namespace spcShiva {

class SIPoint2D {
private:
    SFloat x;
    SFloat y;

public:
    SIPoint2D();
    SIPoint2D(const SFloat x, const SFloat y);
    SIPoint2D(const SIPoint2D& point);

};

};  //  namespace spcShiva

#endif  //  SPCSHIVA_SIPOINT2D_H
