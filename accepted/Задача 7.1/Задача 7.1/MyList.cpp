#include "MyList.h"
#include <cstdio>

struct ListElement
{
	int value;
	ListElement* next;
};

struct List
{
	ListElement* head = nullptr;
};

List* createList()
{
	return new List;
}

//��������, ������ �� ������
bool isListEmpty(List* list)
{
	return list->head == nullptr;
}

//��������, ���������� �� ������� � ������
bool isValueExistInList(List* list, int value)
{
	if (isListEmpty(list))
	{
		return false;
	}

	ListElement* listElement = list->head;

	if (list->head->value == value)
	{
		return true;
	}
	else
	{
		while (listElement->next != nullptr && listElement->next->value != value)
		{
			if (listElement->next->value != value)
			{
				listElement = listElement->next;
			}
		}

		return !(listElement->next == nullptr);
	}
}

//�������� ������� � ������
void addElement(List* list, int value)
{
	ListElement* listElement = new ListElement;
	listElement->value = value;
	listElement->next = list->head;
	list->head = listElement;
	while (listElement->next != nullptr && listElement->value > listElement->next->value)
	{
		int temp = listElement->value;
		listElement->value = listElement->next->value;
		listElement->next->value = temp;
		listElement = listElement->next;
	}
}

//������� ������� �� ������
void deleteElement(List* list, int value)
{
	if (isListEmpty(list))
	{
		printf("������ ����.\n");
		return;
	}

	ListElement* listElement = list->head;

	if (list->head->value == value)
	{
		ListElement* tempListElement = list->head;
		list->head = list->head->next;
		delete tempListElement;
	}
	else
	{
		while (listElement->next != nullptr && listElement->next->value != value)
		{
			if (listElement->next->value != value)
			{
				listElement = listElement->next;
			}
		}

		if (listElement->next == nullptr)
		{
			printf("������ �������� ��� � ������.\n");
			return;
		}

		ListElement* tempListElement = listElement->next;
		listElement->next = tempListElement->next;
		delete tempListElement;
	}
}

//��������� ��� �������� � ������
void putElementsInArray(List* list, int arrayOfNumbers[])
{
	int index = 0;
	ListElement* listElement = list->head;
	while (listElement != nullptr)
	{
		arrayOfNumbers[index] = listElement->value;
		listElement = listElement->next;
		++index;
	}
}

//������� ������
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

void deleteElement(List* list)
{
	ListElement* temp = list->head;
	list->head = list->head->next;
	delete temp;
}

void deleteList(List* list)
{
	while (list->head != nullptr)
	{
		deleteElement(list);
	}

	delete list;
}