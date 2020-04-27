#pragma once

struct MyStack;

MyStack* createStack();

//���������, �������� �� ���� ������
bool isEmpty(MyStack* stack);

//�������� ������� � ����
void addElementInStack(MyStack* stack, int value);

//����������� ����� �� ������� �����
void duplicateHead(MyStack* stack);

// ������� ������� �� �����
int deleteElementFromStack(MyStack* stack);

// ����������� �������� �����
void printStack(MyStack* stack);

// ������� ����
void deleteStack(MyStack* stack);
