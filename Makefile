pong: game_code/*.c
	gcc -o Pong_game game_code/*.c -lncurses

clean:
	rm -rf Pong_game
