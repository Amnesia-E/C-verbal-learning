#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d%d", &a, &b);
	for (a; a <= b; a++)
	{
		if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0))
		{
			printf("%dÄê ", a);
		}
		
	}
	return 0;
}