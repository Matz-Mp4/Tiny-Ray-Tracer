#include "../../include/color.h"
#include <cmath>

Color::Color(const double c)
    : r(c),g(c),b(c) {}

Color::Color(const double red, const double green, const double blue)
    : r(red),g(green),b(blue) {} 


Color& Color::operator+(const Color& rhs) {
    this->r+=rhs.r;
    this->g+=rhs.g;
    this->b+=rhs.b;
    return *this;
}

Color& Color::operator-(const Color& rhs) {
    this->r=this->r - rhs.r;
    this->g=this->g - rhs.g;
    this->b=this->b - rhs.b;
    return *this;
}

Color& Color::operator*(const Color& rhs) {
    this->r*=rhs.r;
    this->g*=rhs.g;
    this->b*=rhs.b;
    return *this;
}

Color& Color::operator*(const double rhs) {
    this->r *= rhs;
    this->g *= rhs;
    this->b *= rhs;
    return *this;
}

bool Color::operator==(const Color& rhs) {
    return this->r == rhs.r &&
           this->g == rhs.g &&
           this->b == rhs.b;
}


Color Color::powc(double p) const {
    return Color(pow(r, p), pow(g, p), pow(b, p));
}

