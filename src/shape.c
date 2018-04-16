#include "shape.h"
#include <GL/glut.h>
#include <stdio.h>

#include "drawer.h"

void draw_shape(Shape* shape) {

    glPushMatrix();

    glColor3f(shape->shape_data->color->x ,shape->shape_data->color->y ,
            shape->shape_data->color->z);


    glTranslatef(shape->translation->x,shape->translation->y,shape->translation->z);

    glRotatef(shape->angle ,shape->rotation->x , shape->rotation->y , shape->rotation->z);


    if(shape->shape_data->shape_type == Wire)
        glutWireCone(shape->shape_data->shape_size,.80,15,15); 
    else if(shape->shape_data->shape_type == Cube) {
        draw_square_with_line();
    }


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


