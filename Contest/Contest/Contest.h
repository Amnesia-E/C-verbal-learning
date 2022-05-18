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

//ͨѶ¼����
typedef struct Contact
{
	struct Peoinfo * data;
	int size;//��¼��ǰ���е�Ԫ�ظ���
	int capacity;//��ǰͨѶ¼���������
}Contact;

//��������
//��ʼ��ͨѶ¼�ĺ���
void Initcontact(struct Contact* ps);

//����һ����Ϣ��ͨѶ¼
void Addcontact(struct Contact* ps);

//��ӡͨѶ¼��Ϣ
void Showcontact(struct Contact* ps);

//ɾ��ָ������ϵ��
void Delcontact(struct Contact* ps);

//����ָ������
void Searchcontact(struct Contact* ps);

//�޸�ָ������
void Modifycontact(struct Contact* ps);

//�ͷſռ�
void Destorycontact(struct Contact* ps);

//������Ϣ
void Savecontact(struct Contact* ps);

//������Ϣ
void SortContact(struct Contact* ps);