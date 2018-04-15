#include  "player.h"
#include <stdio.h>

#include "const.h"


Shape* create_player() {



    Vector3* rotation = create_vector(1.0f , 0.0f , 0.0f);
    Vector3* translation = create_vector(-1.0f ,  -0.1 , 0.0f);

    ShapeData* shape_data = create_shape_data(Wire , 0.4, create_vector(0.0f, 0.0f , 1.0f));


    MoveData* move_data = create_player_move_data();


    return create_shape(shape_data , translation , rotation , 231.0f  , move_data);


}


MoveData* create_player_move_data() {



    float mass = 1.0f;
    Vector3* velocity = create_vector(0.0f , 0.0f , 0.0f);
    Vector3* acceleration = create_vector(0.0f , 0.0f , 0.0f);

    Vector3* gravity = create_vector(0.0f , -0.01f , 0.0f);

    return create_move_data(velocity , acceleration , gravity , mass);


}


void update_player(Shape* shape , unsigned char key) {



    handle_keyboard(shape , key);
    limit_bound(shape);

    update_movement_data(shape);

}



void handle_keyboard(Shape* shape , unsigned char key) {

    if(key == 'a')
        shape->translation->x -= SPEED_X_AXIS;

    else if(key == 'd')
        shape->translation->x += SPEED_X_AXIS;

    else if(key == 's')
        shape->translation->y -= SPEED_Y_AXIS;


    else if(key == SPACEBAR)
        handle_jump(shape);

}

void limit_bound(Shape* shape) {



    if(shape->translation->x > PLAYER_SCREEN_RIGHT)
        shape->translation->x = PLAYER_SCREEN_RIGHT;


    else if(shape->translation->x <  PLAYER_SCREEN_LEFT)
        shape->translation->x = PLAYER_SCREEN_LEFT;



    if(shape->translation->y <=  PLAYER_GROUND_LIMIT) {
        shape->translation->y = PLAYER_GROUND_LIMIT;
        shape->move_data->velocity->y *= -1;
    }



}

void handle_jump(Shape* shape) {


    if(shape->translation->y <  PLAYER_HIGHEST_JUMP_LIMIT)
        shape->translation->y +=  SPEED_X_AXIS;
    printf("Player y : %f\n" , shape->translation->y);


}


void update_movement_data(Shape* shape) {

    apply_force_to_player(shape , shape->move_data->gravity);
    
   
    add_vector(shape->move_data->velocity , shape->move_data->acceleration);
    add_vector(shape->translation , shape->move_data->velocity);
    multi_vector(shape->move_data->acceleration , 0);

}


void apply_force_to_player(Shape* shape , Vector3* force) {

    // f = ma

    Vector3* new_force =  multi_return_vector(force , shape->move_data->mass);
    add_vector(shape->move_data->acceleration, new_force);

}

void debug_angle(Shape* shape , unsigned char key) {

    printf("Current Player angle => %f.\n" ,shape->angle);


    if(key == 'a')
        shape->angle  += 1.0f;
    else if(key == 'd')
        shape->angle  -= 1.0f;
}
