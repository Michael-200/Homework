#pragma once

struct MyList;

struct ListElement;

// �������� ������.
MyList* createList();

// �������� ������� �������.
MyList** createArrayOfList(int capacity);

// ����� ��������� � ������.
int numberOfElements(MyList* list);

// ���������� �� ������� � ������.
bool isContain(MyList* list, char value[]);

// ����� ��������� ��������� � ������.
int numberOfDifferentElements(MyList* list);

// ��������� �� ������ ������� ������.
ListElement* getHead(MyList* list);

// ��������� �� ��������� �������.
ListElement* getNext(ListElement* listElement);

// ������� ���������� ����� ��������.
int getCounterElement(ListElement* listElement);

// ������� �������� �������� ������.
void getValue(ListElement* listElement, char value[]);

// ���������� ��������.
void addElementToList(MyList* list, char value[]);

// ���������� ����������� ��������.
void addUniqueElementToList(MyList* list, char value[]);

// ����������� ���� ����.
void printList(MyList* list);

// ���������� ������ ������������.
void printHead(MyList* list);

// �������� �������� �� ������.
void deleteElementFromList(MyList* list);

// �������� �����.
void deleteList(MyList* list);