#include <iostream>

#include "BinaryTree.h"

const int maxSize = 20;

bool isCorrect()
{
	Tree* testTree = createTree();
	bool isCorrect = true;

	if (isContain(testTree, 1))
	{
		isCorrect = false;
	}

	char value1[] = "aaaa";
	addElementToTree(testTree, 1, value1);

	if (!isContain(testTree, 1))
	{
		isCorrect = false;
	}

	char value2[] = "bbb";
	addElementToTree(testTree, 3, value2);
	char value3[] = "ccc";
	addElementToTree(testTree, 2, value3);

	if (strcmp(getValue(testTree, 3), value2) != 0)
	{
		isCorrect = false;
	}

	if (getValue(testTree, 4) != nullptr)
	{
		isCorrect = false;
	}

	deleteElementFromTree(getHead(testTree), 3);

	if (isContain(testTree, 3))
	{
		isCorrect = false;
	}

	deleteTree(testTree);

	return isCorrect;
}

void printMenu()
{
	printf("������� ����� ��������: \n");
	printf("0 - �����; \n");
	printf("1 - �������� �������� � c������; \n");
	printf("2 - �������� �������� �� �����; \n");
	printf("3 - ��������� ������� ��������� ����� � �������; \n");
	printf("4 - ������� �������� �� �����; \n");
}

int main()
{
	setlocale(LC_ALL, "Russian");

	if (!isCorrect())
	{
		printf("tests failed");
		return 1;
	}

	Tree* tree = createTree();

	int operation = -1;

	while (operation)
	{
		printMenu();
		scanf("%d", &operation);

		switch (operation)
		{
		case 0:
			break;
		case 1:
		{
			printf("������� ��������: ");
			char value[maxSize]{};
			scanf("%s", value);
			printf("������� ����: ");
			int key = 0;
			scanf("%d", &key);
			addElementToTree(tree, key, value);
			break;
		}
		case 2:
		{
			printf("������� ����, �� �������� �������� ��������: ");
			int key = 0;
			scanf("%d", &key);
			printf("�������� �� ������� �����: %s \n", getValue(tree, key));
			break;
		}
		case 3:
		{
			printf("������� ����, ������� ����� ���������: ");
			int key = 0;
			scanf("%d", &key);
			if (isContain(tree, key))
			{
				printf("�������� � ���� ������ ��������� � �������.\n");
			}
			else
			{
				printf("�������� � ���� ������ �� ��������� � �������.\n");
			}
			break;
		}
		case 4:
		{
			printf("������� ����, �� �������� ����� ������� ��������: ");
			int key = 0;
			scanf("%d", &key);
			deleteElementFromTree(getHead(tree), key);
			break;
		}
		default:
		{
			printf("������������ ����� ��������, ���������� ��� ���. \n");
			break;
		}
		}
	}

	deleteTree(tree);

	return 0;
}