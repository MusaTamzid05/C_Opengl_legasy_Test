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


void add_vector(Vector3* vec1 , Vector3* vec2);
void sub_vector(Vector3* vec1  , Vector3* vec2);

void multi_vector(Vector3* vec , float value);
void div_vector(Vector3* vec , float value);



Vector3* multi_return_vector(Vector3* vec , float value);
Vector3* div_return_vector(Vector3* vec , float value);

Vector3* copy_vector(Vector3* from , Vector3* to);

float magitude_of_vector(Vector3* vec);
void  normalize_vector(Vector3* vec);

void limit(Vector3* vector , float max_value , float min_value);

#endif
