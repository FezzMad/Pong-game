# Pong game
Simple [Pong game](https://en.wikipedia.org/wiki/Pong) on C language for terminal Linux.

## Libraries
- [`ncurses`](https://en.wikipedia.org/wiki/Ncurses) - for real-time mode
- [`unistd`](https://en.wikipedia.org/wiki/Unistd.h) - for the delay between cards in microseconds
- [`stdio`](https://www.tutorialspoint.com/c_standard_library/stdio_h.htm) - for other primitive actions (e. g. printf())

## Compilation
Go to the Pong-game folder and enter in the terminal:
```
make
```
Compiled by Pong_game. Run Pong_game in the terminal:
```
./Pong_game
```
## Gameplay
To move the left racket, use the keys `'A'` and `'Z'` ('a' and 'z'), for the right - `'K'` and `'M'` ('k' and 'm'). To pause the game, you need to press the `space` bar. To exit the game, you need to press `ESC` or wait for one of the players to win. In the game you can change the speed using the keys `'1'` , `'2'`, `'3'`, .. ,`'0'`.

With standard settings, the game ends when one of the players scores seven points.
> Since only one input stream is used, when holding the control keys of the racket or when pressing intensively, the racket can move for some time by "inertia".


![glider_emblem](materials/gameplay.gif)

## Settings
If you want to change drawing symbols, size of field, control keys or the final score to win, you can do it in ***constants.h***.

Drawing management

```
#define SCORE_WIN 7
#define RACKET_LEFT ']'
#define RACKET_RIGHT '['
#define FIELD ' '
#define WALL '='
#define BALL 'o'
#define MIDDLE_WALL '|'
#define FRAME '-'
#define Y_MAX 20
#define X_MAX 80
```
Game management
```
#define EXIT 27  // ESC
#define PAUSE 32  // SPACE
#define UP_RACKET_LEFT 'A'
#define DOWN_RACKET_LEFT 'Z'
#define UP_RACKET_RIGHT 'K'
#define DOWN_RACKET_RIGHT 'M'
```