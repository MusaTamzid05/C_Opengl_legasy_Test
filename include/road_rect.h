#ifndef ROAD_RECT_H
#define ROAD_RECT_H

#include "vertex.h"

typedef struct RoadRect {

    float left;
    float right;
    float top;
    float bottom;
    Vector3* color;

} RoadRect;

RoadRect* create_road_rect(float left , float right , float top , float bottom , Vector3* color);

RoadRect** create_road_row(int row, float left , float right ,float top , float bottom , float increment , Vector3** colors);

#endif
