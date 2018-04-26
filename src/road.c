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
    Vector3* rotation = create_vector(0.0f , 0.0f , 0.0f);
    float angle = 0.0f;
    MoveData* move_data  = NULL; // could be fixed latter for better motion.


    Shape* road = create_shape(shape_data , translation , rotation , angle , move_data);

    return road;

}


void update_road(Shape* shape ,unsigned char key) {


}

void draw_road(Shape* shape ) {

    printf("Drawing the road.\n");


    draw_rect(-2.7 , 2.7 , 2.7 , -2.7 , create_vector(1.0f , 0.0f , 1.0f));
    
    
    glEnd();


}
