#include "window.h"
#include <GL/glut.h>
#include <stdio.h>
#include "shape.h"




void init_shapes(Window* window) {


    int total_shapes = 1;
    window->total_shapes = total_shapes;

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

    Shape* shape = create_shape(3 , vertices , translation , rotation , scale , 0 , GL_TRIANGLES , 0);

    printf("%f\n" , shape->angle);
    window->shape = shape;
    //window->shapes = (Shape*)malloc(sizeof(Shape) * total_shapes);
    //window->shapes[0] = shape;



    //Shape* first_shape = create_shape()
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

    show_vertex("Rotation" , window->camera->rotation);
    show_vertex("translation" , window->camera->translation);
    printf("Angle : %d\n" ,window->camera->angle);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity(); 
	glRotatef(window->camera->angle, window->camera->rotation->x , window->camera->rotation->y , window->camera->rotation->z); 
	glTranslatef(window->camera->translation->x , window->camera->translation->y, window->camera->translation->z); 


}

void draw_window(Window* window) {


    init_window_camera(window);
    draw_shape(window->shape);


}


void update_window(Window* window) {


}

