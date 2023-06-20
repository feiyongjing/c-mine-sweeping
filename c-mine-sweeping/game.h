#pragma once

// ��������
# define MINE '1'

// ɨ���־
# define FOG_ZONE '*'

// ս����С
# define ROW 9
# define COL 9

# define ROWS ROW+2
# define COLS COL+2

// ս��������
# define LANDMINE_SIZE (ROW*COL)/9


// ��ʼ������
void initMine(char mine[ROWS][COLS], int row, int col);

// ��ʼ����ͼ
void initShow(char show[ROWS][COLS]);

// ��ӡ��ͼ
void displayShow(char show[ROWS][COLS]);

// ��ҽ����ڵ��ײ���ʾ����
int playerScan(char mine[ROWS][COLS], char show[ROWS][COLS]);

// ������Χ�ĵ�����
char getRoundMineSize(char mine[ROWS][COLS], int x, int y);

// ����ʣ���δ������
int getFogZone(char show[ROWS][COLS]);