#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int is_left_move(char* arr1, char* arr2)
{
	int len1 = strlen(arr1);
	int len2 = strlen(arr2);
	if (len1 != len2)
		return 0;
	//1.��arr1�ַ�����׷��һ��arr2�ַ���
	//strcat��arr1��arr2����//err
	strncat(arr1, arr1, 6);//abcdefabcdef
	//2.�ж�arr2ָ����ַ����Ƿ���arr1ָ����ַ�������Ӵ�
	//strstr-���Ӵ�
	char* ret = strstr(arr1, arr2);
	if (ret == NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "cdefab";
	int ret = is_left_move(arr1, arr2);
	if (ret == 1)
	{
		printf("yes\n");
	}
	else
	{
		printf("no\n");
	}
	return 0;
}