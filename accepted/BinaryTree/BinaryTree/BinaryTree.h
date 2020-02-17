#pragma once

typedef struct BinaryTree
{
	int key;//����
	char *item;//���� ������
	struct tree *left;//����� �������
	struct tree *right;//������ �������
} Node;

Node *addNode(Node *tree, int key, char *value);

Node* searchByKey(Node* tree, int key);

Node* removeByKey(Node* tree, int key);

void freeTree(Node* tree);