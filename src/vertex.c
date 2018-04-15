#include "vertex.h"
#include <stdio.h>
#include <stdlib.h>

#include <math.h>

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


void add_vector(Vector3* vec1 , Vector3* vec2) {


    vec1->x += vec2->x;
    vec1->y += vec2->y;
    vec1->z += vec2->z;

}


void sub_vector(Vector3* vec1  , Vector3* vec2) {


    vec1->x -= vec2->x;
    vec1->y -= vec2->y;
    vec1->z -= vec2->z;

}

void multi_vector(Vector3* vec , float value) {


    vec->x *= value;
    vec->y *= value;
    vec->z *= value;
}


void div_vector(Vector3* vec , float value) {


    vec->x /= value;
    vec->y /= value;
    vec->z /= value;

}


Vector3* multi_return_vector(Vector3* vec , float value) {

    Vector3* new_vector = (Vector3*)malloc(sizeof(Vector3));

    new_vector->x = vec->x * value;
    new_vector->y = vec->y * value;
    new_vector->z = vec->z * value;

    return new_vector;


}


Vector3* div_return_vector(Vector3* vec , float value) {


    Vector3* new_vector = (Vector3*)malloc(sizeof(Vector3));

    new_vector->x = vec->x / value;
    new_vector->y = vec->y / value;
    new_vector->z = vec->z / value;

    return new_vector;
}


float magitude_of_vector(Vector3* vec) {

    return sqrt(vec->x * vec->x +  vec->y * vec->y);
}


void normalize_vector(Vector3* vec) {

    
    float magnitude = magitude_of_vector(vec);

    if(magnitude != 0)
        div_vector(vec , magnitude);


    
}


Vector3* copy_vector(Vector3* from , Vector3* to) {

    
    to->x = from->x;
    to->y = from->y;
    to->z = from->z;
}
