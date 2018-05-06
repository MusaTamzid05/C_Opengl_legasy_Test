#ifndef GAME_OVER_STATE_H
#define GAME_OVER_STATE_H

#include "state.h"

State* create_game_over_state();
void update_game_over_state( int* current_state_index , State* state , unsigned char current_key);


void handle_game_over_key_event( int* current_state_index , State* state , unsigned char current_key);

void init_game_over_state_shapes(State* state);
void draw_game_over_state(State* state);

void init_game_over_state_texts(State* state);

#endif
