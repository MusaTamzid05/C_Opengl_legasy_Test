#ifndef STATS_H
#define STATS_H

typedef struct Stats {

    int score;
    int road_count;
} Stats;

Stats* stats;
Stats* create_stats();
#endif
