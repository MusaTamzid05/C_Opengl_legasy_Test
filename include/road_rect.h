#ifndef ROAD_RECT_H
#define ROAD_RECT_H

typedef struct RoadRect {

    float left;
    float right;
    float top;
    float bottom;

} RoadRect;

RoadRect* create_road_rect(float left , float right , float top , float bottom);

RoadRect** create_road_row(float left , float right ,float top , float bottom , float increment );

#endif
