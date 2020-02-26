#pragma once
#include <string>

struct List;

struct ListElement;

// �������� ������.
List * createList();

// �������� ������� �������.
List ** createArrayOfList(int capacity);

// ����� ��������� � ������.
size_t numberOfElements(List * list);

// ���������� �� ������� � ������.
bool isContain(List * list, char value[]);

// ����� ��������� ��������� � ������.
int numberOfDifferentElements(List * list);

// ��������� �� ������ ������� ������.
ListElement * getHead(List * list);

// ���������� ��������.
void addElementToList(List * list, char value[]);

// ����������� ���� ����.
void printList(List * list);

// ���������� ������ ������������.
void printHead(List * list);

// �������� �������� �� ������.
void deleteElementFromList(List * list);

// �������� �����.
void deleteList(List * list);