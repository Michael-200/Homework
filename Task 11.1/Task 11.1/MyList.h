#pragma once

struct List;

struct ListElement;

// ������� ������.
List* createList();

// ������� ������ �������.
List** createArrayOfList(int size);

// ����������� ���������� ��������� � ������.
int numberOfElementsInList(List* list);

// ������� ��������� �� ������ ������.
ListElement* getHead(List* list);

// ������� ��������� �� ��������� ������� ������.
ListElement* getNext(ListElement* listElement);

// ������� �������� �������� ������.
int valueFromElement(ListElement* listElement);

// ���������� �������� � ������.
void addElementInList(List* list, int town);

// �������� � ����������� ���������� �������� �� ������.
int removeElementFromList(List* list);

// ���������� �� ������� � ������.
bool isContain(List* list, int value);

// ���������� ������.
List* reverseList(List* list);

// �������� ������.
void deleteList(List* list);

// �������� ������� �������.
void deleteArrayOfList(List** arrayOfList, int size);