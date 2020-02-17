#include "BinaryTree.h"
#include <stdio.h>


unsigned char height(Node* localeNode) //��������� ������ �������
{//���� ������� ���, ����� 0 ����� ������ ��������� ���� �������
	return localeNode ? localeNode->height : 0;
}

int difference(Node* localeNode)
{//�������� ����� ����� ���������
	return height(localeNode->right) - height(localeNode->left); //���������� �������
}

void fixHeight(Node* localeNode)
{//������� ������, ���� ������������������ ��������
	unsigned char hleft = height(localeNode->left); //������ ������ ����
	unsigned char hright = height(localeNode->right); //������ ������� ����
	//������ ������� - ��� ������ ���� � ���� ������� ���� 1
	localeNode->height = (hleft>hright ? hleft : hright) + 1;
}

Node* rotateRight(Node* localeNode) //������ ������� ������ nd
{
	Node* temp = localeNode->left;
	localeNode->left = temp->right;
	temp->right = localeNode;
	fixHeight(localeNode);
	fixHeight(localeNode);
	free(temp);
	return localeNode;
}

Node* rotateLeft(Node* localeNode) //����� ������� ������ nd
{
	Node* temp = localeNode->right;
	localeNode->right = temp->left;
	temp->left = localeNode;
	fixHeight(localeNode);
	fixHeight(temp);
	return temp;
}

Node* balance(Node* localeNode)
{//������������ ���� localeNode �����
	fixHeight(localeNode);
	if (difference(localeNode) == 2)
	{
		if (difference(localeNode->right) < 0)
		{
			localeNode->right = rotateRight(localeNode->right);
		}
		return rotateLeft(localeNode);
	}
	if (difference(localeNode) == -2)
	{
		if (difference(localeNode->left) > 0)
		{
			localeNode->left = rotateLeft(localeNode->left);
		}
		return rotateRight(localeNode);
	}
	return localeNode; //������������ �� �����
}

Node *addNode(Node *tree, char *key, char *value) 
{
	//���������� ����� � �����
	int tSame = 0;//��� ������ �����
	if (tree != NULL)
	{
		tSame = strcmp(key, tree->key);
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

Node* findMin(Node* localeNode) // ����� ���� � ����������� ������ � ������ p 
{
	return localeNode->left ? findMin(localeNode->left) : localeNode; //���� ���� ����� ���, ���� � ���� ����� ����� � ���� �������
}

Node* removeMin(Node* localeNode)
{//�������� ���� � ����������� ������ �� ������ p
	//���� ��� ������ ���� ������ ��� �������
	if (localeNode->left == 0)
	{
		return localeNode->right;
	}
	localeNode->left = removeMin(localeNode->left); // ����� ���� � ������ ����
	return balance(localeNode); //����������� ������
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
		Node* min = findMin(ndRight);
		min->right = removeMin(ndRight); //������ ��� ����������� ������� - ��� ������ ��������� ��������� ��� ��������
		min->left = ndLeft; //����� ��� ����������� ������� - ����� ��� ���������
		return balance(min); //����������� ������� �������
	}
	return balance(tree); //�� ������ �� �����, ����������� ������
}

void freeTree(Node* tree) 
{
	//������������ ������ � ������ ���� �����
	if (tree == NULL) return;
	if (tree->left)   freeTree(tree->left);
	if (tree->right)  freeTree(tree->right);
	free(tree);
}