#include "drawer.h"
#include "const.h"
#include <GL/glut.h>
#include "util.h"
#include <stdio.h>


void draw_rect(float left , float right , float top , float bottom , Vector3* color) {


    glBegin(GL_POLYGON);
    
    glColor3f(color->x , color->y , color->z);

    glVertex3f( left , top , 0.0);
    glVertex3f( right , top , 0.0);
    glVertex3f(left, bottom  , 0.0);


    glVertex3f( right , top , 0.0);
    glVertex3f( right , bottom, 0.0);
    glVertex3f(left, bottom  , 0.0);

    
    
    glEnd();
}

void draw_road_obect(float translate_x , float translate_y , float translate_z ,int object_index,  RoadObject* road_object) {

    
    if(object_index == NO_OBJECT)
        return;


    glPushMatrix();
    glTranslatef(translate_x , translate_y , translate_z);
    glRotatef(road_object->angle , road_object->rotation->x , road_object->rotation->y , road_object->rotation->z );

    if(object_index == SPHERE_OBJECT) {
        
        glColor3f(road_object->color->x , road_object->color->y , road_object->color->z);
        glutWireSphere(.4, 20 , 20);

    } else if(object_index == CUBE_OBJECT){


        glColor3f(road_object->color->x , road_object->color->y , road_object->color->z);
        glutSolidCube(.4);
    }
    
    glPopMatrix();
}
