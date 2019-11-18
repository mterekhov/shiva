#include "srenderservice.h"
#include "sopenglapi.h"
#include "scolor.h"
#include "spoint.h"

//==============================================================================

namespace spcShiva
{

//==============================================================================

SRenderService::SRenderService() : drawAPI(new SOpenGLAPI())
{
}

//==============================================================================

SRenderService::~SRenderService()
{
    delete drawAPI;
}

//==============================================================================

void SRenderService::renderGraph() {
    drawAPI->pushMatrices();
    drawAPI->setupIsometricProjection();
    drawAPI->clearScreen();
    drawAPI->popMatrices();

    drawAPI->pushMatrices();
    drawAPI->setupOthoProjection();
    
    drawGrid2D(50, 50, 5);
    
    drawAPI->popMatrices();
}

//==============================================================================

void SRenderService::setupViewport(const SFloat width, const SFloat height) {
    drawAPI->setupViewport(width, height);
}

//==============================================================================

void SRenderService::drawGrid2D(const SFloat rowsNumber, const SFloat columnsNumber, const SFloat scale)
{
    const SColor& color = drawAPI->currentColor();
    
    drawAPI->currentColor(SColor::whiteColor());
    for (SFloat i = -rowsNumber; i < rowsNumber; i+= 1.0f)
    {
        drawAPI->drawLine2D(SPoint2D(-rowsNumber * scale, i * scale), SPoint2D(rowsNumber * scale, i * scale));
    }
    
    for (SFloat i = -columnsNumber; i < columnsNumber; i+= 1.0f)
    {
        drawAPI->drawLine2D(SPoint2D(i * scale, -columnsNumber * scale), SPoint2D(i * scale, columnsNumber * scale));
    }
    
    drawAPI->currentColor(color);
}

//==============================================================================

}
