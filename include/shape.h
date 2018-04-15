#ifndef SHAPE_H
#define SHAPE_H

#include <GL/gl.h>
#include "vertex.h"


enum ShapeType {

    Wire,
    Square
};

typedef struct ShapeData {


    enum ShapeType shape_type;
    float   shape_size;
    Vector3* color;
} ShapeData;


ShapeData* create_shape_data(enum ShapeType shape_type , float shape_size , Vector3* color);


typedef struct Shape  {


    ShapeData*  shape_data;
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
