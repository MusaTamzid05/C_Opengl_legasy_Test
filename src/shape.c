#include "shape.h"
#include <GL/glut.h>
#include <stdio.h>

#include "drawer.h"
#include "road.h"
#include "const.h"

void draw_shape(Shape* shape) {

    glPushMatrix();

    glColor3f(shape->shape_data->color->x ,shape->shape_data->color->y ,
            shape->shape_data->color->z);


    glTranslatef(shape->translation->x,shape->translation->y,shape->translation->z);

    glRotatef(shape->angle ,shape->rotation->x , shape->rotation->y , shape->rotation->z);


    if(shape->shape_data->shape_type == Wire)
        glutSolidCone(shape->shape_data->shape_size,.80,15,15); 

    else if(shape->shape_data->shape_type == RoadCube)
        draw_road(shape);

    else if(shape->shape_data->shape_type == ObjectCone)
        glutWireCone(shape->shape_data->shape_size,.80,15,15); 


    else if(shape->shape_data->shape_type == Rectangle)
        draw_rect(PAUSE_STATE_LEFT , PAUSE_STATE_RIGHT , PAUSE_STATE_TOP , PAUSE_STATE_BOTTOM, shape->shape_data->color);

    glPopMatrix();


}



Shape* create_shape(ShapeData* shape_data  , Vector3* translation , Vector3* rotation ,  float angle , MoveData* move_data) {

    Shape* shape = (Shape*)malloc(sizeof(Shape));

    shape->shape_data = shape_data;
    shape->translation = translation;
    shape->rotation = rotation;
    shape->angle = angle;

    shape->move_data = move_data;
    return shape;
}

void update_shape(Shape* shape) {

    shape->translation->x += 0.01;

}


