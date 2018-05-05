#include "game_state.h"
#include "const.h"
#include "stats.h"
#include "player.h"
#include <stdlib.h>
#include "road.h"
#include <stdio.h>
#include "collision_detector.h"
#include "vertex.h"


State* create_game_state() {

    State* state = (State*)malloc(sizeof(State));
    init_game_state_shapes(state);

    state->update_state_ptr = update_game_state;
    state->draw_state_ptr = draw_game_state;
    init_game_state_texts(state);
    return state;
}


void init_game_state_texts(State* state) {

    int total_texts = 4;
    state->total_texts = total_texts;
    state->texts = (Text**)malloc(sizeof(Text) * total_texts);
    
    state->texts[0] = create_text("Press 'a' to go left." , create_vector(-5500 , 4500 ,0.0) , create_vector(1.0 , 1.0 , 1.0) , create_vector(1.0 , 1.0 , 1.0));

    state->texts[1] = create_text("Press 'd' to go right." , create_vector(-5500 , 4300 ,0.0) , create_vector(1.0 , 1.0 , 1.0) , create_vector(1.0 , 1.0 , 1.0));

    state->texts[2] = create_text("Press 'space' to jump." , create_vector(-5500 , 4100 ,0.0) , create_vector(1.0 , 1.0 , 1.0) , create_vector(1.0 , 1.0 , 1.0));



    char* score = (char*)malloc(sizeof(char)* 100);
    sprintf(score , "Score : %d" , stats->score);
    state->texts[SCORING_GAME_STATE_INDEX] = create_text(score, create_vector(-5500 , 3600 ,0.0) , create_vector(2.0 , 3.0 , 1.0) , create_vector(1.0 , 1.0 , 1.0));

}

void update_game_state( int* current_state_index , State* state , unsigned char current_key) {


    int i = 0;

    for(int i = 0 ; i < state->total_shapes; i++){
        state->shapes[i]->update_func_ptr(state->shapes[i] , current_key);
    }

    collision_detector(state->shapes[PLAYER_INDEX]  , road_rects);
    update_game_state_score(state);

    if(current_key == 'p') 
        *current_state_index = PAUSE_STATE_INDEX;

}


void init_game_state_shapes(State* state) {



    int total_shapes = 2;
    state->total_shapes = total_shapes;

    state->shapes = (Shape**)malloc(sizeof(Shape) * total_shapes);


    state->shapes[PLAYER_INDEX] = create_player();
    state->shapes[PLAYER_INDEX]->update_func_ptr = update_player;
    state->shapes[ROAD_INDEX] = create_road();
    state->shapes[ROAD_INDEX]->update_func_ptr= update_road;

    stats = create_stats();

}

void draw_game_state(State* state) {

    glClearColor(0.0 , 0.0 , 0.0 , 0.0);

    int i = 0;

    for(int i = 0 ; i < state->total_shapes; i++)
        draw_shape(state->shapes[i]);

    for(i = 0 ; i < state->total_texts; i++)
        draw_text(state->texts[i]);

}


void update_game_state_score(State* state) {

    if(stats->score <= 0) 
        state->texts[SCORING_GAME_STATE_INDEX]->color = create_vector(1.0 , 0.0 , 0.0);

    else
        state->texts[SCORING_GAME_STATE_INDEX]->color = create_vector(0.0 , 1.0 , 0.0);


    sprintf(state->texts[3]->str, "Score : %d" , stats->score);

}
