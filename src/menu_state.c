#include "menu_state.h"
#include <stdlib.h>
#include <stdio.h>
#include "const.h"


int current_menu_option = 1;
int previous_menu_option = 1;

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


    int total_texts = 9;
    state->total_texts = total_texts;
    state->texts = (Text**)malloc(sizeof(Text) * total_texts);


    state->texts[0] = create_text("Press 'Space' to select. 'w' and 's' to move" , create_vector(-3000.0f , 0.0f ,0.0) , create_vector(2.0 , 2.0 , 1.0) , create_vector(1.0 , 1.0 , 1.0));
    state->texts[MENU_STATE_START_INDEX] = create_text("Start Game" , create_vector(0.0f , -500.0f ,0.0) , create_vector(2.0 , 2.0 , 1.0) , create_vector(1.0 , 1.0 , 1.0));
    state->texts[MENU_STATE_EXIT_INDEX] = create_text("Exit Game" , create_vector(0.0f , -900.0f ,0.0) , create_vector(2.0 , 2.0 , 1.0) , create_vector(1.0 , 1.0 , 1.0));
   
    char* score = (char*)malloc(sizeof(char) * 100);
    sprintf(score , "Random Color  Sphere %d. " , SPHERE_SCORE);
    state->texts[3] = create_text(score, create_vector(-5000 , 4000.0f ,0.0) , create_vector(2.0 , 2.0 , 1.0) , create_vector(1.0 , 1.0 , 1.0)); 



    char* score1 = (char*)malloc(sizeof(char) * 100);
    sprintf(score1 , "Random Color Cube %d. " , CUBE_SCORE);
    state->texts[4] = create_text(score1 , create_vector(-5000 , 3500.0f ,0.0) , create_vector(2.0 , 2.0 , 1.0) , create_vector(1.0 , 1.0 , 1.0)); 


    char* score2 = (char*)malloc(sizeof(char) * 100);
    sprintf(score2 , "Random Color Cone %d. " , CONE_SCORE);
    state->texts[5] = create_text(score2 , create_vector(-5000 , 3000.0f ,0.0) , create_vector(2.0 , 2.0 , 1.0) , create_vector(1.0 , 1.0 , 1.0)); 


    char* score3= (char*)malloc(sizeof(char) * 100);
    sprintf(score3 , "Pink Color Sphere -%d. " , SPHERE_SCORE);
    state->texts[6] = create_text(score3, create_vector(1000 , 4000.0f ,0.0) , create_vector(2.0 , 2.0 , 1.0) , create_vector(DANGER_OBJECT_COLOR_RED , DANGER_OBJECT_COLOR_GREEN , DANGER_OBJECT_COLOR_BLUE)); 


    char* score4= (char*)malloc(sizeof(char) * 100);
    sprintf(score4 , "Pink Color Cube -%d. " , CUBE_SCORE);
    state->texts[7] = create_text(score4 , create_vector(1000 , 3500.0f ,0.0) , create_vector(2.0 , 2.0 , 1.0) , create_vector(DANGER_OBJECT_COLOR_RED , DANGER_OBJECT_COLOR_GREEN , DANGER_OBJECT_COLOR_BLUE));


    char* score5 = (char*)malloc(sizeof(char) * 100);
    sprintf(score5 , "Pink Color Cone -%d. " , CONE_SCORE);
    state->texts[8] = create_text(score5 , create_vector(1000 , 3000.0f ,0.0) , create_vector(2.0 , 2.0 , 1.0) , create_vector(DANGER_OBJECT_COLOR_RED , DANGER_OBJECT_COLOR_GREEN , DANGER_OBJECT_COLOR_BLUE)); 



}
void update_menu_state_option(State* state , unsigned char current_key) {


    int i = 0;

    for(i = 0 ; i < state->total_texts; i++) {

        if(i == current_menu_option) 
            state->texts[i]->color = create_vector(1.0 , 1.0 , 0.0);

        else if(i == previous_menu_option) 
            if(previous_menu_option != current_menu_option)
                state->texts[i]->color = create_vector(1.0 , 1.0 , 1.0);
        
        
        else
            state->texts[i]->color = create_vector(state->texts[i]->color->x , state->texts[i]->color->y , state->texts[i]->color->z);

    }

    if(current_key == 's') {
        previous_menu_option = current_menu_option;
        current_menu_option++;
    }

    else if (current_key == 'w') {

        previous_menu_option = current_menu_option;
        current_menu_option--;
    }

    if(current_menu_option < MENU_STATE_START_INDEX)
        current_menu_option = MENU_STATE_START_INDEX;

    else if(current_menu_option > MENU_STATE_EXIT_INDEX)
        current_menu_option = MENU_STATE_EXIT_INDEX;

}


void handle_menu_key_event(int* current_state_index , State* state , unsigned char current_key) {

    if(current_key == SPACEBAR) {

        if(current_menu_option == MENU_STATE_START_INDEX) {
            *current_state_index = GAME_STATE_INDEX;
        }

        else if(current_menu_option == MENU_STATE_EXIT_INDEX) {
            exit(1);
        }

    }
}
