#ifndef SPCSHIVA_SRENDERSERVICE_H
#define SPCSHIVA_SRENDERSERVICE_H

//=============================================================================

#include "sdrawapi.h"

//=============================================================================

namespace spcShiva
{
    
//==============================================================================

class SRenderService
{
private:
    SDrawAPI *drawAPI;
    void drawGrid2D(const SFloat rowsNumber, const SFloat columnsNumber, const SFloat scale);

public:
    SRenderService();
    ~SRenderService();
    
    void renderGraph();
    void setupViewport(const SFloat width, const SFloat height);
};

//=============================================================================

}   //  namespace spcShiva

//==============================================================================

#endif  //  SPCSHIVA_SRENDERSERVICE_H
