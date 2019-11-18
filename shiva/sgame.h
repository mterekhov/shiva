#ifndef SPCSHIVA_SGAME_H
#define SPCSHIVA_SGAME_H

//=============================================================================

#include "shivatypes.h"
#include "srenderservice.h"

//=============================================================================

namespace spcShiva
{
    
//==============================================================================

class SGame
{
private:
    SRenderService renderService;
    
public:
    SGame();
    ~SGame();

    virtual void updateScreenSize(const SFloat screenWidth, const SFloat screenHeight);
    virtual void processGameCycle();
    virtual void processKeyboardEvent(const SUInt buttonCode);
    virtual void processMouseEvent(const SFloat x, const SFloat y);
};

//=============================================================================

}   //  namespace spcShiva

//==============================================================================

#endif  //  SPCSHIVA_SGAME_H
