#include "pause_state.h"
#include <stdlib.h>
#include "shape_data.h"
#include "move_data.h"

#include <stdio.h>
#include "stats.h"
#include "const.h"

int current_pause_state_option = 2;

State* create_pause_state() {


    State* state = (State*)malloc(sizeof(State));
    init_pause_state_shapes(state);

    state->update_state_ptr = update_pause_state;
    state->draw_state_ptr = draw_pause_state;
    init_pause_state_texts(state);
    return state;
}


void update_pause_state( int* current_state_index , State* state , unsigned char current_key) {

    sprintf(state->texts[1]->str, "Score : %d" , stats->score);

    int i = 2;

    for(i = PAUSE_STATE_CONTINUE_TEXT ; i <= PAUSE_STATE_QUIT_TEXT ; i++) {

        if(i == current_pause_state_option)
            state->texts[i]->color = create_vector(1.0 , 1.0 , 0.0);
        else
            state->texts[i]->color = create_vector(1.0 , 1.0 , 1.0);

    }

    handle_pause_key_event(current_state_index , state , current_key);

    if(current_key == 'a')
        current_pause_state_option--;

    else if(current_key == 'd')
        current_pause_state_option++;

    if(current_pause_state_option > 3)
        current_pause_state_option = 3;

    else if(current_pause_state_option < 2)
        current_pause_state_option = 2;

}


void init_pause_state_shapes(State* state) {
}


void draw_pause_state(State* state) {


    int i = 0;

    for(int i = 0 ; i < state->total_shapes; i++)
        draw_shape(state->shapes[i]);

    for(i = 0 ; i < state->total_texts; i++)
        draw_text(state->texts[i]);


}

void init_pause_state_texts(State* state) {

    state->total_texts = 4;

    state->texts = (Text**)malloc(sizeof(Text) * state->total_texts);
    state->texts[PAUSE_STATE_GAME_PAUSE_TEXT] = create_text("Game Paused" , create_vector(500, 3500 ,0.0) , create_vector(1.0 , 3.0 , 3.0) , create_vector(1.0 , 1.0 , 1.0));


    char* score = (char*)malloc(sizeof(char)* 100);
    sprintf(score , "Score : %d" , stats->score);
    state->texts[PAUSE_STATE_SCORE_TEXT] = create_text(score, create_vector(500 , 3000 ,0.0) , create_vector(1.0 , 3.0 , 3.0) , create_vector(1.0 , 1.0 , 1.0));


    state->texts[PAUSE_STATE_CONTINUE_TEXT] = create_text("Continue", create_vector(-2000 , 2200 ,0.0) , create_vector(1.0 , 3.0 , 3.0) , create_vector(1.0 , 1.0 , 1.0));
    state->texts[PAUSE_STATE_QUIT_TEXT] = create_text("Quit", create_vector(3000, 2200 ,0.0) , create_vector(1.0 , 3.0 , 3.0) , create_vector(1.0 , 1.0 , 1.0));


}


void handle_pause_key_event( int* current_state_index , State* state , unsigned char current_key) {


    if(current_key == SPACEBAR) {

        if(current_pause_state_option == PAUSE_STATE_CONTINUE_TEXT)
            *current_state_index = GAME_STATE_INDEX;

        else if(current_pause_state_option == PAUSE_STATE_QUIT_TEXT){
            exit(2);
        }
    }
}
