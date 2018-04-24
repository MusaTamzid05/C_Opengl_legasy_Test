#include "road.h"
#include "const.h"

#include <stdio.h>
#include <stdlib.h>

Shape** init_road() {


    printf("Road data initialize.\n");
    Shape** shapes = (Shape**)malloc(sizeof(Shape) * 30);
    RoadData** road_data = init_road_data();


    int row = 0;
    int col = 0;

    float road_col_index = ROAD_X_AXIS_LEFT_LIMIT;
    float road_row_index = ROAD_Y_AXIS_DOWN_LIMIT;

    int road_index = 0;
    
    float angle = ROAD_ANGLE ;
    
    int total_road_row = 5;
    int total_road_col = 6;

    float y_axis_values[5] = { ROAD_Y_AXIS_DOWN_LIMIT , -1.500f , -.8200f , -.258f , 0.2f  };
    float col_starting_index[5] = {ROAD_X_AXIS_LEFT_LIMIT , -2.4f ,  -1.9f , -1.4f , -1.05f};
    float road_col_incrementer[5] = { 1.2f , 0.95f  , 0.75f  , 0.55f , 0.40f};

    int road_rect_index = 0;

    for(row = 0 ; row < total_road_row ; row++) {


        road_col_index = col_starting_index[row];
        
        for(col = 0; col  < total_road_col ; col++) {


            Vector3* rotation = create_vector(1.0f , 0.0f , 0.0f);
            Vector3* translation = create_vector(road_col_index, y_axis_values[row], 0.0f);
            ShapeData* shape_data = create_shape_data(Cube, 1.0 , create_vector(1.0f , 1.0f , 1.0f));
            MoveData* move_data = create_single_road_move_data();

            printf("%f , %f \n" , road_data[row]->x , road_data[row]->y);
            shapes[road_rect_index] = create_single_road(shape_data , translation , rotation , ROAD_ANGLE ,  move_data , road_data[row]);
            road_rect_index++;
            road_col_index += road_col_incrementer[row];

        }
    
    }

    return shapes;

}

Shape* create_single_road(ShapeData* shape_data , Vector3* translation , Vector3* rotation, float angle , MoveData* move_data   , RoadData* road_data) {

    Shape* shape = (Shape*)malloc(sizeof(Shape));

    shape->shape_data = shape_data;
    shape->translation = translation;
    shape->rotation = rotation;
    shape->angle = angle;
    shape->move_data = move_data;
    shape->road_data = road_data;

    shape->update_func_ptr = update_single_road;

    return shape;

}

void update_single_road(Shape* shape , unsigned char key) {


    if(key == 'w')
        shape->translation->y += 0.01f;


    if(key == 's')
        shape->translation->y -= 0.01f;

    //printf("Road y= %f\n" , shape->translation->y);


}


MoveData* create_single_road_move_data() {


    float mass = 1.0f;
    Vector3* velocity = create_vector(0.0f , 0.0f , 0.0f);
    Vector3* acceleration = create_vector(0.0f , 0.0f , 0.0f);

    Vector3* gravity = create_vector(0.0f , 0.0f, 0.0f);

    return create_move_data(velocity , acceleration , gravity , mass , ROAD_FRICTION);

}


RoadData* create_road_data(float x , float y) {

    RoadData* road_data = (RoadData*)malloc(sizeof(RoadData));
    road_data->x = x;
    road_data->y = y;


    return road_data;
}


RoadData** init_road_data() {


    RoadData** road_data = (RoadData**)malloc(sizeof(RoadData) * 5);
    road_data[0] = create_road_data(0.6f , 0.75f);
    road_data[1] = create_road_data(0.48f , 0.75f);
    road_data[2] = create_road_data(0.38f , 0.75f);
    road_data[3] = create_road_data(0.28f , 0.75f);
    road_data[4] = create_road_data(0.20f , 0.75f);


    return road_data;
}
