#include "draw.h"
#include "constants.h"

void drawGame(int xBall, int yBall, int xRacketRight, int yRacketRight, int xRacketLeft, int yRacketLeft, int sizeRacketLeft, int sizeRacketRight, int (*print)(const char *format, ...)) {
    for (int y = 0; y < Y_MAX; y++) {
        int hasRacketLeft = 0;
        int hasRacketRight = 0;
        int hasBall = 0;
        int hasMiddleWall = 0;
        for (int x = 0; x < X_MAX; x++) {
            if (x == xBall && y == yBall && x == X_MAX - 1) {
                print("%c\n", BALL);
                hasBall = 1;
            } else if (x == xBall && y == yBall) {
                print("%c", BALL);
                hasBall = 1;
            }
            if (x == X_MAX / 2 && !hasBall) {
                print("%c", MIDDLE_WALL);
                hasMiddleWall = 1;
            }
            if (y >= yRacketLeft && y < yRacketLeft + sizeRacketLeft && x == xRacketLeft) {
                print("%c", RACKET_LEFT);
                hasRacketLeft = 1;
            }
            if (y >= yRacketRight && y < yRacketRight + sizeRacketRight && x == xRacketRight) {
                print("%c\n", RACKET_RIGHT);
                hasRacketLeft = 1;
            }
            if (!hasBall && !hasRacketLeft && !hasRacketRight && x == X_MAX - 1) {
                print("%c\n", FIELD);
            } else if (!hasBall && !hasRacketLeft && !hasRacketRight && !hasMiddleWall) {
                print("%c", FIELD);
            }
            hasRacketLeft = 0;
            hasRacketRight = 0;
            hasBall = 0;
            hasMiddleWall = 0;
        }
    }
}

void frame(int (*print)(const char *format, ...)) {
    for (int x = 0; x < X_MAX; x++) {
        print("%c", FRAME);
    }
    print("\n");
}

void drawScore(int scorePlayerRight, int scorePlayerLeft, int (*print)(const char *format, ...)) {
    for (int i = 0; i < (X_MAX / 2) - 2; i++)
        print(" ");
    print("%2d:%-2d",scorePlayerLeft, scorePlayerRight);
    for (int i = 0; i < (X_MAX / 2) - 5 / 2 - 1; i++)
        print(" ");
    print("\n");
}
