#ifndef ROAD_OBJECT_H
#define ROAD_OBJECT_H

#include "vertex.h"

typedef struct RoadObject {

    float angle;
    Vector3* color;

}RoadObject;

RoadObject* create_road_object();
#endif
