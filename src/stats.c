#include "stats.h"
#include <stdlib.h>

Stats* create_stats() {

    Stats* stats = (Stats*)malloc(sizeof(Stats));
    stats->score = 0;
    stats->road_count = 0;
}
