#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a = 0;
	int n = 0;
	scanf("%d%d", &a,&n);//2 5
	int sun = 0;
	int i = 0;
	int ret = 0;
	//2 22 222 2222
	for (i = 0; i < n; i++)
	{
		ret =ret * 10 + a;
		sun += ret;
	}
	printf("%d", sun);


	return 0;
}
