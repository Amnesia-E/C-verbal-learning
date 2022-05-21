#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	scanf("%d%d%d", &a, &b, &c);
	if (a < b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
	if (b < c)
	{
		int tmp = b;
		b = c;
		c = tmp;
	}
	if (a < c)
	{
		int tmp = a;
		c = a;
		c = tmp;
	}
	if (a < b)//当上式全部交换时，b与c进行两次对比
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
	printf("%d %d %d\n", a, b, c);
	return 0;
}