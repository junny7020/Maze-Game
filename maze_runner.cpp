#include <stdio.h>
#include <windows.h>
#include<conio.h>
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

char title[20][51]{
};

char gameover[20][51]{
};

char gameclear[20][51]{
};




char map[20][51] = {
	{"11111111111111111111111111111111111111111111111111"},
	{"10000000000000000000000100000000000000000000000001"},
	{"10000000000000000000000100000000000000000000000001"},
	{"10001111100000000000000100000000000000000000000001"},
	{"10001000100000000010000100010001111111111111000001"},
	{"10001000100000000010000100010000000000010001000001"},
	{"10001000100000000010000100010000000000010001000001"},
	{"10001000100011111110000100010000000000010001000001"},
	{"10001000100000000010000100011111111100010001000001"},
	{"10001000100000000010000100000000000100010001000001"},
	{"10001000100000000010000100000000000100010001111111"},
	{"10001000111111100010000100000000000100010000000001"},
	{"10001000000000100010000100011111000100010000000001"},
	{"10001000000000100010000100010001000100010001000001"},
	{"10001000111111100010000100010001000100010001000001"},
	{"10001000000000000011111100010001000100010001000001"},
	{"10001000000000000000000000010001000100000001000001"},
	{"10p0100000000000000000000001000000010000000100g001"},
	{"10001000000000000000000000010000000100000001000001"},
	{"11111111111111111111111111111111111111111111111111"},
};

static int pw;
static int ph;

void drawTitle() {
	system("cls");
	int W, H;
	for (H = 0; H < 20; H++) {
		for (W = 0; W < 50; W++) {
			char temp = title[H][W];

			if (H == 3 && W == 4) {
				printf("     ■□■□■□■□■□■□■");
			}
			if (H == 4 && W == 4) {
				printf("     □■□■□■□■□■□■□");
			}
			if (H == 5 && W == 4) {
				printf("     ■■  MAZE  RUNNER  ■■■");
			}
			if (H == 6 && W == 4) {
				printf("     ■□■□■□■□■□■□■");
			}
			if (H == 7 && W == 4) {
				printf("     □■□■□■□■□■□■□");
			}
			if (H == 9 && W == 4) {
				printf("     Press any key to start!");
			}
			if (H == 11 && W == 4) {
				printf("     △ : UP");
			}
			if (H == 12 && W == 4) {
				printf("     ▽ : DOWN");
			}
			if (H == 13 && W == 4) {
				printf("     ◁ : LEFT");
				}
			if (H == 14 && W == 4) {
				printf("     ▷ : RIGHT");
			}
			if (H == 16 && W == 4) {
				printf("     Made by June Choi, Sungwook Choi ");
			}
			
		}
		printf("\n");
	}
};

void drawGameover() {
	system("cls");
	int W, H;
	for (H = 0; H < 20; H++) {
		for (W = 0; W < 50; W++) {
			char temp = gameover[H][W];

			if (H == 3 && W == 4) {
				printf("     ■■■■■■■■■■■■■");
			}
			if (H == 4 && W == 4) {
				printf("     ■                      ■");
			}
			if (H == 5 && W == 4) {
				printf("     ■     GAME  OVER!      ■");
			}
			if (H == 6 && W == 4) {
				printf("     ■                      ■");
			}
			if (H == 7 && W == 4) {
				printf("     ■■■■■■■■■■■■■");
			}
	

		}
		printf("\n");
	}
};

void drawGameclear() {
	system("cls");
	int W, H;
	for (H = 0; H < 20; H++) {
		for (W = 0; W < 50; W++) {
			char temp = gameover[H][W];

			if (H == 3 && W == 4) {
				printf("     ■■■■■■■■■■■■■");
			}
			if (H == 4 && W == 4) {
				printf("     ■                      ■");
			}
			if (H == 5 && W == 4) {
				printf("     ■       YOU WIN!       ■");
			}
			if (H == 6 && W == 4) {
				printf("     ■                      ■");
			}
			if (H == 7 && W == 4) {
				printf("     ■■■■■■■■■■■■■");
			}

		}
		printf("\n");
	}
};

void drawMap() {
	system("cls");
	int W, H;


	for (H = 0;H < 20; H++) {
		for (W = 0; W < 50; W++) {
			char temp = map[H][W];

			if (temp == '0') {
				printf("■");
			}
			else if (temp == '1') {
				printf("□");
			}
			else if (temp == 'p') {
				printf("▲");
				pw = W;
				ph = H;
			}
			else if (temp == 'k') {
				printf("▼");
				pw = W;
				ph = H;
			}
			else if (temp == 'i') {
				printf("◀");
				pw = W;
				ph = H;
			}
			else if (temp == 'u') {
				printf("▶");
				pw = W;
				ph = H;
			}
			else if (temp == 'g') {
				printf("♥");
			}
		}
		printf("\n");
	}
};




int main(void) {
	char up = '▲';
	char down = '▼';
	char left = '◀';
	char right = '▶';
	drawTitle();
	char any;
	while(1){
		any=_getch();
		drawMap();
		char c;
		while (1) {
			if (_kbhit()) {
				c = _getch();
				if (c == -32) {
					c = _getch();

					switch (c) {
					case LEFT:

						map[ph][pw] = '0';
						pw -= 1;
						if (map[ph][pw] == '1') {
							system("cls");
							drawGameover();
							system("pause");
							return 0;
						}
						else if (map[ph][pw] == 'g') {
							system("cls");
							drawGameclear();
							system("pause");
							return 0;
						}
						map[ph][pw] = 'i';
						break;
					case RIGHT:
						map[ph][pw] = '0';
						pw += 1;
						if (map[ph][pw] == '1') {
							system("cls");
							drawGameover();
							system("pause");
							return 0;
						}
						else if (map[ph][pw] == 'g') {
							system("cls");
							drawGameclear();
							system("pause");
							return 0;
						}
						map[ph][pw] = 'u';
						break;
					case UP:
						map[ph][pw] = '0';
						ph -= 1;
						if (map[ph][pw] == '1') {
							system("cls");
							drawGameover();
							system("pause");
							return 0;
						}
						else if (map[ph][pw] == 'g') {
							system("cls");
							drawGameclear();
							system("pause");
							return 0;
						}
						map[ph][pw] = 'p';
						break;


					case DOWN:
						map[ph][pw] = '0';
						ph += 1;
						if (map[ph][pw] == '1') {
							system("cls");
							drawGameover();
							system("pause");
							return 0;
						}
						else if (map[ph][pw] == 'g') {
							system("cls");
							drawGameclear();
							system("pause");
							return 0;
						}
						map[ph][pw] = 'k';
						break;
					}
				}
				drawMap();
			}
		}
		return 0;
		if (_kbhit() == 1) 
			break;
		
	}

	
	
	
}



