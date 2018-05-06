#include "game_over_state.h"

#include <stdlib.h>
#include "shape_data.h"
#include "move_data.h"

#include <stdio.h>
#include "stats.h"
#include "const.h"

int current_game_over_state_option = 2;

State* create_game_over_state() {


    State* state = (State*)malloc(sizeof(State));
    init_game_over_state_shapes(state);

    state->update_state_ptr = update_game_over_state;
    state->draw_state_ptr = draw_game_over_state;
    init_game_over_state_texts(state);
    return state;
}


void update_game_over_state( int* current_state_index , State* state , unsigned char current_key) {


    sprintf(state->texts[GAME_OVER_STATE_SCORE_TEXT]->str, "Score : %d" , stats->score);

    int i;

    for(i = GAME_OVER_STATE_NEW_GAME_TEXT; i <= GAME_OVER_STATE_EXIT_TEXT; i++) {

        if(i == current_game_over_state_option)
            state->texts[i]->color = create_vector(1.0 , 1.0 , 0.0);
        else
            state->texts[i]->color = create_vector(1.0 , 1.0 , 1.0);

    }

    handle_game_over_key_event(current_state_index , state , current_key);

    if(current_key == 'a')
        current_game_over_state_option--;

    else if(current_key == 'd')
        current_game_over_state_option++;

    if(current_game_over_state_option > GAME_OVER_STATE_EXIT_TEXT) current_game_over_state_option = GAME_OVER_STATE_EXIT_TEXT;

    else if(current_game_over_state_option < GAME_OVER_STATE_NEW_GAME_TEXT)
        current_game_over_state_option = GAME_OVER_STATE_NEW_GAME_TEXT;

}


void init_game_over_state_shapes(State* state) {
}


void draw_game_over_state(State* state) {


    int i = 0;

    for(int i = 0 ; i < state->total_shapes; i++)
        draw_shape(state->shapes[i]);

    for(i = 0 ; i < state->total_texts; i++)
        draw_text(state->texts[i]);


}

void init_game_over_state_texts(State* state) {

    state->total_texts = 4;

    state->texts = (Text**)malloc(sizeof(Text) * state->total_texts);
    state->texts[0] = create_text("Game Complete" , create_vector(500, 3500 ,0.0) , create_vector(1.0 , 3.0 , 3.0) , create_vector(1.0 , 1.0 , 1.0));


    char* score = (char*)malloc(sizeof(char)* 100);
    sprintf(score , "Score : %d" , stats->score);
    state->texts[GAME_OVER_STATE_SCORE_TEXT] = create_text(score, create_vector(500 , 3000 ,0.0) , create_vector(1.0 , 3.0 , 3.0) , create_vector(1.0 , 1.0 , 1.0));


    state->texts[GAME_OVER_STATE_NEW_GAME_TEXT] = create_text("New Game", create_vector(-2000 , 2200 ,0.0) , create_vector(1.0 , 3.0 , 3.0) , create_vector(1.0 , 1.0 , 1.0));
    
    state->texts[GAME_OVER_STATE_EXIT_TEXT] = create_text("Exit", create_vector(3000, 2200 ,0.0) , create_vector(1.0 , 3.0 , 3.0) , create_vector(1.0 , 1.0 , 1.0));


}


void handle_game_over_key_event( int* current_state_index , State* state , unsigned char current_key) {


    if(current_key == SPACEBAR) {

        if(current_game_over_state_option == GAME_OVER_STATE_NEW_GAME_TEXT)
            *current_state_index = NEW_GAME_STATE;

        else if(current_game_over_state_option == GAME_OVER_STATE_EXIT_TEXT){

            exit(2);
        }
    }
}
