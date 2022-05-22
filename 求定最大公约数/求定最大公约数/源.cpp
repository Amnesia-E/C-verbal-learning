#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int n = 0;
	int m = 0;
	scanf("%d%d", &n, &m);
	int r = 0;
	while (m % n)
	{
		r = m % n;
		m = n;
		n = r;
	}
	printf("%d", n);
	return 0;
}