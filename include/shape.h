#ifndef SHAPE_H
#define SHAPE_H

#include <GL/gl.h>
#include "vertex.h"
#include "shape_data.h"



typedef struct MoveData {

    Vector3*   velocity;
    Vector3*   acceleration;
    Vector3*   gravity;

    float     mass;
} MoveData;




typedef struct Shape  {


    ShapeData*  shape_data;
    MoveData*  move_data;

    Vector3* translation;
    Vector3* rotation;
    Vector3* scale;
    float angle;


    int should_scale;

    void (*update_func_ptr)();

} Shape;


Shape* create_shape(ShapeData* shape_data , Vector3* translation , Vector3* rotation ,  Vector3* scale , float angle ,  int should_scale);
void draw_shape(Shape* shape);
void update_shape(Shape* shape);

#endif
