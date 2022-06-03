#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<string.h>
void left_move(char* arr, int k)
{
	assert(arr != 0);
	int i = 0;
	int len = strlen(arr);
	for (i = 0; i < k; i++)
	{
		//×óÐý×ªÒ»¸ö×Ö·û
		//1
		char tmp = *arr;
		//2
		int j = 0;
		for (j = 0; j < len - 1; j++)
		{
			*(arr + j) = *(arr + j + 1);
		}
		//3
		*(arr + len - 1) = tmp;
	}
}
int main()
{
	char arr[] = {"abcd"};
	int k = 0;
	scanf("%d", &k);
	left_move(arr, k);
	printf("%s\n",arr);
	return 0;
}