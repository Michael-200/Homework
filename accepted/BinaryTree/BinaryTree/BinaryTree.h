#pragma once


typedef struct BinaryTree
{
	int count;//����� ���������
	int key;//����
	char *item;//���� ������
	unsigned char height; //������ ���������
	struct tree *left;//����� �������
	struct tree *right;//������ �������
} Node;



Node *addNode(Node *tree, int key, char *value);

Node* searchByKey(Node* tree, int key);

Node* findMin(Node* localeNode);

Node* removeMin(Node* localeNode);

Node* removeByKey(Node* tree, int key);

void freeTree(Node* tree);