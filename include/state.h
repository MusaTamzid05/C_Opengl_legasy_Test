#ifndef STATE_H
#define STATE_H
#include "shape.h"

typedef struct State {

    int total_shapes;
    Shape** shapes;

    void (*update_state_ptr)(struct State* state ,   unsigned char current_key);
    void (*draw_state_ptr)(struct State* state);

}State;



#endif
