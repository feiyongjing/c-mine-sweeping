# define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
# include "game.h"

void menu() {

	printf("****************************************\n");
	printf("**********  1、play   0、exit  *********\n");
	printf("****************************************\n");

}


void game() {
	// 雷区地图
	char mine[ROWS][COLS] = { 0 };
	// 玩家地图
	char show[ROWS][COLS] = { 0 };

	// 初始化雷区地图和玩家地图
	initMine(mine, ROWS, COLS);
	initShow(show, ROWS, COLS);

	// 打印玩家地图
	displayShow(show);


	while (1) {
		// 玩家进行挖地雷并显示地雷
		if (playerScan(mine, show)) break;
	}

}

int main() {

	int x, y, print = 0;

	do {
		menu();
		printf("请选择\n");
		printf("开始游戏按1\n");
		printf("退出游戏按0\n");
		scanf("%d", &print);
		switch (print) {
		case 0:
			print = 0;
			break;
		case 1:
			game();
			break;
		default:
			printf("错误选择\n");
			break;
		}

	} while (print);


	return 0;
}


