#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"


char *strToLower(char *value)
{//�������������� ������ � ������ �������
	const len = strlen(value);
	for (int i = 0; i < len; i++)
	{
		if (value[i] >= 'A' && value[i] <= 'Z')
		{
			value[i] += 'z' - 'Z';
		}
		if (value[i] >= '�' && value[i] <= '�')
		{
			value[i] += '�' - '�';
		}
	}
	return value;
}

int menu()
{//���������� ���� ���������
	system("CLS");//������� ���� �������
	printf("[MENU]\n");
	printf("1. ���� ��������\n");
	printf("2. ����� �������� �� �������\n");
	printf("3. �������� ������� ��������� �����\n");
	printf("4. �������� ������\n");
	printf("5. �����\n");
	printf("Input number: ");

	char *choose = (char *)malloc(100*sizeof(char));//��������� ������ ��� �����;
	scanf("%s", choose);
	//������� ���������� ������ ����
	if (choose < '0' && choose >'9')
	{
		free(choose);//������������ ������
		return 0;
	}
	else
	{
		int nChouse = atoi(choose);
		free(choose);//������������ ������
		return nChouse;
	}
}

int test()
{
	//������������ �������
	
	//�������� �� ����������
	Node *tree = NULL;
	char *key = "a";
	tree = addNode(tree, key, "value1");
	if (!tree)
	{
		return 0;
	}
	//�������� �� ��������
	tree = removeByKey(tree, key);
	if (tree)
	{
		return 0;
	}

	//�������� �� ������� �������� � ������ �������
	char *value = (char *)malloc(100 * sizeof(char));//��������� ������ ��� ��������
	strcpy(value, "���");
	if (strcmp(strToLower(value), "���") != 0)
	{
		return 0;
	}

	return 1;
}

int main()
{
	system("chcp 1251");


	if (!test())
	{
		printf("���� �� �������...\n");
		system("pause");
	}
	
	Node *tree = NULL;//������ ��� ����
	char* key = (char*)malloc(100 *sizeof(char));//��������� ������ ��� �����
	char* value = (char*)malloc(100 *sizeof(char));//��������� ������ ��� ��������



	int loop = 1;
	while (loop)
	{
		int choose = menu();
		switch (choose)
		{
			case 1:
			{
				system("cls");
				printf("���������� ����� ����������\n");
				printf("������� �������: ");
				scanf("%s", key);
				key = strToLower(key);
				printf("������� ����� ��������: ");
				scanf("%s", value);
				tree = addNode(tree, key, value);
				printf("������ �������!\n");
				system("pause");
				break;
			}

			case 2:
			{
				system("cls");
				printf("����� ���������� �� �����\n");
				printf("������� �������: ");
				scanf("%s", key);
				key = strToLower(key);
				Node *found = searchByKey(tree, key);
				if (found)
				{
					printf("\n%s %s\n", found->key, found->item);
				}
				else
				{
					printf("������ �� �������!\n");
				}
				system("pause");
				break;
			}
			

			case 3:
			{
				system("cls");
				printf("�������� �����\n");
				printf("������� ������� ��� �������� �����: ");
				scanf("%s", key);
				key = strToLower(key);
				Node *searchKey = searchByKey(tree, key);
				if (searchKey)
				{
					printf("������ ���� ����������\n");
				}
				else
				{
					printf("������ ����� ���!\n");
				}
				system("pause");
				break;
			}
				
			case 4:
			{
				system("cls");
				printf("�������� ������\n");
				printf("������� ������� ��� ��������: ");
				scanf("%s", key);
				key = strToLower(key);
				tree = removeByKey(tree, key);
				system("pause");
				break;
			}
				
			case 5:
			{
				loop = 0;
				break;
			}

			default:
			{
				printf("�������� �����...\n");
				break;
			}
			
		}//switch
	}//while 

	free(tree);
	free(value);
	free(key);
	
	return 0;
}