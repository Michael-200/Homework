#pragma once

struct MyStack;

MyStack* createStack();

//�������� ������� � ����
void addElementInStack(MyStack* stack, int value);

// ������� ������� �� �����
int deleteElementFromStack(MyStack* stack);

// ������� ����
void deleteStack(MyStack* stack);