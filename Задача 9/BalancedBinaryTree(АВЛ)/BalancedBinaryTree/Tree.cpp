#include "Tree.h"
#include <stdio.h>


unsigned char height(Node* tNode) //��������� ������ �������
{//���� ������� ���, ����� 0 ����� ������ ��������� ���� �������
	return tNode ? tNode->height : 0;
}

int bfactor(Node* tNode)
{//�������� ����� ����� ���������
	return height(tNode->right) - height(tNode->left); //���������� �������
}

void fixheight(Node* tNode)
{//������� ������, ���� ������������������ ��������
	unsigned char hleft = height(tNode->left); //������ ������ ����
	unsigned char hright = height(tNode->right); //������ ������� ����
	//������ ������� - ��� ������ ���� � ���� ������� ���� 1
	tNode->height = (hleft>hright ? hleft : hright) + 1;
}

Node* rotateright(Node* tNode) //������ ������� ������ nd
{
	Node* temp = tNode->left;
	tNode->left = temp->right;
	temp->right = tNode;
	fixheight(tNode);
	fixheight(tNode);
	return tNode;
}

Node* rotateleft(Node* tNode) //����� ������� ������ nd
{
	Node* temp = tNode->right;
	tNode->right = temp->left;
	temp->left = tNode;
	fixheight(tNode);
	fixheight(temp);
	return temp;
}

Node* balance(Node* tNode)
{//������������ ���� tNode �����
	fixheight(tNode);
	if (bfactor(tNode) == 2)
	{
		if (bfactor(tNode->right) < 0)
		{
			tNode->right = rotateright(tNode->right);
		}
		return rotateleft(tNode);
	}
	if (bfactor(tNode) == -2)
	{
		if (bfactor(tNode->left) > 0)
		{
			tNode->left = rotateleft(tNode->left);
		}
		return rotateright(tNode);
	}
	return tNode; //������������ �� �����
}

Node *addNode(Node *tree, char *key, char *value) {
	//���������� ����� � �����
	int tSame = 0;
	if (tree != NULL)
	{
		strcmp(key, tree->key);//��� ������ �����
	}
	
	if (tree == NULL)
	{//���� ������ ���, �� ��������� ������
		tree = (Node *)malloc(sizeof(Node));//������ ��� ����
		tree->key = strdup(key);//����
		tree->item = strdup(value);//���� ������
		tree->count = 1;
		//������������� ������ �������
		tree->left = NULL;
		tree->right = NULL;
	}
	//���������� ����� ��� ������� ������
	//���� � ��� �� ����, ������� ��������
	else if (tSame == 0)
	{
		tree->count++;
		tree->item = strdup(value);//���� ������
	}
	//������� � ����� ��� ������ �����
	else if (tSame < 0)
	{
		tree->left = addNode(tree->left, key, value);
	}
	else
	{
		tree->right = addNode(tree->right, key, value);
	}
	return balance(tree);
}

Node* searchByKey(Node* tree, char *key)
{//����� ���� �� ��������� �����
	int tSame;
	Node *found = NULL;
	if (tree == NULL)
	{
		return tree;
	}
	//���� ������ �� �����
	if ((tSame = strcmp(key, tree->key)) == 0)
	{
		found = tree;
		return found;
	}
	//����� ����������� ������ �� �����
	else if (tSame < 0 && tree->left != NULL)
	{
		found = searchByKey(tree->left, key);
	}
	else if (tSame > 0 && tree->right != NULL)
	{
		found = searchByKey(tree->right, key);
	}

	//���� �� ������
	return found;
}

Node* findmin(Node* tNode) // ����� ���� � ����������� ������ � ������ p 
{
	return tNode->left ? findmin(tNode->left) : tNode; //���� ���� ����� ���, ���� � ���� ����� ����� � ���� �������
}

Node* removemin(Node* tNode)
{//�������� ���� � ����������� ������ �� ������ p
	//���� ��� ������ ���� ������ ��� �������
	if (tNode->left == 0)
	{
		return tNode->right;
	}
	tNode->left = removemin(tNode->left); // ����� ���� � ������ ����
	return balance(tNode); //����������� ������
}

Node* removeByKey(Node* tree, char *key)
{//�������� ���� �� ����� �� ����� key
	// ���� ������ ������, ������
	if (!tree)
	{
		return NULL;
	}
	int tSame = strcmp(key, tree->key);
	//���� ������� ������ ������� ���� � ������ ����
	if (tSame < 0)
	{
		tree->left = removeByKey(tree->left, key);
	}
	//���� ������� ������ �������, ���� � ������� ����
	else if (tSame > 0)
	{
		tree->right = removeByKey(tree->right, key);
	}
	else
	{//�� ������ � �������, ������� ����� �������		
		Node* ndLeft = tree->left;
		Node* ndRight = tree->right;
		free(tree);//���������� �������� �������	
		printf("������ �������...\n");
		if (!ndRight)
		{
			return ndLeft;
		}
		Node* min = findmin(ndRight);
		min->right = removemin(ndRight); //������ ��� ����������� ������� - ��� ������ ��������� ��������� ��� ��������
		min->left = ndLeft; //����� ��� ����������� ������� - ����� ��� ���������
		return balance(min); //����������� ������� �������
	}
	return balance(tree); //�� ������ �� �����, ����������� ������
}