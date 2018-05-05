#include "pause_state.h"
#include <stdlib.h>
#include "shape_data.h"
#include "move_data.h"


State* create_pause_state() {


    State* state = (State*)malloc(sizeof(State));
    init_pause_state_shapes(state);

    state->update_state_ptr = update_pause_state;
    state->draw_state_ptr = draw_pause_state;
    init_pause_state_texts(state);
    return state;
}


void update_pause_state( int* current_state_index , State* state , unsigned char current_key) {


}


void init_pause_state_shapes(State* state) {

    state->total_shapes = 1;
    state->shapes = (Shape**)malloc(sizeof(Shape) * state->total_shapes);

    Vector3* rotation = create_vector(0.0 , 0.0 , 0.0 );
    Vector3* translation = create_vector(-2.0 , -1.0 , 3.0);
    ShapeData* shape_data = create_shape_data(Rectangle , -1 , create_vector(0.0 , 1.0 ,0.0));

    MoveData* move_data = NULL;

    state->shapes[0] = create_shape(shape_data , translation , rotation , 0.0 , move_data);

}


void draw_pause_state(State* state) {


    int i = 0;

    for(int i = 0 ; i < state->total_shapes; i++)
        draw_shape(state->shapes[i]);

    for(i = 0 ; i < state->total_texts; i++)
        draw_text(state->texts[i]);


}

void init_pause_state_texts(State* state) {

}
