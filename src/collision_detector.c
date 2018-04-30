#include "collision_detector.h"
#include <stdio.h>
#include "vertex.h"
#include "const.h"

void collision_detector(Shape* shape , RoadRect** road_rect) {


    int player_ground_index = PLAYER_GROUND_LIMIT;

    // make sure player is in the gound.
    if(shape->translation->y >  player_ground_index)
        return;
    

    int i = 0;

    for(i = 0 ; i < ROAD_RECT_COUNT; i++) {


        if(road_rect[i]->bottom >  ROAD_Y_AXIS_BOTTOM  + PLAYER_COLLITION_RANGE) 
            continue;


        float left_limit = road_rect[i]->left + 2;
        float right_limit = road_rect[i]->right - 2;


        int player_x = (shape->translation->x * 2) ;


        if(player_x < 0)
            player_x += 1;
        else if(player_x > 0)
            player_x -= 1;


        if(player_x >= road_rect[i]->left && player_x <= road_rect[i]->right) {
            if(road_rect[i]->road_object != NULL) {
               
                road_rect[i]->object_index = NO_OBJECT;
                road_rect[i]->road_object = NULL;
            }
        }

    }

}
