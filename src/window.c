#include "window.h"
#include <GL/glut.h>
#include <stdio.h>
#include "player.h"
#include "road.h"
#include "const.h"


void init_shapes(Window* window) {


    int total_shapes = 24;
    window->total_shapes = total_shapes;

    window->shapes = (Shape**)malloc(sizeof(Shape) * total_shapes);

    Shape** road_shapes = init_road();

    int i;

    for(i = 0 ; i < total_shapes ; i++)
        window->shapes[i] = road_shapes[i];

    int player_index  = total_shapes - 1;


    //window->shapes[player_index] = create_player();
    //window->shapes[player_index]->update_func_ptr = update_player;
}


Window* create_window(char* title , int width , int height , Camera* camera , int update_time) {

    Window* window = (Window*)malloc(sizeof(Window));

    window->title = title;
    window->width = width;
    window->height = height;
    window->camera = camera;
    window->update_time = update_time;

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

    int i = 0;

    for(int i = 0 ; i < window->total_shapes; i++)
        draw_shape(window->shapes[i]);


}


void update_window(Window* window) {



    int i = 0;

    for(int i = 0 ; i < window->total_shapes; i++){
        window->shapes[i]->update_func_ptr(window->shapes[i] , window->current_key);
    }

    window->current_key = '-';
}

