#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int killer = 0;
	for (killer = 'a'; killer <= 'd'; killer++)
	{
		if ((killer != 'a') + (killer == 'c') + (killer != 'd') == 3)
		{
		printf("killer=%c\n", killer);
		}
	}
	return 0; 
} 