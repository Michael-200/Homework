#pragma once


typedef struct BinartTree
{
	int count;//����� ���������
	char *key, *item;//����� � ���� ������
	unsigned char height; //������ ���������
	struct tree *left;//����� �������
	struct tree *right;//������ �������
} Node;

unsigned char height(Node* tNode);

int bfactor(Node* tNode);

void fixheight(Node* tNode);

Node* rotateright(Node* tNode);

Node* rotateleft(Node* tNode);

Node* balance(Node* tNode);

Node *addNode(Node *tree, char *key, char *value);

Node* searchByKey(Node* tree, char *key);

Node* findmin(Node* tNode);

Node* removemin(Node* tNode);

Node* removeByKey(Node* tree, char *key);