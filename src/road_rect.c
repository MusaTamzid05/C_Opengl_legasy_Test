#include "road_rect.h"
#include <stdlib.h>


RoadRect* create_road_rect(float left , float right , float top , float bottom) {

    RoadRect* road_rect = (RoadRect*)malloc(sizeof(RoadRect));

    road_rect->left = left;
    road_rect->right = right;
    road_rect->top = top;
    road_rect->bottom = bottom;

    return road_rect;
}


RoadRect** create_road_row(float left , float right ,float top , float bottom , float increment ) {


    float total = (right - left) / increment;

    RoadRect** road_rects = (RoadRect**)malloc(sizeof(RoadRect) * total);

    float i;
    int road_index = 0;

    for(i = left ; i <= right; i += increment) {
        road_rects[road_index] = create_road_rect(i , i+ increment , top , bottom);
        road_index++;
    }

    return road_rects;
}
