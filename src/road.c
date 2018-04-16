#include "road.h"
#include "const.h"

#include <stdio.h>
#include <stdlib.h>

Shape** init_road() {

    Shape** shapes = (Shape**)malloc(sizeof(Shape) * 36 );

    int i = 0;
    int j = 0;

    float road_col_index = ROAD_X_AXIS_LEFT_LIMIT;
    float road_row_index = ROAD_Y_AXIS_DOWN_LIMIT;

    int road_index = 0;
    
    float angle = ROAD_ANGLE ;

    for(j = 0 ; j < TOTAL_ROAD_ROW; j++) {


        for(i = 0; i < TOTAL_ROAD_COL; i++) {


        Vector3* rotation = create_vector(1.0f , 0.0f , 0.0f);
        Vector3* translation = create_vector(road_col_index, road_row_index , 0.0f);
        ShapeData* shape_data = create_shape_data(Cube, 1.0 , create_vector(1.0f , 1.0f , 1.0f));
        MoveData* move_data = create_single_road_move_data();

        shapes[road_index] = create_single_road(shape_data , translation , rotation , angle,  move_data);

        road_index++;

        road_col_index += 1.2f;
        }


        road_col_index = ROAD_X_AXIS_LEFT_LIMIT;
        road_row_index += 1.2f;

    }


    return shapes;

}

Shape* create_single_road(ShapeData* shape_data , Vector3* translation , Vector3* rotation, float angle , MoveData* move_data ) {

    Shape* shape = (Shape*)malloc(sizeof(Shape));

    shape->shape_data = shape_data;
    shape->translation = translation;
    shape->rotation = rotation;
    shape->angle = angle;
    shape->move_data = move_data;

    shape->update_func_ptr = update_single_road;

    return shape;

}

void update_single_road(Shape* shape , unsigned char key) {


    if(key == 'w')
        shape->translation->y += 1.0f;

    printf("Road angle = %f\n" , shape->angle);


}


MoveData* create_single_road_move_data() {


    float mass = 1.0f;
    Vector3* velocity = create_vector(0.0f , 0.0f , 0.0f);
    Vector3* acceleration = create_vector(0.0f , 0.0f , 0.0f);

    Vector3* gravity = create_vector(0.0f , 0.0f, 0.0f);

    return create_move_data(velocity , acceleration , gravity , mass , ROAD_FRICTION);

}
