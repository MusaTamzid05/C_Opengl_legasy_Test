#include "game.h"

#include <time.h>
#include <stdlib.h>


int main(int argc , char** argv) {

    int total_road;

    if(argc == 1)
        total_road = 5;

    else
        total_road = atoi(argv[1]);


    srand((unsigned int)time(NULL));
    run_game(argc , argv , 640 , 480 , "Game" , 25 , total_road);
    

    return 0;
}
