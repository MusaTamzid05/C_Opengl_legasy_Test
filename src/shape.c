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
        glutWireCone(shape->shape_data->shape_size,.80,15,15); //(GLdouble base, GLdouble height,GLint slices, GLint stacks);
    glPopMatrix();


}



Shape* create_shape(ShapeData* shape_data  , Vector3* translation , Vector3* rotation ,  Vector3* scale , float angle , int should_scale) {

    Shape* shape = (Shape*)malloc(sizeof(Shape));

    shape->shape_data = shape_data;
    shape->translation = translation;
    shape->rotation = rotation;
    shape->scale = scale;
    shape->angle = angle;
    shape->should_scale = should_scale;

    return shape;
}

void update_shape(Shape* shape) {

    shape->translation->x += 0.01;

}


