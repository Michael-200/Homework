#pragma once

struct Tree;

struct TreeElement;

// ������� ������.
Tree* createTree();

// ������� ������ ������.
TreeElement* getHead(Tree* tree);

// �������� ������� � ������.
void addElementToTree(Tree* tree, int newKey, char newValue[]);

// ������� ������� �� ������.
TreeElement* deleteElementFromTree(TreeElement* treeElement, int keyToDelete);

// ���������, ��������� �� ������� � ������.
bool isContain(Tree* tree, int keyToChecked);

// ������� �������� �� �����.
char* getValue(Tree* tree, int keyToReturn);

// ������� ������.
void deleteTree(Tree* tree);