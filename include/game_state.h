#ifndef GAME_STATE_H
#define GAME_STATE_H


#include "state.h"

State* create_game_state();
void update_game_state(State* state , unsigned char current_key);


void init_game_state_shapes(State* state);
void draw_game_state(State* state);

#endif
