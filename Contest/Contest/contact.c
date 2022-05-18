#define _CRT_SECURE_NO_WARNINGS 1

#include"Contest.h"

void Initcontact(struct Contact* ps)
{
	ps->data = (struct Peoinfo*)malloc(DEFAULT_SZ * sizeof(struct Peoinfo));
	if (ps->data == NULL)
	{
		return 0;
	}
	ps->size = 0;
	ps->capacity = DEFAULT_SZ;
}

void Destorycontact(struct Contact* ps)
{
	free(ps->data);
	ps->data = NULL;
}

void Cheackcapacity(struct Contact* ps)
{
	if (ps->size == ps->capacity)
	{
		//����
		struct Peoinfo* ptr= realloc(ps->data, (ps->capacity + 2) * sizeof(Peoinfo));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
			printf("���ݳɹ�\n");
		}
		else
		{
			printf("����ʧ��\n");
		}

	}
}

void Addcontact(struct Contact* ps)
{
	//��⵱ǰͨѶ¼����
	//1.������ˣ������ӿռ�
	//2.���������ɶ��Ҳ����
	Cheackcapacity(ps);
	//��������
	printf("���������֣�>");
	scanf("%s", ps->data[ps->size].name);
	printf("���������䣺>");
	scanf("%d", &(ps->data[ps->size].age));
	printf("�������Ա�>");
	scanf("%s", ps->data[ps->size].sex);
	printf("������绰��>");
	scanf("%s", ps->data[ps->size].tele);
	printf("�������ַ��>");
	scanf("%s", ps->data[ps->size].addr);
	ps->size++;
	printf("��ӳɹ�\n");
}
static int Find(const struct Contact* ps,char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
		{
			return i;
		}
		return -1;//�Ҳ��������
	}
}
void Showcontact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		int i = 0;
		//����
		printf("%-20s\t%-2s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		//����
		for (i = 0; i < ps->size; i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}

	}
}

void Delcontact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫɾ���Ķ���>");
	scanf("%s", name);
	//1.����;����Ҫɾ��������ʲôλ��
	//�ҵ��˷����������ڵ��±�
	//�Ҳ�������-1
	int pos = Find(ps, name);
	//2.ɾ��
	if (pos==-1)
	{
		printf("ɾ�����˲�����\n");
	}
	else
	{
		//ɾ������
		int j = 0;
		for (j = pos; j <ps->size-1 ; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�\n");
	}
}

void Searchcontact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ�����˵�����:>");
	scanf("%s", name);
	int pos=Find(ps, name);
	if (ps == -1)
	{
		printf("Ҫ���ҵ��˲�����\n");
	}
	else
	{
		printf("%-20s\t%-2s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		printf("%-20s\t%-2s\t%-5s\t%-12s\t%-20s\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr);
	}
}

void Modifycontact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ�޸ĵĶ���>");
	scanf("%s", name);
	int pos = Find(ps, name);
	if (pos == -1)
	{
		printf("�޸ĵ��˲�����\n");
	}
	else
	{
		printf("���������֣�>");
		scanf("%s", ps->data[pos].name);
		printf("���������䣺>");
		scanf("%d", &(ps->data[pos].age));
		printf("�������Ա�>");
		scanf("%s", ps->data[pos].sex);
		printf("������绰��>");
		scanf("%s", ps->data[pos].tele);
		printf("�������ַ��>");
		scanf("%s", ps->data[pos].addr);

		printf("�޸����\n");
	}
}

void Savecontact(struct Contact* ps)
{
	FILE* pfwrite = fopen("contact.dat","wb");
	if (pfwrite == NULL)
	{
		printf("%s\n", strerror(errno));
		return ;
	}
	//��¼ͨѶ¼��Ϣ
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&(ps->data[i]), sizeof(Peoinfo), 1, pfwrite);
		return 0;
	}

	fclose(pfwrite);
	pfwrite = NULL;
}

void SortContact(struct Contact* ps)
{

}