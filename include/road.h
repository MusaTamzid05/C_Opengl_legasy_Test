#ifndef ROAD_H
#define ROAD_H


#include "shape.h"

Shape** init_road();

Shape* create_single_road(ShapeData* shape_data , Vector3* translation , Vector3* rotation, float angle , MoveData* move_ );

MoveData* create_single_road_move_data();

void update_single_road(Shape* shape , unsigned char key);


#endif
