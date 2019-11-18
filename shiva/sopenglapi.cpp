#include "sopenglapi.h"
#include <OpenGL/gl.h>
#include <math.h>
#include "shivatools.h"

//==============================================================================

namespace spcShiva
{

//==============================================================================

SOpenGLAPI::SOpenGLAPI()
{
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnableClientState(GL_VERTEX_ARRAY);
}
    
//==============================================================================

SOpenGLAPI::~SOpenGLAPI()
{
    
}

//==============================================================================
    
void SOpenGLAPI::setupViewport(const SFloat width, const SFloat height)
{
    glViewport(0.0f, 0.0f, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, width, 0.0f, height, 1.0f, -1.0f);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
    
//==============================================================================

void SOpenGLAPI::clearScreen()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

//==============================================================================
    
void SOpenGLAPI::setupOthoProjection()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    glOrtho(0.0f, viewportWidth(), 0.0f, viewportHeight(), 1.0f, -1.0f);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

//==============================================================================
    
SFloat SOpenGLAPI::viewportWidth()
{
    GLfloat viewportSizeArray[4] = {0};
    glGetFloatv(GL_VIEWPORT, viewportSizeArray);
    
    return viewportSizeArray[2];
}

//==============================================================================

SFloat SOpenGLAPI::viewportHeight()
{
    GLfloat viewportSizeArray[4] = {0};
    glGetFloatv(GL_VIEWPORT, viewportSizeArray);
    
    return viewportSizeArray[3];
}

//==============================================================================

void SOpenGLAPI::setupIsometricProjection()
{
    SFloat aspect = viewportWidth() / viewportHeight();
    SFloat near = 0.1f;
    SFloat far = 10000.0f;
    SFloat fieldOfView = 45.0f;
    SFloat size = near * tanf(deg2rad(fieldOfView) / 2.0f);
    SFloat width = size;
    SFloat height = size / aspect;
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    glFrustum(-width, width, -height, height, near, far);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
    
//==============================================================================

void SOpenGLAPI::pushMatrices()
{
    glPushMatrix();
}

//==============================================================================

void SOpenGLAPI::popMatrices()
{
    glPopMatrix();
}

//==============================================================================

SColor SOpenGLAPI::currentColor()
{
    GLfloat colorComponents[4] = {0};
    glGetFloatv(GL_CURRENT_COLOR, colorComponents);
    SColor color = SColor(colorComponents[0], colorComponents[1], colorComponents[2], colorComponents[3]);
    
    return color;
}
    
//==============================================================================

void SOpenGLAPI::currentColor(const SColor& color)
{
    glColor4f(color.red, color.green, color.blue, color.alpha);
}
    
//==============================================================================
    
void SOpenGLAPI::drawLine2D(const SPoint2D& p1, const SPoint2D& p2)
{
    SFloat line[4] = {0};
    line[0] = p1.x;
    line[1] = p1.y;
    line[2] = p2.x;
    line[3] = p2.y;
    glVertexPointer(2, GL_FLOAT, 0, line);
    glDrawArrays(GL_LINES, 0, 2);
}

//==============================================================================

void SOpenGLAPI::drawLine(const SPoint& p1, const SPoint& p2)
{
    SFloat line[6] = {0};
    line[0] = p1.x;
    line[1] = p1.y;
    line[2] = p1.z;
    line[3] = p2.x;
    line[4] = p2.y;
    line[5] = p2.z;
    glVertexPointer(3, GL_FLOAT, 0, line);
    glDrawArrays(GL_LINES, 0, 2);
}
    
//==============================================================================

void SOpenGLAPI::drawPoints(const SFloat *points, const SInt pointsCount)
{
    glVertexPointer(2, GL_FLOAT, 0, points);
    glDrawArrays(GL_POINTS, 0, pointsCount);
}

//==============================================================================

void SOpenGLAPI::multMatrices(SFloat *matrix)
{
    glMultMatrixf(matrix);
}

//==============================================================================

void SOpenGLAPI::translate(const SPoint& point)
{
    glTranslatef(point.x, point.y, point.z);
}

//==============================================================================

}
