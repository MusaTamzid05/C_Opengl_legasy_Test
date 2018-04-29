#include "drawer.h"
#include <GL/glut.h>
#include "const.h"


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

void draw_road_obect(float translate_x , float translate_y , float translate_z ,int object_index) {

    
    if(object_index == NO_OBJECT)
        return;


    glPushMatrix();
    glTranslatef(translate_x , translate_y , translate_z);
    

    if(object_index == SPHERE_OBJECT) {
        
        glColor3f(0.0f , 1.0f , 0.0f);
        glutWireSphere(.2, 20 , 20);
    }
    
    glPopMatrix();
}
