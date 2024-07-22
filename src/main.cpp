#include "../include/math.h"
#include "../include/world.h"
#include <iostream>

int main() {
  World w;
  w.build();
  w.render_scene();

  return 0;
}
