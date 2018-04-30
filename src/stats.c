#include "stats.h"
#include <stdlib.h>
#include "const.h"


Stats* create_stats() {

    Stats* stats = (Stats*)malloc(sizeof(Stats));
    stats->score = 0;
    stats->road_count = 0;
}


void update_score(int object_index) {

    if(object_index == SPHERE_OBJECT)
        stats->score += SPHERE_SCORE;

    else if(object_index == CUBE_OBJECT)
        stats->score += CUBE_SCORE;

    else if(object_index == CONE_OBJECT)
        stats->score += CONE_SCORE;



    else if(object_index == DANGER_SPHERE_OBJECT) 
        stats->score -= SPHERE_SCORE;

    else if(object_index == DANGER_CUBE_OBJECT)
        stats->score -= CUBE_SCORE;


    else if(object_index == DANGER_CONE_OBJECT)
        stats->score -= CONE_SCORE;
}
