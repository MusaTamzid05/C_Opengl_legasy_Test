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


extern const float SPEED_Y_AXIS_MAX;
extern const float SPEED_Y_AXIS_MIN;



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


extern const float  PLAYER_COLLITION_RANGE;

extern const float DANGER_OBJECT_COLOR_RED;
extern const float DANGER_OBJECT_COLOR_GREEN;
extern const float DANGER_OBJECT_COLOR_BLUE;

extern const float OBJECT_SIZE; 

extern const int NO_OBJECT; 

extern const int SPHERE_OBJECT; 
extern const int CUBE_OBJECT; 
extern const int CONE_OBJECT; 
extern const int DANGER_SPHERE_OBJECT; 
extern const int DANGER_CUBE_OBJECT; 
extern const int DANGER_CONE_OBJECT; 

extern const float OBJECT_RECT_POSSIBILITY;
extern const float OBJECT_X_DIFF;
extern const float OBJECT_Y_DIFF;
extern const float OBJECT_Z_DIFF;


extern const int MAX_ANGLE_INCREMENTER;
extern const int MIN_ANGLE_INCREMENTER;
// keyboard
extern const int SPACEBAR;

// Scores

extern const int SPHERE_SCORE;
extern const int CUBE_SCORE;
extern const int CONE_SCORE;

// state indexs


extern const int NEW_GAME_STATE;
extern const int MENU_STATE_INDEX;
extern const int GAME_STATE_INDEX;
extern const int PAUSE_STATE_INDEX;
extern const int GAME_OVER_STATE_INDEX;

// Menu State.

extern const int MENU_STATE_START_INDEX;
extern const int MENU_STATE_EXIT_INDEX;

// Game State.
extern const int SCORING_GAME_STATE_INDEX;
extern const int ROAD_GAME_STATE_INDEX;

// Pause State

extern const int PAUSE_STATE_LEFT;
extern const int PAUSE_STATE_RIGHT;
extern const int PAUSE_STATE_TOP;
extern const int PAUSE_STATE_BOTTOM;

extern const int PAUSE_STATE_GAME_PAUSE_TEXT;
extern const int PAUSE_STATE_SCORE_TEXT;
extern const int PAUSE_STATE_CONTINUE_TEXT;
extern const int PAUSE_STATE_QUIT_TEXT;

// Game Over states


extern const int GAME_OVER_STATE_SCORE_TEXT;
extern const int GAME_OVER_STATE_NEW_GAME_TEXT;
extern const int GAME_OVER_STATE_EXIT_TEXT;


#endif
