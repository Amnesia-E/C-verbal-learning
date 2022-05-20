#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()//准备部分
{
	printf("**********************\n");
	printf("*****1.play 0.exit ***\n");
	printf("**********************\n");
}
void game()//键盘组装
{   
	char ret = 0;
	char board[ROW][COL] = { 0 };
	Initboard(board, ROW, COL);
	Displayboar(board, ROW, COL);
	while (1)//游戏运行部分
	{
		Playermove(board, ROW, COL);
		Displayboar(board, ROW, COL);
		ret = Iswin(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
		Computermove(board, ROW, COL);
		Displayboar(board, ROW, COL);
		ret = Iswin(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择>--");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			printf("三子棋\n");
			break;
		case 0:
			printf("退出游戏...exit...\n");
			break;
		default:
			printf("输入错误，请重新输入！\n");
		}
	} while (input);
	return 0;
}

