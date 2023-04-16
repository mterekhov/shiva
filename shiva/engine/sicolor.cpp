#include "sicolor.h"

namespace spcShiva {

SIColor::SIColor() : red(0), green(0), blue(0), alpha(1) {
}

SIColor::SIColor(const SIColor& color) : red(color.red), green(color.green), blue(color.blue), alpha(color.alpha) {
}

SIColor::SIColor(const SFloat red, const SFloat green, const SFloat blue, const SFloat alpha) : red(red), green(green), blue(blue), alpha(alpha) {
}

};  //  namespace spcShiva
