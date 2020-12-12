#include <iostream>
#include "MyList.h"

bool test()
{
	List* testList = createList();
	if (!isListEmpty(testList))
	{
		printf("�� ������� ���� 1.\n");
		deleteList(testList);
		return false;
	}

	int testSize = 5;
	int testStart = 0;
	int testEnd = 10;

	if (!fillList(testList, testSize, testStart, testEnd))
	{
		printf("�� �������� ���� 1.1.\n");
		deleteList(testList);
		return false;
	}

	if (isListEmpty(testList))
	{
		printf("�� �������� ���� 2.\n");
		deleteList(testList);
		return false;
	}

	deleteList(testList);

	if (!isListExist(testList))
	{
		printf("�� �������� ���� 3.\n");
		return false;
	}

	testSize = 5;
	testStart = -3;
	testEnd = 7;
	testList = createList();
	fillList(testList, testSize, testStart, testEnd);

	if (isListEmpty(testList))
	{
		printf("�� �������� ���� 4.\n");
		deleteList(testList);
		return false;
	}

	testSize = -5;

	if (fillList(testList, testSize, testStart, testEnd))
	{
		printf("�� �������� ���� 5.\n");
		deleteList(testList);
		return false;
	}

	testSize = 10;
	testStart = 100;

	if (fillList(testList, testSize, testStart, testEnd))
	{
		printf("�� �������� ���� 6.\n");
		deleteList(testList);
		return false;
	}

	deleteList(testList);

	return true;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	if (!test())
	{
		return -1;
	}

	List* list = createList();
	int operation = -1;

	while (operation)
	{
		printf("������� ����� ��������:\n");
		printf("0 - �����\n");
		printf("1 - ��������� ������ ���������� ����������\n");
		printf("2 - ���������� ������\n");
		printf("3 - ����������� ������\n");
		scanf("%d", &operation);

		switch (operation)
		{
		case 0:
			break;
		case 1:
		{
			printf("������� ������ ������: ");
			int sizeOfList = 0;
			scanf("%d", &sizeOfList);
			int start = 0;
			printf("������� ������ ��������� ��������: ");
			scanf("%d", &start);
			int end = 0;
			printf("������� ����� ���������: ");
			scanf("%d", &end);
			if (!isListEmpty(list))
			{
				deleteList(list);
				list = createList();
			}
			fillList(list, sizeOfList, start, end);
			break;
		}
		case 2:
		{
			if (isListEmpty(list))
			{
				printf("������ ������ ����!\n");
			}
			else
			{
				list = reverseList(list);
				printf("������ ������� ���������.\n");
			}
			break;
		}
		case 3:
		{
			showList(list);
			break;
		}
		default:
		{
			printf("������������ ��������.\n");
			break;
		}
		}
	}

	deleteList(list);

	return 0;
}