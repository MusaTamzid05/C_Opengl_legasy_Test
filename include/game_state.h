#ifndef GAME_STATE_H
#define GAME_STATE_H


#include "state.h"

State* create_game_state();
void update_game_state( int* current_state_index ,  State* state , unsigned char current_key);


void init_game_state_shapes(State* state);
void draw_game_state(State* state);

void init_game_state_texts(State* state);

void update_game_state_score(State* state);
#endif
