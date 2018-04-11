#include "vertex.h"
#include <stdio.h>
#include <stdlib.h>


Vector3* create_vector(float x , float y , float z) {

    Vector3* vec = (Vector3*)malloc(sizeof(Vector3));

    vec->x = x;
    vec->y = y;
    vec->z = z;

    return vec;

}


void show_vertices(Vector3* vertices , int length) {

    int i = 0;

    for(i = 0 ; i < length ; i++) 
        printf("x = %f , y = %f , z= %f\n" , vertices[i].x , vertices[i].y , vertices[i].z);
}


void show_vertex(char* name , Vector3* vec) {

    printf("%s =>  x : %f , y : %f , z : %f.\n" , name ,  vec->x , vec->y , vec->z);
}
