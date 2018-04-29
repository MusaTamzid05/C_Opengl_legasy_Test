#include "util.h"
#include <stdlib.h>

float limit_range(float value , float max_value , float min_value) {

    if(value > max_value)
        value = max_value;

    else if(value < min_value)
        value = min_value;

    return value;
}


float generate_random(float max) {

    return ((float)rand() / (float)(RAND_MAX)) * max;
}
