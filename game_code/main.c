#include <ncurses.h>
#include <stdio.h>
#include <unistd.h>

#include "control.h"
#include "constants.h"
#include "draw.h"



int main() {
    int delay = 70000;
    
    int sizeRacketLeft = 3;
    int sizeRacketRight = 3;
    
    int yRacketLeft = Y_MAX/2 - sizeRacketLeft / 2;
    int yRacketRight = Y_MAX/2 - sizeRacketRight / 2;
    int xRacketLeft = 0;
    int xRacketRight = X_MAX - 1;
    int xBall = X_MAX / 2;
    int yBall = Y_MAX / 2;
    
    int xDirectionBall = -1;
    int yDirectionBall = 1;
    
    int exit = 0;
    int pause = 0;
    
    int scorePlayerLeft = 0;
    int scorePlayerRight = 0;

    initscr();
    noecho();
    nodelay(stdscr, true);
    
    
    while (!exit) {
        refresh();
        clear();
        drawScore(scorePlayerRight, scorePlayerLeft, printw);
        frame(printw);
        drawGame(xBall, yBall, xRacketRight, yRacketRight, xRacketLeft, yRacketLeft, sizeRacketLeft, sizeRacketRight, printw);
        frame(printw);
        gameControl(getch(), &exit, &pause, sizeRacketRight, &yRacketRight, sizeRacketRight, &yRacketLeft, &xBall, &yBall, &xDirectionBall, &yDirectionBall, xRacketRight, xRacketLeft, &scorePlayerRight, &scorePlayerLeft, &delay);
        usleep(delay);
    }

    endwin();
    
    return 0;
}


