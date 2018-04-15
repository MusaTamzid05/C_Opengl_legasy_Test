#include "shape_data.h"

#include <stdlib.h>


ShapeData* create_shape_data(enum ShapeType shape_type , float shape_size , Vector3* color) {

    ShapeData* shape_data =(ShapeData*)malloc(sizeof(ShapeData));
    shape_data->shape_type = shape_type;
    shape_data->shape_size = shape_size;
    shape_data->color = color;

    return shape_data;
}
