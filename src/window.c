#include "window.h"
#include <GL/glut.h>
#include <stdio.h>
#include "shape.h"
#include "shape_updater.h"



void init_shapes(Window* window) {


    int total_shapes = 2;
    window->total_shapes = total_shapes;

    window->shapes = (Shape**)malloc(sizeof(Shape) * total_shapes);

    Vector3* vertices = (Vector3*)malloc( 3 * sizeof(Vector3));

    vertices[0].x = 0.5f;
    vertices[0].y = -0.5f;
    vertices[0].z = 0.0f;


    vertices[1].x = 0.0f;
    vertices[1].y = 0.5f;
    vertices[1].z = -0.0f;


    vertices[2].x = -0.5f;
    vertices[2].y = -0.5f;
    vertices[2].z = 0.0f;

    Vector3* rotation = create_vector(0.0f , 1.0f , 0.0f);
    Vector3* translation = create_vector(1.0f , 1.0f , 0.0f);
    Vector3* scale = create_vector(0.0f , 0.0f , 0.0f);


    Vector3* translation2 = create_vector(0.0f , 1.0f , 0.0f);
    window->shapes[0] = create_shape(3 , vertices , translation , rotation , scale , 0 , GL_TRIANGLES , 0);
    window->shapes[0]->update_func_ptr = update1;
    window->shapes[1] = create_shape(3 , vertices ,  translation2, rotation , scale , 0 , GL_TRIANGLES , 0);
    window->shapes[1]->update_func_ptr = update2;

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

