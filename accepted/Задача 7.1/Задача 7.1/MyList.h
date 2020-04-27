#pragma once

struct ListElement;

struct List;

List* createList();

//��������, ������ �� ������
bool isListEmpty(List* list);

//��������, ���������� �� ������� � ������
bool isValueExistInList(List* list, int value);

//�������� ������� � ������
void addElement(List* list, int value);

//������� ������� �� ������
void deleteElement(List* list, int value);

//��������� ��� �������� � ������
void putElementsInArray(List* list, int arrayOfNumbers[]);

//������� ������
void showList(List* list);

void deleteElement(List* list);

void deleteList(List* list);
