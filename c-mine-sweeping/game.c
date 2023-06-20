# define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
# include "game.h"

// ������ͼ
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
		mine[x][y] = MINE; // �����
		--size;
	}

}

// ��ʼ����ͼ
void initShow(char show[ROWS][COLS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			show[i][j] = FOG_ZONE;
		}
	}
}

// ��ӡ��ͼ
void displayShow(char show[ROWS][COLS]) {

	for (int i = 1; i < ROWS - 1; i++) {
		for (int j = 1; j < COLS - 1; j++) {
			printf("%c ", show[i][j]);
		}
		printf("\n");
	}
}


// ��ҽ����ڵ��ײ���ʾ����
int playerScan(char mine[ROWS][COLS], char show[ROWS][COLS]) {

	int x, y;
	while (1) {
		printf("���������ɨ�������\n");
		scanf("%d %d", &x, &y);
		if (x < 0 || x > ROW || y<0 || y>COL) {
			printf("����Խ��Ƿ���������ѡ��ɨ������\n");
			continue;
		}

		if (show[x][y] != FOG_ZONE) {
			printf("�������Ѿ���ɨ����ˣ�������ѡ��ɨ������\n");
			continue;
		}
		break;
	}

	if (mine[x][y] == MINE) {
		displayShow(show);
		printf("�㱻���׸�ը���ˣ�\n");
		return 1;
	}

	// ������Χ�ĵ�����
	show[x][y] = getRoundMineSize(mine, x, y);

	// ��ӡ��ҵ�ͼ
	displayShow(show);

	// ����ʣ���δ������
	if (getFogZone(show) == LANDMINE_SIZE) {
		printf("����ȫ����ɨ������ˣ���һ�ʤ��\n");
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