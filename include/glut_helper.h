#ifndef GLUT_HELPER_H
#define GLUT_HELPER_H

#include "window.h"


void init_glut(int argc , char** argv , Window* window);
void create_glut_window();
void init_rendering();
void handle_resize(int w, int h) ;


// opengl callbacks.

void update_callback(int value);
void draw_callback();

#endif
