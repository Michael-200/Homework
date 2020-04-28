#pragma once

struct TreeElement;

struct MyTree;

// �������� ������
MyTree* createTree();

// ������� ������ ������.
TreeElement* getHead(MyTree* tree);

// ������� �������� � �������� ������.
char getValue(TreeElement* treeElement);

// ������� ������ �������.
TreeElement* getLeft(TreeElement* treeElement);

// ������� ������� �������.
TreeElement* getRight(TreeElement* treeElement);

// ���������� �������� � ������
void addElementInTree(MyTree* tree, char newValue);

// ����� ������ �� �����
void printTree(MyTree* tree);

// ��������� ��������� � ������
void putExpressionToTree(MyTree* tree, char expression[]);

// ��������� ��������� �� ������.
int count(TreeElement* treeElement);

// �������� ������
void deleteTree(MyTree* tree);