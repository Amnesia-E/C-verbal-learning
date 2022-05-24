#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int arr[] = { 1,2,3,4,11,6,7,8,9,10 };
	int max = 0;
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[i]);
	for (i = 1; i < sz; i++)
	{
		if (arr[i] > arr[i - 1])
			max = arr[i];
		else
			break;
	}
	printf("%d\n", max);
	return 0;
}