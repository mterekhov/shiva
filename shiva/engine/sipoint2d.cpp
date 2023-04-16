#include "sipoint2d.h"

namespace spcShiva {

SIPoint2D::SIPoint2D() : x(0), y(0) {
}

SIPoint2D::SIPoint2D(const SIPoint2D& point) : x(point.x), y(point.y) {
}

SIPoint2D::SIPoint2D(const SFloat x, const SFloat y) : x(x), y(y) {
}

};  //  namespace spcShiva
