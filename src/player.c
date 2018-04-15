#include  "player.h"
#include <stdio.h>

#include "const.h"


Shape* create_player() {



    Vector3* rotation = create_vector(1.0f , 0.0f , 0.0f);
    Vector3* translation = create_vector(-1.0f , -2.3f , 0.0f);
    Vector3* scale = create_vector(0.0f , 0.0f , 0.0f);

    ShapeData* shape_data = create_shape_data(Wire , 0.4, create_vector(0.0f, 0.0f , 1.0f));

    
    return create_shape(shape_data , translation , rotation , 231.0f );


}


void update_player(Shape* shape , unsigned char key) {
   
    handle_keyboard(shape , key);
    limit_bound(shape);

}



void handle_keyboard(Shape* shape , unsigned char key) {

    if(key == 'a')
        shape->translation->x -= SPEED_X_AXIS;

    else if(key == 'd')
        shape->translation->x += SPEED_X_AXIS;

    else if(key == SPACEBAR)
        handle_jump(shape);

}

void limit_bound(Shape* shape) {



    if(shape->translation->x > PLAYER_SCREEN_RIGHT)
        shape->translation->x = PLAYER_SCREEN_RIGHT;


    else if(shape->translation->x <  PLAYER_SCREEN_LEFT)
        shape->translation->x = PLAYER_SCREEN_LEFT;


}

void handle_jump(Shape* shape) {


    if(shape->translation->y <  PLAYER_HIGHEST_JUMP_LIMIT)
        shape->translation->y +=  SPEED_X_AXIS;
    printf("Player y : %f\n" , shape->translation->y);


}

void debug_angle(Shape* shape , unsigned char key) {

    printf("Current Player angle => %f.\n" ,shape->angle);


    if(key == 'a')
        shape->angle  += 1.0f;
    else if(key == 'd')
        shape->angle  -= 1.0f;
}
