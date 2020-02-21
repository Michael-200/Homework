#pragma once

struct MyTree;

// �������� ������
MyTree* createTree();

// ���������� �������� � ������
void addElementInTree(MyTree* tree, char newValue);

// ����� ������ �� �����
void printTree(MyTree* tree);

// ��������� ��������� � ������
void putExpressionToTree(MyTree* tree, char expression[]);

// �������� ������
void deleteTree(MyTree* tree);