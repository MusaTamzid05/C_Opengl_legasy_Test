#include "drawer.h"
#include <GL/glut.h>

void draw_square_with_line() {

        glBegin(GL_LINES);
        glVertex3f(-0.6 , -0.75 , 0.0);
        glVertex3f(0.6 , -0.75 , 0.0);


        glVertex3f(0.6 , -0.75 , 0.0);
        glVertex3f(0.6 , 0.75 , 0.0);


        glVertex3f(0.6 , 0.75 , 0.0);
        glVertex3f(-0.6 , 0.75 , 0.0);


        glVertex3f(-0.6 , 0.75 , 0.0);
        glVertex3f(-0.6 , -0.75 , 0.0);


        glEnd();

}
