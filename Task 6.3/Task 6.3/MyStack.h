#pragma once

struct StackElement;

struct MyStack;

MyStack* createStack();

// �������� ������� � ����.
void pushToStack(MyStack *stack, char symbol);

// ������� �������� � ������ ����� ��� ��������.
char headOfStack(MyStack *stack);

// �������� �� ������� �����.
bool isStackEmpty(MyStack *stack);

// ������� � ������� ������� �� �����.
char popFromStack(MyStack *stack);

// ������� ����.
void deleteStack(MyStack *stack);

// ���������� ����.
MyStack * reverseStack(MyStack *stack);