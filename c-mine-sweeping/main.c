# define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
# include "game.h"

void menu() {

	printf("****************************************\n");
	printf("**********  1��play   0��exit  *********\n");
	printf("****************************************\n");

}


void game() {
	// ������ͼ
	char mine[ROWS][COLS] = { 0 };
	// ��ҵ�ͼ
	char show[ROWS][COLS] = { 0 };

	// ��ʼ��������ͼ����ҵ�ͼ
	initMine(mine, ROWS, COLS);
	initShow(show, ROWS, COLS);

	// ��ӡ��ҵ�ͼ
	displayShow(show);


	while (1) {
		// ��ҽ����ڵ��ײ���ʾ����
		if (playerScan(mine, show)) break;
	}

}

int main() {

	int x, y, print = 0;

	do {
		menu();
		printf("��ѡ��\n");
		printf("��ʼ��Ϸ��1\n");
		printf("�˳���Ϸ��0\n");
		scanf("%d", &print);
		switch (print) {
		case 0:
			print = 0;
			break;
		case 1:
			game();
			break;
		default:
			printf("����ѡ��\n");
			break;
		}

	} while (print);


	return 0;
}


