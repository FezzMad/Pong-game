#ifndef SRC_DRAW_H_
#define SRC_DRAW_H_

void drawGame(int xBall, int yBall, int xRacketRight, int yRacketRight, int xRacketLeft, int yRacketLeft, int sizeRacketLeft, int sizeRacketRight, int (*print)(const char *format, ...));
void frame(int (*print)(const char *format, ...));
void drawScore(int scorePlayerRight, int scorePlayerLeft, int (*print)(const char *format, ...));

#endif  // SRC_DRAW_H_
