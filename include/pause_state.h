#ifndef PAUSE_STATE_H
#define PAUSE_STATE_H


#include "state.h"

State* create_pause_state();
void update_pause_state( int* current_state_index , State* state , unsigned char current_key);


void init_pause_state_shapes(State* state);
void draw_pause_state(State* state);

void init_pause_state_texts(State* state);

#endif
