#include "drawer.h"
#include <GL/glut.h>

void draw_square_with_line(float x , float y) {



        glBegin(GL_LINES);
        glVertex3f(-x, -y , 0.0);
        glVertex3f(x , -y, 0.0);


        glVertex3f(x, -y , 0.0);
        glVertex3f(x , y , 0.0);


        glVertex3f(x , y ,  0.0);
        glVertex3f(-x , y ,  0.0);


        glVertex3f(-x,  y  , 0.0);
        glVertex3f(-x , -y , 0.0);

        glEnd();

}
