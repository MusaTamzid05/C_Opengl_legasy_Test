#ifndef PLAYER_H
#define PLAYER_H

#include "shape.h"


Shape* create_player();
void update_player(Shape* shape , unsigned char key);
void handle_keyboard(Shape* shape , unsigned char key);
void limit_bound(Shape* shape);

// this tool are for debuging perpose only.


void debug_angle(Shape* shape , unsigned char key);

#endif
