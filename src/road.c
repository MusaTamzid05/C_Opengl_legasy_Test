#include "road.h"
#include "const.h"

#include <stdio.h>
#include <stdlib.h>
#include "vertex.h"

#include "move_data.h"

Shape* create_road() {

    ShapeData* shape_data = create_shape_data(RoadCube , 12 , create_vector(0.0f , 0.0f , 0.0f));

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


}
