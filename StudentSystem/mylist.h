#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//���ݵ����------>ѧ����Ϣ����
typedef struct student
{
	char name[20];
	int age;
	char sex[5];
	char tel[20];
}stuDate;

typedef stuDate ElemType;

//�������ݽṹ
typedef struct Node
{
	ElemType date;
	struct Node* next;
}Node,*NodeList;

//������ͷ
Node* creatList()
{
	NodeList head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	return head;
}

//�����ڵ�
Node* creatNode(ElemType date)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	memcpy(&newNode->date, &date, sizeof(ElemType));
	newNode->next = NULL;
	return newNode;
}

//��ӡ����
void printList(Node* headNode)
{
	Node* pp = headNode->next;
	printf("����\t����\t�Ա�\t�绰\n\n");
	while (pp)
	{
		printf("%s\t%d\t%s\t%s\n", pp->date.name,pp->date.age,pp->date.sex,pp->date.tel);
		pp = pp->next;
	}
	printf("\n");
}

//���루ͷ�壩
void insertNodeByHead(Node* head, ElemType date)
{
	Node* tmp = creatNode(date);
	tmp->next = head->next;
	head->next = tmp;
}

//ָ��λ��ɾ��
void DelAppointNode(NodeList head, char *name)
{
	Node* pre = head;
	Node* pp = head->next;

	if (pp == NULL)
	{
		printf("����Ϊ�գ��޷�ɾ��\n");
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
				printf("δ�ҵ�������");

			}
		}
	}

	return;
}

//����
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

//����洢
//�ļ���
void readInFromFile(Node* head,const char* filename)
{
	//1.���ļ�
	FILE* fp;
	stuDate date;
	fp = fopen(filename, "r");			//�Զ��ķ�ʽ���ļ������ļ������ڲ��ᴴ���ļ�
	if (fp == NULL)
	{
		fp = fopen(filename, "w+");			//�����ļ�
	}
	//2.���ļ�
	while (fscanf(fp, "%s\t%d\t%s\t%s\n", date.name, &date.age, date.sex, date.tel) != EOF)
	{
		insertNodeByHead(head, date);
	}

	//3.�ر��ļ�
	fclose(fp);							
}

//�ļ�д
void writeInfoToFile(Node* head,const char* filename)
{
	//1.���ļ�
	FILE* fp;
	fp = fopen(filename, "w");			//�Զ��ķ�ʽ���ļ������ļ������ڲ��ᴴ���ļ�
	Node* pp = head->next;
	//2.д�ļ�
	while (pp)
	{
		fprintf(fp, "%s\t%d\t%s\t%s\n", pp->date.name, pp->date.age, pp->date.sex, pp->date.tel);
		pp = pp->next;
	}
	//3.�ر��ļ�
	fclose(fp);
}
