#include "color.h"

Color::Color(const double c): 
    r(c),g(c),b(c) {} 

Color::Color(const double red, const double green, const double blue): 
    r(red),g(green),b(blue) {} 

bool Color::operator==(const Color& rhs) {
    return this->r == rhs.r &&
           this->g == rhs.g &&
           this->b == rhs.b;
}

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

Color& Color::operator*(const double d) {
    this->r*=d;
    this->g*=d;
    this->b*=d;
    return *this;
}

