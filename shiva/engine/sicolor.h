#ifndef SPCSHIVA_SICOLOR_H
#define SPCSHIVA_SICOLOR_H

#include "shivatypes.h"

namespace spcShiva {

class SIColor {
private:
    SFloat red;
    SFloat green;
    SFloat blue;
    SFloat alpha;

public:
    SIColor();
    SIColor(const SFloat red, const SFloat green, const SFloat blue, const SFloat alpha);
    SIColor(const SIColor& color);

};

};  //  namespace spcShiva

#endif  //  SPCSHIVA_SICOLOR_H
