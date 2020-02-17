#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "BinaryTree.h"

int isDigit(char* s)
{ //�������� �� ������ ������ ����� ������
	int i = 0;
	int len = strlen(s);
	while (i < len)
	{
		if (s[i] < '0' || s[i] > '9')
		{
			return 0;
		}
		i++;
	}
	return 1;
}

char* strToLower(char* value)
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
	printf("1. ���� �������� �� �����\n");
	printf("2. ��������� �������� �� �����\n");
	printf("3. �������� ������� ��������� �����\n");
	printf("4. �������� ������\n");
	printf("5. �����\n");
	printf("����� ������: ");

	char* choose = (char*)malloc(100 * sizeof(char));//��������� ������ ��� �����;
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
	Node* tree = NULL;
	int key = 5;
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
	char* value = (char*)malloc(100 * sizeof(char));//��������� ������ ��� ��������
	strcpy(value, "���");
	if (strcmp(strToLower(value), "���") != 0)
	{
		return 0;
	}

	return 1;
}

int main()
{
	setlocale(LC_ALL, "RU");

	if (!test())
	{
		printf("���� �� �������...\n");
		return 0;
	}

	Node* tree = NULL;//������ ��� ����
	int key = 0;//��������
	char* sKey = (char*)malloc(100 * sizeof(char));//�������� �����
	char* value = (char*)malloc(100 * sizeof(char));//��������� ������ ��� ��������

	int loop = 1;
	while (loop)
	{
		int choose = menu();
		switch (choose)
		{
			case 1:
			{
				printf("���������� ����� ����������\n");
				printf("������� �������� �����: ");
				scanf("%s", sKey);
				if (!isDigit(sKey))
				{
					printf("�������� ���� ��������!\n");
					break;
				}
				//������ �������� ����� � �����
				key = atoi(sKey);
				printf("������� ������: ");
				scanf("%s", value);
				tree = addNode(tree, key, value);
				printf("������ �������!\n");
				break;
			}

			case 2:
			{
				printf("����� ���������� �� �����\n");
				printf("���� �����: ");
				scanf("%s", sKey);
				if (!isDigit(sKey))
				{
					printf("�������� ���� ��������!\n");
					break;
				}
				//������ �������� ����� � �����
				key = atoi(sKey);
				Node* found = searchByKey(tree, key);
				if (found)
				{
					printf("\n%d %s\n", found->key, found->item);
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
				printf("������� ���� ��� ��� ��������: ");
				scanf("%s", sKey);
				if (!isDigit(sKey))
				{
					printf("�������� ���� ��������!\n");
					break;
				}
				//������ �������� ����� � �����
				key = atoi(sKey);
				Node* searchKey = searchByKey(tree, key);
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
				printf("������� �������� ����� ��� �������� ������: ");
				scanf("%s", sKey);
				if (!isDigit(sKey))
				{
					printf("�������� ���� ��������!\n");
					break;
				}
				//������ �������� ����� � �����
				key = atoi(sKey);

				tree = removeByKey(tree, key);
				printf("��� ������������ ������� ����� �������..\n");
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
	free(value);
	free(sKey);

	return 0;
}
