#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//数据的设计------>学生信息抽象
typedef struct student
{
	char name[20];
	int age;
	char sex[5];
	char tel[20];
}stuDate;

typedef stuDate ElemType;

//链表数据结构
typedef struct Node
{
	ElemType date;
	struct Node* next;
}Node,*NodeList;

//创建表头
Node* creatList()
{
	NodeList head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	return head;
}

//创建节点
Node* creatNode(ElemType date)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	memcpy(&newNode->date, &date, sizeof(ElemType));
	newNode->next = NULL;
	return newNode;
}

//打印链表
void printList(Node* headNode)
{
	Node* pp = headNode->next;
	printf("姓名\t年龄\t性别\t电话\n\n");
	while (pp)
	{
		printf("%s\t%d\t%s\t%s\n", pp->date.name,pp->date.age,pp->date.sex,pp->date.tel);
		pp = pp->next;
	}
	printf("\n");
}

//插入（头插）
void insertNodeByHead(Node* head, ElemType date)
{
	Node* tmp = creatNode(date);
	tmp->next = head->next;
	head->next = tmp;
}

//指定位置删除
void DelAppointNode(NodeList head, char *name)
{
	Node* pre = head;
	Node* pp = head->next;

	if (pp == NULL)
	{
		printf("数据为空，无法删除\n");
		return;
	}

	while (pp != NULL)
	{
		if (!strcmp(pp->date.name,name))
		{
			Node* tmp = pp;
			pp = pp->next;
			pre->next = pp;
			free(tmp);
			break;
		}
		else
		{
			pre = pp;
			pp = pp->next;
			if (pp == NULL)
			{
				printf("未找到该数据");

			}
		}
	}

	return;
}

//查找
Node* searchDate(Node* LL, char *name)
{
	Node* pp = LL->next;
	while (pp != NULL)
	{
		if (!strcmp(pp->date.name, name))
		{
			return pp;
		}
		else
		{
			pp = pp->next;
		}
	}
	return NULL;
}

//链表存储
//文件读
void readInFromFile(Node* head,const char* filename)
{
	//1.打开文件
	FILE* fp;
	stuDate date;
	fp = fopen(filename, "r");			//以读的方式打开文件，若文件不存在不会创建文件
	if (fp == NULL)
	{
		fp = fopen(filename, "w+");			//创建文件
	}
	//2.读文件
	while (fscanf(fp, "%s\t%d\t%s\t%s\n", date.name, &date.age, date.sex, date.tel) != EOF)
	{
		insertNodeByHead(head, date);
	}

	//3.关闭文件
	fclose(fp);							
}

//文件写
void writeInfoToFile(Node* head,const char* filename)
{
	//1.打开文件
	FILE* fp;
	fp = fopen(filename, "w");			//以读的方式打开文件，若文件不存在不会创建文件
	Node* pp = head->next;
	//2.写文件
	while (pp)
	{
		fprintf(fp, "%s\t%d\t%s\t%s\n", pp->date.name, pp->date.age, pp->date.sex, pp->date.tel);
		pp = pp->next;
	}
	//3.关闭文件
	fclose(fp);
}
