#pragma once

// 雷区地雷
# define MINE '1'

// 扫描标志
# define FOG_ZONE '*'

// 战场大小
# define ROW 9
# define COL 9

# define ROWS ROW+2
# define COLS COL+2

// 战场地雷数
# define LANDMINE_SIZE (ROW*COL)/9


// 初始化地雷
void initMine(char mine[ROWS][COLS], int row, int col);

// 初始化地图
void initShow(char show[ROWS][COLS]);

// 打印地图
void displayShow(char show[ROWS][COLS]);

// 玩家进行挖地雷并显示地雷
int playerScan(char mine[ROWS][COLS], char show[ROWS][COLS]);

// 计算周围的地雷数
char getRoundMineSize(char mine[ROWS][COLS], int x, int y);

// 计算剩余的未排雷区
int getFogZone(char show[ROWS][COLS]);