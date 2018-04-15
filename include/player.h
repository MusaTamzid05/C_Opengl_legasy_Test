#ifndef PLAYER_H
#define PLAYER_H

#include "shape.h"


Shape* create_player();
void update_player(Shape* shape , unsigned char key);


// this tool are for debuging perpose only.


void debug_angle(Shape* shape , unsigned char key);

#endif
