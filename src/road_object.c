#include "road_object.h"
#include "util.h"
#include <stdlib.h>
#include "const.h"

RoadObject* create_road_object() {

    RoadObject* road_object = (RoadObject*)malloc(sizeof(RoadObject));
    road_object->angle = 0;
    road_object->color = create_vector (generate_random(1.0) ,generate_random(1.0) , generate_random(1.0));

    road_object->angle_incrementer = generate_random(MAX_ANGLE_INCREMENTER) + MIN_ANGLE_INCREMENTER;

    if(generate_random(10) > 5 )
        road_object->rotation= create_vector(1.0 , 0.0 , 0.0);
    else
        road_object->rotation= create_vector(0.0 , 1.0 , 0.0);

    return road_object;
}
