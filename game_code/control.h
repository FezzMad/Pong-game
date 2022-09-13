#ifndef SRC_CONTROL_H_
#define SRC_CONTROL_H_
 
void gameControl(char command, int *exit, int *pause, int sizeRacketRight, int *yRacketRight, int sizeRacketLeft, int *yRacketLeft, int *xBall, int *yBall, int *xDirectionBall, int *yDirectionBall, int xRacketRight, int xRacketLeft, int *scorePlayerRight, int *scorePlayerLeft, int *delay);
void gameStateControl(char command, int *exit, int *pause);
void racketLeftControl(char command, int sizeRacketLeft, int *yRacketLeft);
void racketRightControl(char command, int sizeRacketRight, int *yRacketRight);
void ballControl(int *xBall, int *yBall, int *xDirectionBall, int *yDirectionBall, int yRacketRight, int yRacketLeft, int xRacketRight, int xRacketLeft, int sizeRacketLeft, int sizeRacketRight, int *scorePlayerRight, int *scorePlayerLeft);
void speedGameControl(char command, int *delay);
char toUpperCase(char letter);

#endif  // SRC_CONTROL_H_
