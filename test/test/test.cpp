#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()//׼������
{
	printf("**********************\n");
	printf("*****1.play 0.exit ***\n");
	printf("**********************\n");
}
void game()//������װ
{   
	char ret = 0;
	char board[ROW][COL] = { 0 };
	Initboard(board, ROW, COL);
	Displayboar(board, ROW, COL);
	while (1)//��Ϸ���в���
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
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��>--");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			printf("������\n");
			break;
		case 0:
			printf("�˳���Ϸ...exit...\n");
			break;
		default:
			printf("����������������룡\n");
		}
	} while (input);
	return 0;
}

