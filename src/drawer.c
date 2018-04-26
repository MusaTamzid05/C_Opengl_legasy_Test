#include "drawer.h"
#include <GL/glut.h>



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
