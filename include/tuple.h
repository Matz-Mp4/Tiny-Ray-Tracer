#pragma once
#include <ostream>

template<size_t Size> class Tuple{
    protected:
        double data[Size];
    
    public:
        Tuple() = default;
        ~Tuple() = default;

        Tuple(double t);
        Tuple(double data[Size]);
        
        bool operator==(const Tuple<Size>& tup) const;
        double operator[](int i) const;

        template<size_t size>
        friend std::ostream& operator<<(std::ostream& stream, const Tuple<size>& tup); //print Tuple 
                                                                                       
};

template <size_t Size>
Tuple<Size>::Tuple(double t) {
    for(int i = 0; i < Size; i++)
        data[i] = t;
}

template <size_t Size>
Tuple<Size>::Tuple(double tup[Size]) {
    for(int i = 0; i < Size; i++)
        data[i] = tup[i];
}

template <size_t Size>
std::ostream &operator<<(std::ostream &stream, const Tuple<Size> &tup) {
  stream << '(';
  for (int i = 0; i < Size; i++) {
    stream << tup.data[i] << ",";
  }
  stream << "\b\b) ";
  return stream;
}

template <size_t Size>
bool Tuple<Size>::operator==(const Tuple<Size>& tup) const {
    int i = 0;

    while(i <= Size) {
        if (tup.data[i] != data[i]) return false;
        i++;
    }
    return true;
}

template <size_t Size>
double Tuple<Size>::operator[](int i) const {

    if (i < Size)
        return data[i];
    else
        throw std::out_of_range("Error: Attempted to acess out of range element\n");
}

