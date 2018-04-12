#ifndef SHAPE_H
#define SHAPE_H

#include <GL/gl.h>
#include "vertex.h"

typedef struct Shape  {

    int total_vertices;
    Vector3* vertices;
    Vector3* translation;
    Vector3* rotation;
    Vector3* scale;
    float angle;

    GLenum mode;

    int should_scale;

    void (*update_func_ptr)();

} Shape;


Shape* create_shape(int total_vertices , Vector3* vertices , Vector3* translation , Vector3* rotation ,  Vector3* scale , float angle , GLenum mode  , int should_scale);
void draw_shape(Shape* shape);
void update_shape(Shape* shape);

#endif
