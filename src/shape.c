#include "shape.h"
#include <GL/glut.h>
#include <stdio.h>


void draw_shape(Shape* shape) {

    glPushMatrix();

    glColor3f(shape->shape_data->color->x ,shape->shape_data->color->y ,
            shape->shape_data->color->z);


    glTranslatef(shape->translation->x,shape->translation->y,shape->translation->z);

    glRotatef(shape->angle ,shape->rotation->x , shape->rotation->y , shape->rotation->z);


    if(shape->shape_data->shape_type == Wire)
        glutWireCone(shape->shape_data->shape_size,.80,15,15); 

    glPopMatrix();


}



Shape* create_shape(ShapeData* shape_data  , Vector3* translation , Vector3* rotation ,  float angle ) {

    Shape* shape = (Shape*)malloc(sizeof(Shape));

    shape->shape_data = shape_data;
    shape->translation = translation;
    shape->rotation = rotation;
    shape->angle = angle;

    return shape;
}

void update_shape(Shape* shape) {

    shape->translation->x += 0.01;

}


