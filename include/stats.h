#ifndef STATS_H
#define STATS_H

typedef struct Stats {

    int score;
    int road_count;
    int total_road;
} Stats;

Stats* stats;
Stats* create_stats(int total_road);

void update_score(int object_index);
#endif
