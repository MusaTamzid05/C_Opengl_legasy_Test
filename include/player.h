#ifndef PLAYER_H
#define PLAYER_H

#include "shape.h"
#include "move_data.h"

Shape* create_player();
MoveData*  create_player_move_data();

void update_player(Shape* shape , unsigned char key);
void handle_keyboard(Shape* shape , unsigned char key);
void limit_bound(Shape* shape);

void handle_jump(Shape* shape);

void update_movement_data(Shape* shape);
void apply_force_to_player(Shape* shape , Vector3* force);
void apply_friction_to_player(Shape* shape);

// this tool are for debuging perpose only.


void debug_angle(Shape* shape , unsigned char key);

#endif
