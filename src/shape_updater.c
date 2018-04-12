#include "shape_updater.h"
#include <stdio.h>

void update1(Shape* shape , unsigned char key) {


    printf("Current key %c\n" , key);

    if(key == 'a')
        shape->translation->x -= 0.01;
    else if(key == 'd')
        shape->translation->x += 0.01;
}

void update2(Shape* shape , unsigned char key) {


    if(key == 'h')
        shape->translation->x -= 0.01;
    else if(key == 'j')
        shape->translation->x += 0.01;
}




