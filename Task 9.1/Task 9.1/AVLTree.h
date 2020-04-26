#pragma once

struct Tree;

struct TreeElement;

// ������� ������.
Tree* createTree();

// ������� ������ ������.
TreeElement* getHead(Tree* tree);

// ���������� ����� �������� � ������ ������.
void newHead(Tree* tree, TreeElement* newHead);

// �������� ������� � ������.
TreeElement* addElementToTree(Tree* tree, TreeElement* treeElement, int newKey, char newValue[]);

TreeElement* removeElementFromTree(TreeElement* treeElement, int keyToDelete);

// ���������, ��������� �� ������� � ������.
bool isContain(Tree* tree, int keyToChecked);

// ������� �������� �� �����.
char* getValue(Tree* tree, int keyToReturn);

// ������� ������.
void deleteTree(Tree* tree);
