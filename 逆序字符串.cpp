#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<string.h>

void reverse(char* str)
{
	assert(str);
	int len = strlen(str);

	char* left = str;
	char* right = str + len - 1;
	 
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

int main()
{
	char arr[256] = { 0 };
	//scanf("%s",arr);//abcdef--->fedcba
	gets_s(arr);//读取一行
	//逆序函数
	reverse(arr);
	printf("逆序后的字符串为：%s\n", arr);
	return 0;
}