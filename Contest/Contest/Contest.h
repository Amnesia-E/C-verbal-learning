#pragma once

#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>

#define DEFAULT_SZ 3

#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

enum option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
	SAVE
};
typedef struct Peoinfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
} Peoinfo;

//通讯录类型
typedef struct Contact
{
	struct Peoinfo * data;
	int size;//记录当前已有的元素个数
	int capacity;//当前通讯录的最大容量
}Contact;

//声明函数
//初始化通讯录的函数
void Initcontact(struct Contact* ps);

//增加一个信息到通讯录
void Addcontact(struct Contact* ps);

//打印通讯录信息
void Showcontact(struct Contact* ps);

//删除指定的联系人
void Delcontact(struct Contact* ps);

//查找指定的人
void Searchcontact(struct Contact* ps);

//修改指定的人
void Modifycontact(struct Contact* ps);

//释放空间
void Destorycontact(struct Contact* ps);

//储存信息
void Savecontact(struct Contact* ps);

//排序信息
void SortContact(struct Contact* ps);