#ifndef CONST_H
#define CONST_H

// array index for using data.
extern const int PLAYER_INDEX;
extern const int ROAD_INDEX;

// player boundaries.

extern const float PLAYER_SCREEN_RIGHT;
extern const float PLAYER_SCREEN_LEFT;

extern const float PLAYER_GROUND_LIMIT;
extern const float PLAYER_SKY_LIMIT;
extern const float PLAYER_Z_AXIS_VALUS;

// Player Force.



extern const float PLAYER_GRAVITY;
extern const float PLAYER_FRICTION;
extern const float PLAYER_JUMP_FORCE_Y_AXIS;

// player speed


extern const float SPEED_X_AXIS;
extern const float SPEED_Y_AXIS;

extern const float SPEED_X_AXIS_MAX;
extern const float SPEED_X_AXIS_MIN;


//************* Road Data ************/

extern const float ROAD_ANGLE;
extern const float ROAD_X_AXIS_LEFT_LIMIT;
extern const float ROAD_X_AXIS_RIGHT_LIMIT;

extern const float ROAD_Y_AXIS_TOP;
extern const float ROAD_Y_AXIS_BOTTOM;

extern const int ROAD_COL_COUNT; 

extern const int ROAD_RECT_COUNT; 
extern const float ROAD_RECT_SPEED; 

// Road Objects.

extern const int NO_OBJECT; 
extern const int SPHERE_OBJECT; 
extern const float OBJECT_X_DIFF;
extern const float OBJECT_Y_DIFF;
extern const float OBJECT_Z_DIFF;

// keyboard
extern const int SPACEBAR;

#endif
