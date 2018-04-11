#ifndef VERTEX_H
#define VERTEX_H



typedef struct Vector3 {

    float x;
    float y;
    float z;
} Vector3;


Vector3* create_vector(float x , float y , float z);
void show_vertex(char* name , Vector3* vec);
void show_vertices(Vector3* vertices , int length);

#endif
