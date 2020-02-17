#pragma once


typedef struct BinaryTree
{
	int count;//����� ���������
	char *key;//����
	char *item;//���� ������
	unsigned char height; //������ ���������
	struct tree *left;//����� �������
	struct tree *right;//������ �������
} Node;

unsigned char height(Node* localeNode);

int difference(Node* localeNode);

void fixHeight(Node* localeNode);

Node* rotateRight(Node* localeNode);

Node* rotateLeft(Node* localeNode);

Node* balance(Node* localeNode);

Node *addNode(Node *tree, char *key, char *value);

Node* searchByKey(Node* tree, char *key);

Node* findMin(Node* localeNode);

Node* removeMin(Node* localeNode);

Node* removeByKey(Node* tree, char *key);

void freeTree(Node* tree);