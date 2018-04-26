#include "road.h"
#include "const.h"

#include <stdio.h>
#include <stdlib.h>
#include "vertex.h"

#include "move_data.h"
#include "drawer.h"

Shape* create_road() {

    ShapeData* shape_data = create_shape_data(RoadCube , 12 , create_vector(1.0f , 1.0f , 1.0f));

    Vector3* translation = create_vector(0.0f , 0.0f , 0.0f);
    Vector3* rotation = create_vector(1.0f , 0.0f , 0.0f);
    float angle = ROAD_ANGLE; 
    MoveData* move_data  = NULL; // could be fixed latter for better motion.


    Shape* road = create_shape(shape_data , translation , rotation , angle , move_data);

    road_rects = create_road_row(ROAD_X_AXIS_LEFT_LIMIT , ROAD_X_AXIS_RIGHT_LIMIT , 0.0 , 1.0f , 1.0f);


    for(int i = 0 ; i < 6 ; i++) {

        printf("%d\n" , i + 1);
        printf("left : %f\n" , road_rects[i]->left);
        printf("right: %f\n" , road_rects[i]->right);
        printf("top: %f\n" , road_rects[i]->top);
        printf("Bottom: %f\n" , road_rects[i]->bottom);
    }
    return road;

}


void update_road(Shape* shape ,unsigned char key) {

    if(key == 's')
        shape->angle += 1;


    else if(key == 'w')
        shape->angle -= 1;


}

void draw_road(Shape* shape ) {





    for(int i = 0 ; i < 8 ; i++)
        draw_rect(road_rects[i]->left , road_rects[i]->right , road_rects[i]->top , road_rects[i]->bottom , create_vector(1.0f , 0.0f , 0.0f) );
    //draw_rect(-2.7 , 2.7 , 2.7 , -2.7 , create_vector(0.0f , 0.0f , 1.0f));
    
    


}
