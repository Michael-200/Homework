#pragma once

struct TreeElement
{
	char value;
	TreeElement* left = nullptr;
	TreeElement* right = nullptr;
};

struct MyTree
{
	TreeElement* head = nullptr;
};

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