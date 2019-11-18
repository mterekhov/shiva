#include "srenderservice.h"
#include "sopenglapi.h"
#include "scolor.h"
#include "spoint.h"
#include <math.h>

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
    
    installCamera(SVector(5,5,5), SVector(), SVector(0,1,0));
    drawGrid(50, 50, 1);
    
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

void SRenderService::drawGrid(const SFloat rowsNumber, const SFloat columnsNumber, const SFloat scale)
{
    const SColor& color = drawAPI->currentColor();
    
    drawAPI->currentColor(SColor::whiteColor());
    for (SFloat i = -rowsNumber; i < rowsNumber; i+= 1.0f)
    {
        drawAPI->drawLine(SPoint(-rowsNumber * scale, 0.0f, i * scale), SPoint(rowsNumber * scale, 0.0f, i * scale));
    }
    
    for (SFloat i = -columnsNumber; i < columnsNumber; i+= 1.0f)
    {
        drawAPI->drawLine(SPoint(i * scale, 0.0f, -columnsNumber * scale), SPoint(i * scale, 0.0f, columnsNumber * scale));
    }
    
    drawAPI->currentColor(color);
}

//==============================================================================

void SRenderService::installCamera(const SVector& eyePosition3D, const SVector& center3D, const SVector& upVector3D)
{
    SFloat m[16] = {0.0f};
    SFloat x[3] = {0.0f};
    SFloat y[3] = {0.0f};
    SFloat z[3] = {0.0f};
    SFloat mag = 0.0f;
    
    /* Make rotation matrix */
    
    /* Z vector */
    z[0] = eyePosition3D.x - center3D.x;
    z[1] = eyePosition3D.y - center3D.y;
    z[2] = eyePosition3D.z - center3D.z;
    mag = sqrtf(z[0] * z[0] + z[1] * z[1] + z[2] * z[2]);
    if (mag) {          /* mpichler, 19950515 */
        z[0] /= mag;
        z[1] /= mag;
        z[2] /= mag;
    }
    
    /* Y vector */
    y[0] = upVector3D.x;
    y[1] = upVector3D.y;
    y[2] = upVector3D.z;
    
    /* X vector = Y cross Z */
    x[0] = y[1] * z[2] - y[2] * z[1];
    x[1] = -y[0] * z[2] + y[2] * z[0];
    x[2] = y[0] * z[1] - y[1] * z[0];
    
    /* Recompute Y = Z cross X */
    y[0] = z[1] * x[2] - z[2] * x[1];
    y[1] = -z[0] * x[2] + z[2] * x[0];
    y[2] = z[0] * x[1] - z[1] * x[0];
    
    /* mpichler, 19950515 */
    /* cross product gives area of parallelogram, which is < 1.0 for
     * non-perpendicular unit-length vectors; so normalize x, y here
     */
    
    mag = sqrtf(x[0] * x[0] + x[1] * x[1] + x[2] * x[2]);
    if (mag) {
        x[0] /= mag;
        x[1] /= mag;
        x[2] /= mag;
    }
    
    mag = sqrt(y[0] * y[0] + y[1] * y[1] + y[2] * y[2]);
    if (mag) {
        y[0] /= mag;
        y[1] /= mag;
        y[2] /= mag;
    }
    
    m[0] = x[0];
    m[4] = x[1];
    m[8] = x[2];
    m[1] = y[0];
    m[5] = y[1];
    m[9] = y[2];
    m[2] = z[0];
    m[6] = z[1];
    m[10] = z[2];
    m[15] = 1.0f;

    drawAPI->multMatrices(m);
    
    /* Translate Eye to Origin */
    drawAPI->translate(SPoint(-eyePosition3D.x, -eyePosition3D.y, -eyePosition3D.z));
}
    
//==============================================================================

}
