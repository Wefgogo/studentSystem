/*
*	1.����
*	2.���ݽṹ���				//������ƺ͹��ֿܷ�
*	3.����
*/
#include"mylist.h"
//���ݵ����------>ѧ����Ϣ����

//�˵����
void menu()
{
	//���в���ͬ�����ļ�
	printf("-----------------------��ѧ������ϵͳ��----------------------\n");
	printf("\t\t\t0.�˳�ϵͳ\n");
	printf("\t\t\t1.¼����Ϣ\n");
	printf("\t\t\t2.�����Ϣ\n");
	printf("\t\t\t3.ɾ����Ϣ\n");
	printf("\t\t\t4.������Ϣ\n");
	printf("-------------------------------------------------------------\n");
}

Node* list = creatList();
//�û�����
//������ѡ�˵�������Ӧ����
void keyDown()
{
	int choice = 0;
	stuDate date;
	scanf("%d", &choice);

	switch (choice)
	{
	case 0:
		printf("�����˳�\n");
		system("pause");
		exit(0);
		break;
	case 1:
		printf("----------¼����Ϣ----------\n");
		//����
		printf("������ѧ�����������䣬�Ա𣬵绰��");
		fflush(stdin);	//��ջ�����
		scanf("%s%d%s%s", &date.name, &date.age, &date.sex, &date.tel);
		insertNodeByHead(list, date);
		break;
	case 2:
		printf("----------�����Ϣ----------\n");
		printList(list);
		break;
	case 3:
		printf("----------ɾ����Ϣ----------\n");
		printf("������Ҫɾ������:");
		scanf("%s", &date.name);
		DelAppointNode(list, date.name);
		break;
	case 4:
		printf("----------������Ϣ----------\n");
		printf("������Ҫ��������\n");
		scanf("%s", &date.name);
		if (searchDate(list,date.name) == NULL)
		{
			printf("δ�ҵ������Ϣ\n");
			system("pause");
		}
		else
		{
			printf("����\t����\t�Ա�\t�绰\n");
			printf("%s\t%d\t%s\t%s\n", searchDate(list, date.name)->date.name, searchDate(list, date.name)->date.age, 
				searchDate(list, date.name)->date.sex, searchDate(list, date.name)->date.tel);
		}
		break;
	default:
		printf("�������\n");
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
	//�����������
	/*Node* list = creatList();
	insertNodeByHead(list, 1);
	insertNodeByHead(list, 2);
	insertNodeByHead(list, 5);
	insertNodeByHead(list, 8);
	insertNodeByHead(list, 9);
	printList(list);
	DelAppointNode(list, 5);
	printList(list);
	printf("����\n");
	printf("%d\n", searchDate(list, 2)->date);*/




	system("pause");
	return 0;
}