#include "const.h"



// Player boundaries.
const int PLAYER_INDEX = 0;
const int ROAD_INDEX = 1;
const float PLAYER_SCREEN_RIGHT =  2.9999;
const float PLAYER_SCREEN_LEFT =  -2.9999;
const float PLAYER_GROUND_LIMIT = -1.4f;
const float PLAYER_SKY_LIMIT = 1.4f;
const float PLAYER_Z_AXIS_VALUS = 3.0f;
// Player Force


const float PLAYER_GRAVITY = -0.01f;
const float PLAYER_FRICTION = 0.001f;;
const float PLAYER_JUMP_FORCE_Y_AXIS = 0.2f;

// player speed



const float SPEED_X_AXIS = 0.1f;
const float SPEED_Y_AXIS = 0.1f;

const float SPEED_X_AXIS_MAX = 0.35;
const float SPEED_X_AXIS_MIN = -0.35;


//************* Road Data ************/

const float ROAD_ANGLE = -53.0f;
const float ROAD_X_AXIS_LEFT_LIMIT = -4.0f;
const float ROAD_X_AXIS_RIGHT_LIMIT = 4.0f;

const int ROAD_RECT_COUNT = 96; 
const int ROAD_COL_COUNT = 8; 

const float ROAD_Y_AXIS_TOP = 9.0f;
const float ROAD_Y_AXIS_BOTTOM = -3.0f;

const float ROAD_RECT_SPEED = 0.1f; 


// Road Objects.

const int NO_OBJECT = -1; 

const float OBJECT_SIZE = 0.4; 

const float  PLAYER_COLLITION_RANGE = 1.f;

const float DANGER_OBJECT_COLOR_RED = 1.0;
const float DANGER_OBJECT_COLOR_GREEN = 0.0;
const float DANGER_OBJECT_COLOR_BLUE = 0.4;

const int SPHERE_OBJECT = 1; 

const int CUBE_OBJECT = 2; 
const int CONE_OBJECT = 3; 
const int DANGER_SPHERE_OBJECT = 4; 
const int DANGER_CUBE_OBJECT = 5; 
const int DANGER_CONE_OBJECT = 6 ; 


const float OBJECT_RECT_POSSIBILITY = 9.0 ;
const float OBJECT_X_DIFF = 0.5f;
const float OBJECT_Y_DIFF = -1.0f;
const float OBJECT_Z_DIFF = 0.5f;


const int MAX_ANGLE_INCREMENTER = 5 ;
const int MIN_ANGLE_INCREMENTER = 1;
// keyboard

//  Keyboard.
const int SPACEBAR = 32;


// Scores

const int SPHERE_SCORE = 10;
const int CUBE_SCORE = 15;
const int CONE_SCORE = 20;


// state indexs

const int MENU_STATE_INDEX = 0;
const int GAME_STATE_INDEX = 1;


// Game State.

const int SCORING_GAME_STATE_INDEX = 3;
