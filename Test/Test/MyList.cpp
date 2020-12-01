#include "MyList.h"
#include <cstdio>
#include <stdlib.h>

struct ListElement
{
	int value;
	ListElement* next;
};

struct List
{
	ListElement* head = nullptr;
};

// ������� ������
List* createList()
{
	return new List;
}

// ���������, �������� �� ������ ������
bool isListEmpty(List* list)
{
	return list->head == nullptr;
}

//��������� ������ �� ������
bool isListExist(List* list)
{
	return list != nullptr;
}

// ��������� ������ ���������� ����������
bool fillList(List* list, int sizeOfList, int start, int end)
{
	if (sizeOfList < 1 || start > end)
	{
		printf("������������ ���������.\n");
		return false;
	}
	int range = end - start + 1;
	for (int i = 0; i != sizeOfList; ++i)
	{
		int newValue = (rand() % range) + start;
		addElement(list, newValue);
	}

	return true;
}

// ���������� ������
List* reverseList(List* list)
{
	List* newList = createList();
	while (list->head != nullptr)
	{
		int tempValue = removeElement(list);
		addElement(newList, tempValue);
	}

	deleteList(list);

	return newList;
}

// �������� ������� � ������ ������
void addElement(List* list, int value)
{
	ListElement* listElement = new ListElement;
	listElement->value = value;
	listElement->next = list->head;
	list->head = listElement;
}

// ������� ������� �� ������ ������ � ������� ��������
int removeElement(List* list)
{
	ListElement* temp = list->head;
	int result = temp->value;
	list->head = list->head->next;
	delete temp;

	return result;
}

// ����������� ������
void showList(List* list)
{
	if (isListEmpty(list))
	{
		printf("������ ����.\n");
		return;
	}
	printf("������: ");
	ListElement* listElement = list->head;
	while (listElement != nullptr)
	{
		printf("%d ", listElement->value);
		listElement = listElement->next;
	}
	printf("\n");
}

// ������� ������� �� ������ ������
void deleteElement(List* list)
{
	ListElement* temp = list->head;
	list->head = list->head->next;
	delete temp;
}

// ������� ������
void deleteList(List* list)
{
	if (list == nullptr)
	{
		return;
	}
	while (list->head != nullptr)
	{
		deleteElement(list);
	}

	delete list;
}