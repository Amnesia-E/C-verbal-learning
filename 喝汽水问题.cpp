#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int money = 0;
	int total = 0;
	int empty = 0;
	scanf("%d", &money);
	//买回来的汽水喝掉
	total = money;
	empty = money;
	//换回来的汽水
	while (empty >= 2)
	{
		total += empty / 2;
		empty = empty / 2 + empty % 2;
	}
	printf("total=%d\n", total);
	return 0;
}