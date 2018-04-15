#include  "player.h"


Shape* create_player() {



    Vector3* rotation = create_vector(1.0f , 0.0f , 0.0f);
    Vector3* translation = create_vector(1.0f , 0.0f , 0.0f);
    Vector3* scale = create_vector(0.0f , 0.0f , 0.0f);

    ShapeData* shape_data = create_shape_data(Wire , 0.3, create_vector(0.0f, 0.0f , 1.0f));

    
    return create_shape(shape_data , translation , rotation , scale , 310, 0);


}


void update_player(Shape* shape , unsigned char key) {




    if(key == 'a')
        shape->translation->x -= 0.01;
    else if(key == 'd')
        shape->translation->x += 0.01;

}
