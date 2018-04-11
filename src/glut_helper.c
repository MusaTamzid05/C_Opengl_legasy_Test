#include "glut_helper.h"
#include <GL/glut.h>


#include <stdio.h>

Window* main_window;

void init_glut(int argc , char** argv , Window* window) {


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(window->width , window->height);
	glutInitWindowPosition(window->width / 2 , window->height / 2);

    main_window = window;
    init_shapes(main_window);

}

void create_glut_window() {

    glutCreateWindow(main_window->title);
    init_rendering();
}

void init_rendering() {


	glEnable(GL_DEPTH_TEST);

}




void handle_resize(int w, int h)  {


	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);

}


// opengl callbacks.


void update_callback(int value) {


    update_window(main_window);

    glutPostRedisplay();
    glutTimerFunc(main_window->update_time , update_callback , 0);

}


void draw_callback() {


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



    draw_window(main_window);
	glutSwapBuffers();
}

