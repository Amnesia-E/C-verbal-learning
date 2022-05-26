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
	gets_s(arr);//��ȡһ��
	//������
	reverse(arr);
	printf("�������ַ���Ϊ��%s\n", arr);
	return 0;
}