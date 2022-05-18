#define _CRT_SECURE_NO_WARNINGS 1
#include "Contest.h"

void menu()
{
	printf("**********************************************\n");
	printf("******* 1.add           2.del        *********\n");
	printf("******* 3.search        4.modify     *********\n");
	printf("******* 5.show          6.sort       *********\n");
	printf("******* 7.save          0.exit       *********\n");
	printf("**********************************************\n");
}
int main()
{
	int input = 0;
	//创建通讯录
	int size = 0;
	Contact con;//con就是通讯录，里面包含：data指针和size，capacity
	//初始化通讯录
	Initcontact(&con);

	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			Addcontact(&con);
				break;
		case DEL:
			Delcontact(&con);
			break;
		case SEARCH:
			Searchcontact(&con);
			break;
		case MODIFY:
			Modifycontact(&con);
			break;
		case SHOW:
			Showcontact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case SAVE:
			Savecontact(&con);
			break;
		case EXIT:
			Destorycontact(&con);
			Savecontact(&con);
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}