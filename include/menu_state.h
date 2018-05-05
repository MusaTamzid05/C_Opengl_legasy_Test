#ifndef MENU_STATE_H
#define MENU_STATE_H



#include "state.h"

State* create_menu_state();
void update_menu_state( int* current_state_index , State* state , unsigned char current_key);


void init_menu_state_shapes(State* state);
void draw_menu_state(State* state);

void init_menu_state_texts(State* state);

void update_menu_state_option( State* state , unsigned char current_key);

void handle_menu_key_event(int* current_state_index , State* state , unsigned char current_key);


#endif
