#include "shape.h"
#include <GL/glut.h>
#include <stdio.h>


void draw_shape(Shape* shape) {

   
	glPushMatrix(); 
	glTranslatef(shape->translation->x , shape->translation->y, shape->translation->z);

    if(shape->should_scale)
        glScalef(shape->scale->x , shape->scale->y , shape->scale->z); 

    glRotatef(shape->angle ,shape->rotation->x, shape->rotation->y , shape->rotation->z); 

	glBegin(shape->mode);


    int i = 0;
    for(i = 0 ; i < shape->total_vertices; i++)
        glVertex3f(shape->vertices[i].x , shape->vertices[i].y , shape->vertices[i].z);

   
	glEnd();

	glPopMatrix(); 


}



Shape* create_shape(int total_vertices , Vector3* vertices , Vector3* translation , Vector3* rotation ,  Vector3* scale , float angle , GLenum mode  , int should_scale) {

    Shape* shape = (Shape*)malloc(sizeof(Shape));

    shape->total_vertices = total_vertices;
    shape->vertices = vertices;
    shape->translation = translation;
    shape->rotation = rotation;
    shape->scale = scale;
    shape->angle = angle;
    shape->mode = mode;
    shape->should_scale = should_scale;

    return shape;
}

void update_shape(Shape* shape) {

    shape->translation->x += 0.01;

}
