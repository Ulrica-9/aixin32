//#include <stdio.h>
//#include <string.h>
//#include <math.h>
//struct date
//{
//	int year;
//	int month;
//	int day;
//};
//struct student
//{
//	char name[30];
//	int age;
//	char sex;
//	struct date birthday;
//
//}stu,*p;
//int main(void)
//{
//	p = &stu;
//	strcpy(stu.name, "luo tian yu");
//	printf("请输入性别:");
//	scanf_s("%c", &p->sex);
//	printf("请输入年龄:");
//	scanf_s("%d", &p->age);
//	
//	printf("请输入出生年月:");
//	scanf_s("%d%d%d", &stu.birthday.year, &stu.birthday.month, &stu.birthday.day);
//	printf("Name:%s\nsex:%c\nage:%d\nbirthady :%d  %d   %d\n", p->name, p->sex, p->age,stu.birthday.year,stu.birthday.month,stu.birthday.day);
//	return 0;
//}
//#include <stdio.h>
//#include <string.h>
//#include <math.h>
//struct money
//{
//	int a;
//	int b;
//	
//}mon[4] = { {100,200},{300,400},{500,600},{700,800} };
//int main(void)
//{
//	struct money* p = mon;
//	printf("%d\n",++p->a);
//	printf("%d\n",(++p)->b);
//	printf("%d\n",(p++)->a);
//	printf("%d\n",p->b);
//	printf("%d\n",p++->b);
//	printf("%d",p->b);
//	
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#define FORMAT "Name:%s\nage:%d\ngrade:%d %d %d\n"
//struct student
//{
//	char name[20];
//	int age;
//	
//	int grade[3];
//}stu = {"luo tianyu",20,96,88,100};
//void print(struct student * p)
//{
//	printf(FORMAT,p-> name, p->age, p->grade[0], p->grade[1], p->grade[2]);
//	 p->age=19; 
//	 p->grade[0]=100;
//	 p->grade[1]=100;
//	 p->grade[2]=100;
//}
//int main(void)
//{
//	
//	
//	print(&stu);
//	printf("改变后的值:\n");
//	printf(FORMAT, stu.name,stu.age,stu.grade[0], stu.grade[1], stu.grade[2]);
//	return 0;
//}


//创建静态链接表
//#include <stdio.h>
//#include <string.h>
//#define FORMAT "%d   %d\n"
//struct student
//{
//	int i;
//	int j;
//	struct student* p;
//};
//int main(void)
//{
//	struct student a, b, c;
//	struct student* q, * head;
//	
//	a.i = 100;
//	a.j = 99;
//	b.i = 100;
//	b.j = 88;
//	c.i = 99;
//	c.j = 55;
//	a.p = &b;
//	
//	a.p = &b;
//	b.p = &c;
//	c.p = NULL;
//	head = &a;
//	q = head;
//	do
//	{
//		printf("%d %d\n", q->i, q->j);
//		q = q->p;
//	} while (q != NULL);
//	return 0;
//}

//创建动态链接表:
//#include <stdio.h>
//#include <string.h>
//#include <malloc.h>
//#include <windows.h>
//#define FORMAT "name:%d  grade:%d\n"
//#define NAME sizeof(struct student)
//struct student
//{
//	int num;
//	int grade;
//	struct student* a;
//};
//struct student* creat(int n)
//{
//	struct student* head=NULL;
//	struct student* p=NULL;
//	struct student* q=NULL;
//	int i = 0;
//	if (n != 0)
//	{
//		p = head = (struct student*)malloc(NAME);
//		if (p != NULL)
//		{
//			for (i = 0; i < n; i++)
//			{
//				q = (struct student*)malloc(NAME);
//				printf("请输入第%d个同学的学号:", i + 1);
//				scanf_s("%d", &q->num);
//				printf("请输入第%d个同学的成绩:", i + 1);
//				scanf_s("%d", &q->grade);
//				q->a = p->a;
//				p->a = q;
//				p = q;
//			}
//		}
//		else
//		{
//			exit(-1);
//		}
//
//	}
//	else
//	{
//		exit(-1);
//	}
//	return head;
//}
//void print(struct student* head)
//{
//	struct student* p;
//	p = head->a;
//	while (p!=NULL)
//	{
//		printf(FORMAT,p->num,p->grade );
//		p = p->a;
//	}
//	printf("\n");
//}
//int main(void)
//{
//	int n = 0;
//	struct student* head;
//	printf("请输入要创建的链接表个数:");
//	scanf_s("%d", &n);
//	head = creat(n);
//	print(head);
//	return 0;
//}


// 动态链接表的创建与删除
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <windows.h>
#define NAME sizeof(struct student)
#define FORMAT "num:%d  grade:%d\n"
struct student
{
	int num;
	int grade;
	struct student* p;
};
struct student* name(int n)
{
	int i;
	struct student* head = NULL;
	struct student* u = NULL;
	struct student* q = NULL;
	u = head = (struct student*)malloc(NAME);
	if (u != NULL)
	{
		head->p = NULL;
		for (i = 0; i < n; i++)
		{
			q = (struct student*)malloc(NAME);

			printf("请输入第%d个学生的学号:", i + 1);
			scanf_s("%d", &q->num);
			printf("请输入第%d个学生的成绩:", i + 1);
			scanf_s("%d", &q->grade);
			q->p = u->p;
			u->p = q;
		}
	}
	else
	{
		exit(-1);
	}

	return head;

}
void delete_my(struct student* head)
{
	int a;
	
	struct student* p1;
	struct student* p2;
	p2 = head;
	p1 = head->p;
	printf("请输入要删除的学生学号:");
	scanf_s("%d", &a);
	while (p1)
	{
		if (p1->num == a)
		{
			p2->p = p1->p;
			free(p1);
			break;
		}
		else
		{
			p2 = p1;
			p1 = p1->p;
		}
	}

}

void create(struct student* head)
{
	struct student* p0;
	struct student* p1;
	struct student* p2;
	int i;
	p0 = (struct student*)malloc(NAME);
	
	printf("请输入插入学生的学号:");
	scanf_s("%d", &p0->num);
	printf("请输入插入学生的成绩:");
	scanf_s("%d", &p0->grade);
	p2 = head;
	p1 = head->p;
	while (p1)
	{
		if (p1->num<p0->num)
		{
			p2 = p1;
			p1 = p1->p;
		}
		else
		{
			break;
		}
	}
	p2->p = p0;
	p0->p = p1;
}

void print(struct student* head)
{
	struct student*aa;
	aa= head->p;
	while (aa)
	{
		printf(FORMAT, aa->num, aa->grade);
		aa =aa->p;
	}
}

int main(void)
{
	
	int n = 0;
	
	struct student* head;
	printf("请输入创建的链接表个数:");
	scanf_s("%d", &n);
	head = name(n);
	print(head);
	delete_my(head);
	print(head);
	create(head);
	print(head);
	return 0;
}