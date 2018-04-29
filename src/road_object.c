#include "road_object.h"
#include "util.h"
#include <stdlib.h>

RoadObject* create_road_object() {

    RoadObject* road_object = (RoadObject*)malloc(sizeof(RoadObject));
    road_object->angle = 0;
    road_object->color = create_vector (generate_random(1.0) ,generate_random(1.0) , generate_random(1.0));

    return road_object;
}
