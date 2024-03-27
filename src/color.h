class Color {
public:
    double r,g,b;
    
    Color() = default;
    Color(const double c);
    Color(const double red, const double green, const double blue);

    Color& operator+(const Color &rhs);
    Color& operator-(const Color &rhs);
    Color& operator*(const Color &rhs);
    Color& operator*(const double d);
    bool   operator==(const Color &rhs);

};
