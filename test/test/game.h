#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3
void Initboard(char board[ROW][COL],int row,int col);//���̿ո���
void Displayboar(char board[ROW][COL], int row, int col);//��ӡ���̿�ܽ���
void Computermove(char board[ROW][COL], int row, int col);//������Ϸ����
void Playermove(char board[ROW][COL], int row, int col);//�����Ϸ����
char Iswin(char board[ROW][COL], int row, int col);//ʤ���ж�