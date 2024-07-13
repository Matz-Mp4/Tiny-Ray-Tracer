#include "../include/tuple.h"
#include <iostream>

int main(){
    /* World w; */
    /* w.build(); */
    /* w.render_scene(); */
    double data[] ={1.0,1.0,1.0,1.0}; 
    Tuple<4> tup(2.0);
    /* Tuple<4> tup2(data); */
    /* bool ver = tup1 == tup2; */
    /* bool ver = tup == tup; */
    std::cout << tup << "\n";
    
    return 0;
}
