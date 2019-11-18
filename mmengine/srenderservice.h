#ifndef SPCSHIVA_SRENDERSERVICE_H
#define SPCSHIVA_SRENDERSERVICE_H

//=============================================================================

#include "sdrawapi.h"
#include "svector.h"

//=============================================================================

namespace spcShiva
{
    
//==============================================================================

class SRenderService
{
private:
    SDrawAPI *drawAPI;
    void drawGrid2D(const SFloat rowsNumber, const SFloat columnsNumber, const SFloat scale);
    void drawGrid(const SFloat rowsNumber, const SFloat columnsNumber, const SFloat scale);
    void installCamera(const SVector& eyePosition3D, const SVector& center3D, const SVector& upVector3D);

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
