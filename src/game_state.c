#include "game_state.h"
#include "const.h"
#include "stats.h"
#include "player.h"
#include <stdlib.h>
#include "road.h"
#include <stdio.h>
#include "collision_detector.h"

State* create_game_state() {

    State* state = (State*)malloc(sizeof(State));
    init_game_state_shapes(state);

    state->update_state_ptr = update_game_state;
    state->draw_state_ptr = draw_game_state;
    return state;
}


void update_game_state(State* state , unsigned char current_key) {


    int i = 0;

    for(int i = 0 ; i < state->total_shapes; i++){
        state->shapes[i]->update_func_ptr(state->shapes[i] , current_key);
    }

    collision_detector(state->shapes[PLAYER_INDEX]  , road_rects);
    printf("Score : %d\n" , stats->score);


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


    int i = 0;

    for(int i = 0 ; i < state->total_shapes; i++)
        draw_shape(state->shapes[i]);

}
