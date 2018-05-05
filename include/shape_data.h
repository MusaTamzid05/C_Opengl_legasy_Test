#ifndef SHAPE_DATA_H
#define SHAPE_DATA_H


#include "vertex.h"


enum ShapeType {

    Wire,
    RoadCube, 

    // This are all road objects below.

    ObjectCone,
    Rectangle

};

typedef struct ShapeData {


    enum ShapeType shape_type;
    float   shape_size;
    Vector3* color;
} ShapeData;



ShapeData* create_shape_data(enum ShapeType shape_type , float shape_size , Vector3* color);


#endif
