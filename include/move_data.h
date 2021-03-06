#ifndef MOVE_DATA_H
#define MOVE_DATA_H

#include "vertex.h"


typedef struct MoveData {

    Vector3*   velocity;
    Vector3*   acceleration;
    Vector3*   gravity;

    float     mass;
    float     friction_constant;

} MoveData;


MoveData* create_move_data(Vector3* velocity , Vector3* acceleration , Vector3* gravity , float mass , float friction_constant);



#endif
