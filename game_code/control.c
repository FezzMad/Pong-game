#include "control.h"
#include "constants.h"

void speedGameControl(char command, int *delay) {
    switch (command) {
        case '1': *delay = 190000; break;
        case '2': *delay = 160000; break;
        case '3': *delay = 130000; break;
        case '4': *delay = 100000; break;
        case '5': *delay = 70000; break;
        case '6': *delay = 40000; break;
        case '7': *delay = 10000; break;
        case '8': *delay = 7000; break;
        case '9': *delay = 4000;
    }
}

void ballControl(int *xBall, int *yBall, int *xDirectionBall, int *yDirectionBall, int yRacketRight, int yRacketLeft, int xRacketRight, int xRacketLeft, int sizeRacketLeft, int sizeRacketRight, int *scorePlayerRight, int *scorePlayerLeft) {
    (*xBall) += (*xDirectionBall);
    (*yBall) += (*yDirectionBall);
    if (*xBall <= 0) {
        (*scorePlayerRight)++;
    }
    if (*xBall >= X_MAX - 1) {
        (*scorePlayerLeft)++;
    }
    if (*xBall <= 0 || *xBall >= X_MAX - 1) {
        *xBall = X_MAX / 2;
        *yBall = Y_MAX / 2;
    }

    if ((*yBall >= yRacketLeft && *yBall < yRacketLeft + sizeRacketLeft && *xBall == xRacketLeft + 1)
        || (*yBall == yRacketLeft - 1 && *xBall == xRacketLeft + 1 && *yDirectionBall > 0)    // вверхний угол левой ракетки
        || (*yBall == yRacketLeft + 3 && *xBall == xRacketLeft + 1 && *yDirectionBall < 0)    // нижний угол левой ракетки
        || (*yBall >= yRacketRight && *yBall < yRacketRight + sizeRacketRight && *xBall == xRacketRight - 1)
        || (*yBall == yRacketRight - 1 && *xBall == xRacketRight - 1 && *yDirectionBall > 0)  // вверхний угол правой ракетки
        || (*yBall == yRacketRight + 3 && *xBall == xRacketRight - 1 && *yDirectionBall < 0)) // нижний угол правой ракетки
        (*xDirectionBall) *= (-1);
    if (*yBall == 0 || *yBall == Y_MAX - 1
        || (*yBall == yRacketRight - 1 && *xBall == xRacketRight - 1 && *yDirectionBall > 0)  // вверхний угол правой ракетки
        || (*yBall == yRacketRight + 3 && *xBall == xRacketRight - 1 && *yDirectionBall < 0)  // нижний угол правой ракетки
        || (*yBall == yRacketLeft - 1 && *xBall == xRacketLeft + 1 && *yDirectionBall > 0)    // вверхний угол левой ракетки
        || (*yBall == yRacketLeft + 3 && *xBall == xRacketLeft + 1 && *yDirectionBall < 0))   // нижний угол левой ракетки
        (*yDirectionBall) *= (-1);
}

void racketLeftControl(char command, int sizeRacketLeft, int *yRacketLeft) {
    switch (command) {
        case UP_RACKET_LEFT: {
            if (*yRacketLeft > 0)
                (*yRacketLeft)--;
            break;
        }
        case DOWN_RACKET_LEFT: {
            if (*yRacketLeft + sizeRacketLeft < Y_MAX)
                (*yRacketLeft)++;
        }
    }
}

void racketRightControl(char command, int sizeRacketRight, int *yRacketRight) {
    switch (command) {
        case UP_RACKET_RIGHT: {
            if (*yRacketRight > 0)
                (*yRacketRight)--;
            break;
        }
        case DOWN_RACKET_RIGHT: {
            if (*yRacketRight + sizeRacketRight < Y_MAX)
                (*yRacketRight)++;
        }
    }
}

void gameStateControl(char command, int *exit, int *pause) {
    switch (command) {
        case EXIT: {
            *exit = 1;
            break;
        }
        case PAUSE: {
            if (*pause)
                *pause = 0;
            else
                *pause = 1;
            break;
        }
    }
}

void gameControl(char command, int *exit, int *pause, int sizeRacketRight, int *yRacketRight, int sizeRacketLeft, int *yRacketLeft, int *xBall, int *yBall, int *xDirectionBall, int *yDirectionBall, int xRacketRight, int xRacketLeft, int *scorePlayerRight, int *scorePlayerLeft, int *delay) {
    command = toUpperCase(command);
    gameStateControl(command, exit, pause);
    speedGameControl(command, delay);
    if (!*pause) {
        racketLeftControl(command, sizeRacketLeft, yRacketLeft);
        racketRightControl(command, sizeRacketRight, yRacketRight);
        ballControl(xBall, yBall, xDirectionBall, yDirectionBall, *yRacketRight, *yRacketLeft, xRacketRight, xRacketLeft, sizeRacketLeft, sizeRacketRight, scorePlayerRight, scorePlayerLeft);
    }
    if (*scorePlayerLeft == SCORE_WIN || *scorePlayerRight == SCORE_WIN) *exit = 1;
}

char toUpperCase(char letter) {
    if (letter >= 'a' && letter <= 'z') {
        letter -= 32;
    }
    return letter;
}
