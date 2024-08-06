#include "../include/math.h"
#include "../include/world.h"
#include <iostream>

int main() {
  World w;
  w.build();
  /* w.render_scene(); */
  w.camera_ptr->render_scene(w);
  return 0;
}
