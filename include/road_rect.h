#ifndef ROAD_RECT_H
#define ROAD_RECT_H

#include "vertex.h"
#include "road_object.h"

int random_road_object_shape();

typedef struct RoadRect {

    float left;
    float right;
    float top;
    float bottom;
    Vector3* color;

    int object_index;

    RoadObject* road_object;

} RoadRect;

RoadRect* create_road_rect(float left , float right , float top , float bottom , Vector3* color );

RoadRect** create_road_row(int row, float left , float right ,float top , float bottom , float increment , Vector3** colors);
RoadRect** create_whole_road( float left , float right ,float top , float bottom , float row_increment , Vector3** colors);

void  create_random_road_object(RoadRect* road_rect);
#endif
