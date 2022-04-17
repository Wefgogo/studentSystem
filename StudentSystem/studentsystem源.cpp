/*
*	1.界面
*	2.数据结构设计				//数据设计和功能分开
*	3.交互
*/
#include"mylist.h"
//数据的设计------>学生信息抽象

//菜单设计
void menu()
{
	//所有操作同步到文件
	printf("-----------------------【学生管理系统】----------------------\n");
	printf("\t\t\t0.退出系统\n");
	printf("\t\t\t1.录入信息\n");
	printf("\t\t\t2.浏览信息\n");
	printf("\t\t\t3.删除信息\n");
	printf("\t\t\t4.查找信息\n");
	printf("-------------------------------------------------------------\n");
}

Node* list = creatList();
//用户交互
//根据所选菜单项做相应功能
void keyDown()
{
	int choice = 0;
	stuDate date;
	scanf("%d", &choice);

	switch (choice)
	{
	case 0:
		printf("正常退出\n");
		system("pause");
		exit(0);
		break;
	case 1:
		printf("----------录入信息----------\n");
		//插入
		printf("请输入学生姓名，年龄，性别，电话：");
		fflush(stdin);	//清空缓冲区
		scanf("%s%d%s%s", &date.name, &date.age, &date.sex, &date.tel);
		insertNodeByHead(list, date);
		break;
	case 2:
		printf("----------浏览信息----------\n");
		printList(list);
		break;
	case 3:
		printf("----------删除信息----------\n");
		printf("请输入要删除名字:");
		scanf("%s", &date.name);
		DelAppointNode(list, date.name);
		break;
	case 4:
		printf("----------查找信息----------\n");
		printf("请输入要查找姓名\n");
		scanf("%s", &date.name);
		if (searchDate(list,date.name) == NULL)
		{
			printf("未找到相关信息\n");
			system("pause");
		}
		else
		{
			printf("姓名\t年龄\t性别\t电话\n");
			printf("%s\t%d\t%s\t%s\n", searchDate(list, date.name)->date.name, searchDate(list, date.name)->date.age, 
				searchDate(list, date.name)->date.sex, searchDate(list, date.name)->date.tel);
		}
		break;
	default:
		printf("输入错误\n");
		system("pause");
		break;
	}
	
	writeInfoToFile(list, "001.txt");
}

int main()
{
	readInFromFile(list,"001.txt");
	while (1)
	{
		menu();
		keyDown();
		system("pause");
		system("cls");
	}
	//测试链表代码
	/*Node* list = creatList();
	insertNodeByHead(list, 1);
	insertNodeByHead(list, 2);
	insertNodeByHead(list, 5);
	insertNodeByHead(list, 8);
	insertNodeByHead(list, 9);
	printList(list);
	DelAppointNode(list, 5);
	printList(list);
	printf("查找\n");
	printf("%d\n", searchDate(list, 2)->date);*/




	system("pause");
	return 0;
}