#pragma once

#include <ostream>

template<size_t Size> class Tuple {
    protected:
        double data[Size];
    
    public:
        Tuple<Size>() = default;
        Tuple<Size>(double data[Size]);

        bool operator ==(const Tuple<Size>& tup) const;
        double operator[](size_t i) const;
        friend std::ostream& operator<<(std::ostream& stream, const Tuple<Size>& tup); //print Tuple 
};

