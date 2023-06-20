# define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
# include "game.h"

// 雷区地图
void initMine(char mine[ROWS][COLS], int row, int col) {

	int size = LANDMINE_SIZE;

	while (size) {
		int x = rand() % ROWS;
		int y = rand() % COLS;

		if (x == 0 || x == ROWS - 1 || y == 0 || y == COLS - 1) {
			continue;
		}

		if (mine[x][y] == MINE) {
			continue;
		}
		mine[x][y] = MINE; // 埋地雷
		--size;
	}

}

// 初始化地图
void initShow(char show[ROWS][COLS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			show[i][j] = FOG_ZONE;
		}
	}
}

// 打印地图
void displayShow(char show[ROWS][COLS]) {

	for (int i = 1; i < ROWS - 1; i++) {
		for (int j = 1; j < COLS - 1; j++) {
			printf("%c ", show[i][j]);
		}
		printf("\n");
	}
}


// 玩家进行挖地雷并显示地雷
int playerScan(char mine[ROWS][COLS], char show[ROWS][COLS]) {

	int x, y;
	while (1) {
		printf("玩家请输入扫描的坐标\n");
		scanf("%d %d", &x, &y);
		if (x < 0 || x > ROW || y<0 || y>COL) {
			printf("坐标越界非法，请重新选择扫描坐标\n");
			continue;
		}

		if (show[x][y] != FOG_ZONE) {
			printf("该坐标已经有扫描过了，请重新选择扫描坐标\n");
			continue;
		}
		break;
	}

	if (mine[x][y] == MINE) {
		displayShow(show);
		printf("你被地雷给炸死了！\n");
		return 1;
	}

	// 计算周围的地雷数
	show[x][y] = getRoundMineSize(mine, x, y);

	// 打印玩家地图
	displayShow(show);

	// 计算剩余的未排雷区
	if (getFogZone(show) == LANDMINE_SIZE) {
		printf("地雷全部被扫描出来了，玩家获胜！\n");
		return 1;
	}
	return 0;
}

char getRoundMineSize(char mine[ROWS][COLS], int x, int y) {
	char result = '0';

	if (mine[x - 1][y - 1] == MINE) ++result;
	if (mine[x - 1][y] == MINE) ++result;
	if (mine[x - 1][y + 1] == MINE) ++result;
	if (mine[x][y - 1] == MINE) ++result;
	if (mine[x][y + 1] == MINE) ++result;
	if (mine[x + 1][y - 1] == MINE) ++result;
	if (mine[x + 1][y] == MINE) ++result;
	if (mine[x + 1][y + 1] == MINE) ++result;

	return result;
}

int getFogZone(char show[ROWS][COLS]) {
	int result = 0;
	for (int i = 1; i < ROWS - 1; i++) {
		for (int j = 1; j < COLS - 1; j++) {
			if (show[i][j] == FOG_ZONE) {
				++result;
			}
		}
	}

	return result;
}