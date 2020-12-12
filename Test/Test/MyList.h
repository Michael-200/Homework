#pragma once

struct ListElement;

struct List;

// ������� ������
List* createList();

// ���������, �������� �� ������ ������
bool isListEmpty(List* list);

//��������� ������ �� ������
bool isListExist(List* list);

// ��������� ������ ���������� ����������
bool fillList(List* list, int sizeOfList, int start, int end);

// ���������� ������
List* reverseList(List* list);

// ������� ������� �� ������ ������ � ������� ��������
int removeElement(List* list);

// �������� ������� � ������ ������
void addElement(List* list, int value);

// ����������� ������
void showList(List* list);

// ������� ������� �� ������ ������
void deleteElement(List* list);

// ������� ������
void deleteList(List* list);