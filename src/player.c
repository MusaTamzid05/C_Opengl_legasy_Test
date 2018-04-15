#include  "player.h"
#include <stdio.h>

Shape* create_player() {



    Vector3* rotation = create_vector(1.0f , 0.0f , 0.0f);
    Vector3* translation = create_vector(-1.0f , -2.3f , 0.0f);
    Vector3* scale = create_vector(0.0f , 0.0f , 0.0f);

    ShapeData* shape_data = create_shape_data(Wire , 0.4, create_vector(0.0f, 0.0f , 1.0f));

    
    return create_shape(shape_data , translation , rotation , scale , 231.0f , 0);


}


void update_player(Shape* shape , unsigned char key) {
    

}


void debug_angle(Shape* shape , unsigned char key) {

    printf("Current Player angle => %f.\n" ,shape->angle);


    if(key == 'a')
        shape->angle  += 1.0f;
    else if(key == 'd')
        shape->angle  -= 1.0f;
}
