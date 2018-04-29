#include "road.h"
#include "const.h"

#include <stdio.h>
#include <stdlib.h>
#include "vertex.h"

#include "move_data.h"
#include "drawer.h"


Vector3** create_road_colors() {

    Vector3** colors = (Vector3**)malloc(sizeof(Vector3)* 2);

    colors[0] = create_vector(1.0 , 0.0 , 0.0);
    colors[1] = create_vector(1.0 , 1.0 , 1.0);

    return colors;
}


Shape* create_road() {

    ShapeData* shape_data = create_shape_data(RoadCube , 12 , create_vector(1.0f , 1.0f , 1.0f));

    Vector3* translation = create_vector(0.0f , 0.0f , 0.0f);
    Vector3* rotation = create_vector(1.0f , 0.0f , 0.0f);
    float angle = ROAD_ANGLE; 
    MoveData* move_data  = NULL; // could be fixed latter for better motion.


    Shape* road = create_shape(shape_data , translation , rotation , angle , move_data);
    Vector3** colors = create_road_colors();

    road_rects  = create_whole_road(ROAD_X_AXIS_LEFT_LIMIT , ROAD_X_AXIS_RIGHT_LIMIT , ROAD_Y_AXIS_TOP , -3.0f , 1.0f ,  colors);
    
    //road_rects = create_road_row(1 , ROAD_X_AXIS_LEFT_LIMIT , ROAD_X_AXIS_RIGHT_LIMIT , -3.0 , -2.0 , 1.0f , colors);

    return road;

}


void update_road(Shape* shape ,unsigned char key) {


    for(int i = 0 ; i < ROAD_RECT_COUNT; i++) {

        /*
        if(road_rects[i]->top <= ROAD_Y_AXIS_BOTTOM){

            road_rects[i]->top = ROAD_Y_AXIS_TOP;
            road_rects[i]->bottom = ROAD_Y_AXIS_TOP - 1.0f;
        }

        road_rects[i]->top -= ROAD_RECT_SPEED;
        road_rects[i]->bottom -= ROAD_RECT_SPEED;
        */

        
        if(road_rects[i]->road_object != NULL) 
            road_rects[i]->road_object->angle += road_rects[i]->road_object->angle_incrementer; 

    }



}

void draw_road(Shape* shape ) {

    for(int i = 0 ; i < ROAD_RECT_COUNT; i++) {
        

        if(road_rects[i]->road_object != NULL)
            draw_road_obect(road_rects[i]->left + OBJECT_X_DIFF , road_rects[i]->top +  OBJECT_Y_DIFF , OBJECT_Z_DIFF , road_rects[i]->object_index ,road_rects[i]->road_object) ;
        else
            draw_road_obect(road_rects[i]->left + OBJECT_X_DIFF , road_rects[i]->top +  OBJECT_Y_DIFF , OBJECT_Z_DIFF , road_rects[i]->object_index , NULL);

        draw_rect(road_rects[i]->left , road_rects[i]->right , road_rects[i]->top , road_rects[i]->bottom , road_rects[i]->color );
    }



}
