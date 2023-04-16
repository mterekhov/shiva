#ifndef SPCSHIVA_SISHIVAENGINE_H
#define SPCSHIVA_SISHIVAENGINE_H

#include "sicitrai.h"

namespace spcShiva {

/// Main engine object
class SIShivaEngine {
private:
    SICitraI *citra;
    
public:
    SIShivaEngine(SICitraI* citra);
    ~SIShivaEngine();

};

};  //  namespace spcShiva

#endif  //  SPCSHIVA_SISHIVAENGINE_H
