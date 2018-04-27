#include  "player.h"
#include <stdio.h>
#include <stdlib.h>
#include "const.h"


Shape* create_player() {



    Vector3* rotation = create_vector(1.0f , 0.0f , 0.0f);
    Vector3* translation = create_vector(-1.0f ,  PLAYER_GROUND_LIMIT , PLAYER_Z_AXIS_VALUS);

    ShapeData* shape_data = create_shape_data(Wire , 0.4, create_vector(0.0f, 0.0f , 1.0f));


    MoveData* move_data = create_player_move_data();


    return create_shape(shape_data , translation , rotation , 231.0f  , move_data);


}


MoveData* create_player_move_data() {



    float mass = 1.0f;
    Vector3* velocity = create_vector(0.0f , 0.0f , 0.0f);
    Vector3* acceleration = create_vector(0.0f , 0.0f , 0.0f);

    Vector3* gravity = create_vector(0.0f , PLAYER_GRAVITY , 0.0f);

    return create_move_data(velocity , acceleration , gravity , mass , PLAYER_FRICTION);


}


void update_player(Shape* shape , unsigned char key) {



    handle_keyboard(shape , key);
    limit_bound(shape);

    update_movement_data(shape);

}



void handle_keyboard(Shape* shape , unsigned char key) {

    if(key == 'a')
        apply_force_to_player(shape  , create_vector(-SPEED_X_AXIS , 0.0f , 0.0f));


    else if(key == 'd')
        apply_force_to_player(shape  , create_vector(SPEED_X_AXIS , 0.0f , 0.0f));

    else if(key == 's')
        shape->translation->y -= SPEED_Y_AXIS;


    else if(key == SPACEBAR)
        handle_jump(shape);

}

void limit_bound(Shape* shape) {



    if(shape->translation->x > PLAYER_SCREEN_RIGHT) {

        shape->translation->x = PLAYER_SCREEN_RIGHT;
        shape->move_data->velocity->x *= -1;

    }


    else if(shape->translation->x <  PLAYER_SCREEN_LEFT) {

        shape->translation->x = PLAYER_SCREEN_LEFT;
        shape->move_data->velocity->x *= -1;

    }



    if(shape->translation->y <=  PLAYER_GROUND_LIMIT) {
        shape->translation->y = PLAYER_GROUND_LIMIT;
        shape->move_data->velocity->y *= -1;
    }


    if(shape->translation->y >= PLAYER_SKY_LIMIT) {
        shape->translation->y = PLAYER_SKY_LIMIT ;
        shape->move_data->velocity->y *= -1;
    }



}

void handle_jump(Shape* shape) {


    apply_force_to_player(shape , create_vector(0.0f , PLAYER_JUMP_FORCE_Y_AXIS , 0.0f));

}


void update_movement_data(Shape* shape) {

    apply_force_to_player(shape , shape->move_data->gravity);
    
   
    add_vector(shape->move_data->velocity , shape->move_data->acceleration);
    add_vector(shape->translation , shape->move_data->velocity);
    multi_vector(shape->move_data->acceleration , 0);
    apply_friction_to_player(shape);

}


void apply_force_to_player(Shape* shape , Vector3* force) {

    // f = ma

    Vector3* new_force =  multi_return_vector(force , shape->move_data->mass);
    add_vector(shape->move_data->acceleration, new_force);

}


void apply_friction_to_player(Shape* shape) {


    // nomarlize_velocity * -1  * friction_constant.
    
    Vector3* friction = (Vector3*)malloc(sizeof(Vector3));
    copy_vector(shape->move_data->velocity , friction);
    multi_vector(friction ,-1.0f);

    normalize_vector(friction);
    multi_vector(friction , shape->move_data->friction_constant);

    apply_force_to_player(shape , friction);


}

void debug_angle(Shape* shape , unsigned char key) {

    printf("Current Player angle => %f.\n" ,shape->angle);


    if(key == 'a')
        shape->angle  += 1.0f;
    else if(key == 'd')
        shape->angle  -= 1.0f;
}


