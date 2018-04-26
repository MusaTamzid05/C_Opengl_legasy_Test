#include "road_rect.h"
#include <stdlib.h>
#include "const.h"
#include <stdio.h>
#include "vertex.h"


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

        if(color_index == 0)
            printf("white\t");

        else if(color_index == 1)
            printf("red.\t");

        road_rects[road_index] = create_road_rect(i , i+ increment , top , bottom , colors[color_index]);
        
        color_index = (color_index + 1 ) % 2;
        road_index++;
    }

    printf("%\n");

    return road_rects;
}


RoadRect** create_whole_road( float left , float right ,float top , float bottom , float row_increment , Vector3** colors) {



    printf("Top : %f\n" , top);
    printf("Bottom: %f\n" , bottom);


    int row_index = 1;
    int rect_index = 0;
    float i;

    RoadRect** road_rects = (RoadRect**)malloc(sizeof(RoadRect) * 96);
    
    for(i = top ; i > bottom ; i -=  row_increment ) {
      
        printf("row_index : %d , left : %f , right : %f, top : %f , bottom : %f\n" , row_index , left , right , i , i - row_increment);
        RoadRect** row_road = create_road_row(row_index , left , right , i , i - row_increment , 1.0 ,  colors);
        
        int col = 0;

        for(col = 0 ; col <  ROAD_COL_COUNT ; col++) {

            road_rects[rect_index] = row_road[col];
            rect_index += 1;
        }

        row_index++;

    }

    return road_rects;
}
