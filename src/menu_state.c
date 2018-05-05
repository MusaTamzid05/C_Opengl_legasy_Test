#include "menu_state.h"
#include <stdlib.h>
#include <stdio.h>
#include "const.h"


int current_menu_option = 0;

State* create_menu_state() {

    State* state = (State*)malloc(sizeof(State));
    init_menu_state_shapes(state);

    state->update_state_ptr = update_menu_state;
    state->draw_state_ptr = draw_menu_state;
    init_menu_state_texts(state);
    return state;

}


void update_menu_state( int* current_state_index , State* state , unsigned char current_key) {


    int i = 0;
    for(i = 0 ; i < state->total_shapes; i++){
        state->shapes[i]->update_func_ptr(state->shapes[i] , current_key);
    }

    update_menu_state_option(state, current_key);
    handle_menu_key_event(current_state_index , state, current_key);


}


void init_menu_state_shapes(State* state) {

    state->total_shapes = 0;

}


void draw_menu_state(State* state) {

    glClearColor(0.0 , 0.0 , 0.3 , 1.0);

    int i = 0;

    for(i = 0 ; i < state->total_shapes; i++)
        draw_shape(state->shapes[i]);

    for(i = 0 ; i < state->total_texts; i++)
        draw_text(state->texts[i]);


}

void init_menu_state_texts(State* state) {


    int total_texts = 2;
    state->total_texts = total_texts;
    state->texts = (Text**)malloc(sizeof(Text) * total_texts);

    state->texts[0] = create_text("Start Game" , create_vector(0.0f , -500.0f ,0.0) , create_vector(2.0 , 2.0 , 1.0) , create_vector(1.0 , 1.0 , 1.0));
    state->texts[1] = create_text("Exit Game" , create_vector(0.0f , -900.0f ,0.0) , create_vector(2.0 , 2.0 , 1.0) , create_vector(1.0 , 1.0 , 1.0));

}



void update_menu_state_option(State* state , unsigned char current_key) {


    int i = 0;

    for(i = 0 ; i < state->total_texts; i++) {

        if(i == current_menu_option)
            state->texts[i]->color = create_vector(1.0 , 1.0 , 0.0);
        else
            state->texts[i]->color = create_vector(1.0 , 1.0 , 1.0);

    }

    if(current_key == 's')
        current_menu_option++;

    else if (current_key == 'w')
        current_menu_option--;

    if(current_menu_option < 0)
        current_menu_option = 0;

    else if(current_menu_option > 1)
        current_menu_option = 1;

}


void handle_menu_key_event(int* current_state_index , State* state , unsigned char current_key) {

    if(current_key == SPACEBAR) {

        if(current_menu_option == 0) {
            *current_state_index = GAME_STATE_INDEX;
        }

        else if(current_menu_option == 1) {
            exit(1);
        }

    }
}
