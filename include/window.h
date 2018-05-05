#ifndef WINDOW_H
#define WINDOW_H


#include "camera.h"
#include "shape.h"
#include "state.h"

typedef struct Window {

    char* title;
    int width;
    int height;
    Camera* camera;
    int update_time;

    unsigned char current_key;
    int total_states;
    State** states;

} Window;


Window* create_window(char* title , int width , int height , Camera* camera , int update_time);

void init_states(Window* window);

void init_shapes(Window* window);
void init_window_camera(Window* window);
void draw_window(Window* window);
void update_window(Window* window);



#endif
