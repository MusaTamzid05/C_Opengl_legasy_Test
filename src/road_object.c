#include "road_object.h"
#include "shape_data.h"
#include "const.h"
#include <stdio.h>

Shape* create_road_object(RoadRect* road_rect) {

    printf("%f , %f , %f , %f\n" , road_rect->left ,road_rect->right , road_rect->top, road_rect->bottom);

    Vector3* rotation = create_vector(1.0f , 0.0f , 0.0f);
    Vector3* translation = create_vector(road_rect->left,  road_rect->top, PLAYER_Z_AXIS_VALUS);

    ShapeData* shape_data = create_shape_data(ObjectCone, 0.2, create_vector(0.0f, 0.0f , 1.0f));


    return create_shape(shape_data , translation , rotation , 231.0f  , NULL);

}
