#pragma once

struct MyStack;

MyStack* createStack();

// ��������� ���� �� �������
bool isStackEmpty(MyStack* stack);

//�������� ������� � ����
void addElementInStack(MyStack* stack, int value);

// ������� ������� �� �����
int deleteElementFromStack(MyStack* stack);

// ������� ����
void deleteStack(MyStack* stack);