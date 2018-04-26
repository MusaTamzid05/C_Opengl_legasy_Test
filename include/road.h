#ifndef ROAD_H
#define ROAD_H


#include "shape.h"
#include "road_rect.h"

RoadRect** road_rects;

Shape* create_road();

void update_road(Shape* shape , unsigned char key);
void draw_road(Shape* shape);

#endif
