#include "move_data.h"
#include <stdlib.h>

MoveData* create_move_data(Vector3* velocity , Vector3* acceleration , Vector3* gravity ,float mass) {

    MoveData* move_data = (MoveData*)malloc(sizeof(MoveData));

    move_data->velocity = velocity;
    move_data->acceleration = acceleration;
    move_data->gravity = gravity;
    move_data->mass  = mass;


    return move_data;
}

