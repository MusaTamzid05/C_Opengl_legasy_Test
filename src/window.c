#include "window.h"
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include "stats.h"
#include "menu_state.h"
#include "game_state.h"


void init_states(Window* window) {

    window->total_states = 2;
    window->states= (State**)malloc(sizeof(State) * window->total_states);


    window->states[0] =  create_menu_state();
    window->states[1] = create_game_state();
}



Window* create_window(char* title , int width , int height , Camera* camera , int update_time) {

    Window* window = (Window*)malloc(sizeof(Window));

    window->title = title;
    window->width = width;
    window->height = height;
    window->camera = camera;
    window->update_time = update_time;
    init_states(window);

    return window;

}

void init_window_camera(Window* window) {


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity(); 
	glRotatef(window->camera->angle, window->camera->rotation->x , window->camera->rotation->y , window->camera->rotation->z); 
	glTranslatef(window->camera->translation->x , window->camera->translation->y, window->camera->translation->z); 


}

void draw_window(Window* window) {


    init_window_camera(window);

    window->states[window->current_state_index]->draw_state_ptr(window->states[window->current_state_index]);

}


void update_window(Window* window) {

    
    window->states[window->current_state_index]->update_state_ptr(window->states[window->current_state_index] , window->current_key);
    window->current_key = '-';

}

