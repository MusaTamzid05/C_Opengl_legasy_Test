#ifndef DRAWER_H
#define DRAWER_H

#include "road_object.h"

void draw_rect(float left , float right , float top , float bottom , Vector3* color);
void draw_road_obect(float translate_x , float translate_y , float translate_z ,int object_index , RoadObject* road_object);

#endif
