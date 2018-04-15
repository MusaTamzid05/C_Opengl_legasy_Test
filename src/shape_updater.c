#include "shape_updater.h"
#include <stdio.h>

void update1(Shape* shape , unsigned char key) {


    printf("Current Player angle => %f.\n" ,shape->angle);


    if(key == 'a')
        shape->angle  += 1.0f;
    else if(key == 'd')
        shape->angle  -= 1.0f;
}

void update2(Shape* shape , unsigned char key) {


    if(key == 'h')
        shape->translation->x -= 0.01;
    else if(key == 'j')
        shape->translation->x += 0.01;
}




