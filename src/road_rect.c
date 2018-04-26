#include "road_rect.h"
#include <stdlib.h>


RoadRect* create_road_rect(float left , float right , float top , float bottom, Vector3* color) {

    RoadRect* road_rect = (RoadRect*)malloc(sizeof(RoadRect));

    road_rect->left = left;
    road_rect->right = right;
    road_rect->top = top;
    road_rect->bottom = bottom;
    road_rect->color = color;

    return road_rect;
}


RoadRect** create_road_row(int row , float left , float right ,float top , float bottom , float increment ,  Vector3** colors) {

    int color_index;

    if(row % 2 == 0)
        color_index = 0;
    else
        color_index = 1;


    float total = (right - left) / increment;

    RoadRect** road_rects = (RoadRect**)malloc(sizeof(RoadRect) * total);

    float i;
    int road_index = 0;

    for(i = left ; i < right; i += increment) {
        road_rects[road_index] = create_road_rect(i , i+ increment , top , bottom , colors[color_index]);

        color_index = (color_index + 1 ) % 2;
        road_index++;
    }

    return road_rects;
}
