#include "../../include/tuple.h"

//print tuple content
template <size_t Size>
std::ostream &operator<<(std::ostream &stream, const Tuple<Size> &tup) {
  stream << '(';
  for (int i = 0; i < Size; i++) {
    stream << tup.data[i] << " ,";
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
double Tuple<Size>::operator[](size_t i) const {
    return data[i];
}


