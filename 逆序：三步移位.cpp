#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<string.h>
void reverse(char* left, char* right)
{
	assert(left != 0);
	assert(right != 0);
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void left_move(char* arr, int k)
{
	assert(arr != 0);
	int len = strlen(arr);
	assert(k < len);

	reverse(arr, arr + k - 1);
	reverse(arr+k, arr + len - 1);
	reverse(arr, arr + len - 1);
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