#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "BinaryTree.h"


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
	printf("[MENU]\n");
	printf("1. ���� ��������\n");
	printf("2. ����� �������� �� �������\n");
	printf("3. �������� ������� ��������� �����\n");
	printf("4. �������� ������\n");
	printf("5. �����\n");
	printf("Input number: ");

	char *choose = (char*)malloc(100 *sizeof(char));//��������� ������ ��� �����;
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
		free(tree);
		return 0;
	}

	//�������� �� ������� �������� � ������ �������
	char *value = (char*)malloc(100 *sizeof(char));//��������� ������ ��� ��������
	strcpy(value, "���");
	if (strcmp(strToLower(value), "���") != 0)
	{
		free(value);
		return 0;
	}
	free(value);
	if (tree != NULL) free(tree);
	return 1;
}

int main()
{
	setlocale(LC_ALL, "RU");

	if (!test())
	{
		printf("���� �� �������...\n");
	}
	
	Node *found = NULL;
	Node *searchKey = NULL;
	Node *tree = NULL;//������ ��� ����
	char *key = (char *)malloc(100*sizeof(char));//��������� ������ ��� �����
	char *value = (char *)malloc(100*sizeof(char));//��������� ������ ��� ��������


	int loop = 1;
	while (loop)
	{
		int choose = menu();
		switch (choose)
		{
			case 1:
			{
				printf("���������� ����� ����������\n");
				printf("������� �������: ");
				scanf("%s", key);
				key = strToLower(key);
				printf("������� ����� ��������: ");
				scanf("%s", value);
				tree = addNode(tree, key, value);
				printf("������ �������!\n");
				break;
			}

			case 2:
			{
				printf("����� ���������� �� �����\n");
				printf("������� �������: ");
				scanf("%s", key);
				key = strToLower(key);
				found = searchByKey(tree, key);
				if (found)
				{
					printf("\n%s %s\n", found->key, found->item);
				}
				else
				{
					printf("������ �� �������!\n");
				}
				break;
			}

			case 3:
			{
				printf("�������� �����\n");
				printf("������� ������� ��� �������� �����: ");
				scanf("%s", key);
				key = strToLower(key);
				searchKey = searchByKey(tree, key);
				if (searchKey)
				{
					printf("������ ���� ����������\n");
				}
				else
				{
					printf("������ ����� ���!\n");
				}
				
				break;
			}
				
			case 4:
			{
				printf("�������� ������\n");
				printf("������� ������� ��� ��������: ");
				scanf("%s", key);
				key = strToLower(key);
				tree = removeByKey(tree, key);
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
				
		}
	}

	freeTree(tree);
	free(searchKey);
	free(value);
	free(key);
	
	return 0;
}