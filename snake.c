#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int i, j, length = 20, width = 20;
int gameover, score;
int x, y, food1, food2, move;
void showinstructions(){
    printf("\t\t\t###################### \n\t\t\t#    SNAKE GAME      #\n\t\t\t#    By Jaswanth     #\n\t\t\t######################\n\n\n");
    printf(">Eat the food to score points\n\n");
    printf(">Use the W,A,S,D keys to move\n\n");
    printf(">W moves you up,A moves you to the left,S moves you down,D moves you to the right\n\n");
    printf(">Get ready to start the game!!!\n\n");
    printf(">Remember, if you hit the wall the game automatically ends!!!");
    return;
}
void setup()
{
    showinstructions();
	gameover = 0;
	x = length / 2;
	y = width / 2;
label1:
	food1 = rand() % 20;
	if (food1 == 0)
		goto label1;
label2:
	food2 = rand() % 20;
	if (food2 == 0)
		goto label2;
	score = 0;
}
void draw()
{
	system("cls");
	for (i = 0; i < length; i++) {
		for (j = 0; j < width; j++) {
			if (i == 0 || i == width - 1
				|| j == 0
				|| j == length - 1) {
				printf("#");
			}
			else {
				if (i == x && j == y)
					printf("^");
				else if (i == food1
						&& j == food2)
					printf("@");
				else
					printf(" ");
			}
		}
		printf("\n");
	}
	printf("score = %d", score);
	printf("\n");
	printf("press X to quit the game");
}
void input()
{
	if (kbhit()) {
		switch (getch()) {
		case 'a':
			move = 1;
			break;
		case 's':
			move = 2;
			break;
		case 'd':
			move = 3;
			break;
		case 'w':
			move = 4;
			break;
		case 'x':
			gameover = 1;
			break;
		}
	}
}
void algorithm()
{
	sleep(0.01);
	switch (move) {
	case 1:
		y--;
		break;
	case 2:
		x++;
		break;
	case 3:
		y++;
		break;
	case 4:
		x--;
		break;
	default:
		break;
	}
	if (x < 0 || x > length
		|| y < 0 || y > width)
		gameover = 1;
	if (x == food1 && y == food2) {
	label3:
		food1 = rand() % 20;
		if (food1 == 0)
			goto label3;
	label4:
		food2 = rand() % 20;
		if (food2 == 0)
			goto label4;
		score += 10;
	}
}
void main()
{
    showinstructions();
    sleep(8);
	int m, n;
	setup();
	while (!gameover) {
		draw();
		input();
		algorithm();
	}
}

