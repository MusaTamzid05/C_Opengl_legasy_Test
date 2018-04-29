#include "game.h"

#include <time.h>
#include <stdlib.h>


int main(int argc , char** argv) {


    srand((unsigned int)time(NULL));
    run_game(argc , argv , 640 , 480 , "Game" , 25);
    

    return 0;
}
