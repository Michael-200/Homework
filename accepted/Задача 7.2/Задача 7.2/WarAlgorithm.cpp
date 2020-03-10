#include "MyList.h"
#include "WarAlgorithm.h"

int lastWarrior(int numberOfWarriors, int killedWarrior)
{
	List* list = new List;

	initList(list, numberOfWarriors);

	ListElement* listElement = list->head;

	while (listElement->next != nullptr)
	{
		listElement = listElement->next;
	}
	listElement->next = list->head;

	while (listElement != listElement->next) //���� �� ��������� �� �������, ������� ��������� �� ����, ����� �������
	{
		for (int i = 0; i != killedWarrior - 1; ++i)
		{
			listElement = listElement->next;
		}
		ListElement* tempListElement = new ListElement;
		tempListElement = listElement->next;
		listElement->next = listElement->next->next;
		delete tempListElement;
	}

	int result = listElement->value;
	delete listElement;

	return result;
}

//��������� ������� ��� ����� �������, ����� �� ����������� � �����
bool isLastWarriorCorrect(int numberOfWarriors, int killedWarrior, int correctLastWarrior)
{
	return lastWarrior(numberOfWarriors, killedWarrior) == correctLastWarrior;
}