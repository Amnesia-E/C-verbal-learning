#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d%d", &a,&b);
	int i = 0;
	for (i = a; i <= b; i++)
	{
		int j = 0;
		for (j = 2; j < sqrt(i); j++)
		{
			if (i % j == 0)
			{
				break;
			}
		}
		if(j>sqrt(i))
		printf("%d ", i);
	}
	return 0;
}