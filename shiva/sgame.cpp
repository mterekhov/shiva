#include "sgame.h"
#include <stdio.h>

namespace spcShiva
{
    
//==============================================================================

SGame::SGame()
{
}

//==============================================================================

SGame::~SGame()
{
}

//==============================================================================

void SGame::updateScreenSize(const SFloat screenWidth, const SFloat screenHeight)
{
    renderService.setupViewport(screenWidth, screenHeight);
}

//==============================================================================

void SGame::processGameCycle()
{
    renderService.renderGraph();
}

//==============================================================================

void SGame::processKeyboardEvent(const SUInt buttonCode)
{
}

//==============================================================================

void SGame::processMouseEvent(const SFloat x, const SFloat y)
{
}

//==============================================================================

}
