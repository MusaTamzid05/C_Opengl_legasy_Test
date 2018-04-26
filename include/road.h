#ifndef ROAD_H
#define ROAD_H


#include "shape.h"
#include "road_rect.h"

RoadRect** road_rects;
Vector3** create_road_colors();
Shape* create_road();

void update_road(Shape* shape , unsigned char key);
void draw_road(Shape* shape);

#endif
