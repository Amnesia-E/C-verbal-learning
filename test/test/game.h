#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3
void Initboard(char board[ROW][COL],int row,int col);//棋盘空格建立
void Displayboar(char board[ROW][COL], int row, int col);//打印棋盘框架建立
void Computermove(char board[ROW][COL], int row, int col);//电脑游戏部分
void Playermove(char board[ROW][COL], int row, int col);//玩家游戏部分
char Iswin(char board[ROW][COL], int row, int col);//胜负判断