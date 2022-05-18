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
		//增容
		struct Peoinfo* ptr= realloc(ps->data, (ps->capacity + 2) * sizeof(Peoinfo));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
			printf("增容成功\n");
		}
		else
		{
			printf("增容失败\n");
		}

	}
}

void Addcontact(struct Contact* ps)
{
	//检测当前通讯录容量
	//1.如果满了，就增加空间
	//2.如果不满，啥事也不干
	Cheackcapacity(ps);
	//增加数据
	printf("请输入名字：>");
	scanf("%s", ps->data[ps->size].name);
	printf("请输入年龄：>");
	scanf("%d", &(ps->data[ps->size].age));
	printf("请输入性别：>");
	scanf("%s", ps->data[ps->size].sex);
	printf("请输入电话：>");
	scanf("%s", ps->data[ps->size].tele);
	printf("请输入地址：>");
	scanf("%s", ps->data[ps->size].addr);
	ps->size++;
	printf("添加成功\n");
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
		return -1;//找不到的情况
	}
}
void Showcontact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		//标题
		printf("%-20s\t%-2s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		//数据
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
	printf("请输入要删除的对象：>");
	scanf("%s", name);
	//1.查找;查找要删除的人在什么位置
	//找到了返回名字所在的下标
	//找不到返回-1
	int pos = Find(ps, name);
	//2.删除
	if (pos==-1)
	{
		printf("删除的人不存在\n");
	}
	else
	{
		//删除数据
		int j = 0;
		for (j = pos; j <ps->size-1 ; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}
}

void Searchcontact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要查找人的名字:>");
	scanf("%s", name);
	int pos=Find(ps, name);
	if (ps == -1)
	{
		printf("要查找的人不存在\n");
	}
	else
	{
		printf("%-20s\t%-2s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
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
	printf("请输入要修改的对象：>");
	scanf("%s", name);
	int pos = Find(ps, name);
	if (pos == -1)
	{
		printf("修改的人不存在\n");
	}
	else
	{
		printf("请输入名字：>");
		scanf("%s", ps->data[pos].name);
		printf("请输入年龄：>");
		scanf("%d", &(ps->data[pos].age));
		printf("请输入性别：>");
		scanf("%s", ps->data[pos].sex);
		printf("请输入电话：>");
		scanf("%s", ps->data[pos].tele);
		printf("请输入地址：>");
		scanf("%s", ps->data[pos].addr);

		printf("修改完成\n");
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
	//记录通讯录信息
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