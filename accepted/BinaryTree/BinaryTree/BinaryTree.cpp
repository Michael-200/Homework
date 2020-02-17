#include "BinaryTree.h"
#include <stdio.h>

Node *addNode(Node *tree, int key, char *value) 
{
	//���������� ����� � �����
	if (tree == NULL)
	{//���� ������ ���, �� ��������� ������
		tree = (Node*)malloc(sizeof(Node));//������ ��� ����
		tree->key = key;//����
		tree->item = strdup(value);//���� ������
		//������������� ������ �������
		tree->left = NULL;
		tree->right = NULL;
	}
	//���������� ����� ��� ������� ������
	//���� � ��� �� ����, ������� ��������
	else if (key == tree->key)
	{
		tree->item = strdup(value);//���� ������
	}

	//������� � ����� ��� ������ �����
	else if (key < tree->key)
	{
		tree->left = addNode(tree->left, key, value);
	}
	else
	{
		tree->right = addNode(tree->right, key, value);
	}
	return tree;
}

Node* searchByKey(Node* tree, int key)
{//����� ���� �� ��������� �����
	Node *found = NULL;
	if (tree == NULL)
	{
		return tree;
	}
	//���� ������ �� �����
	if (key == tree->key)
	{
		found = tree;
		return found;
	}
	//����� ����������� ������ �� �����
	else if (key < tree->key && tree->left != NULL)
	{
		found = searchByKey(tree->left, key);
	}
	else if (key > tree->key && tree->right != NULL)
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
	if (localeNode->left == NULL)
	{
		return localeNode->right;
	}
	localeNode->left = removeMin(localeNode->left); // ����� ���� � ������ ����
	return localeNode;
}

Node* removeByKey(Node* tree, int key)
{//�������� ���� �� ����� �� ����� key
	// ���� ������ ������, ������
	if (!tree)
	{
		return NULL;
	}
	//���� ������� ������ ������� ���� � ������ ����
	if (key < tree->key)
	{
		tree->left = removeByKey(tree->left, key);
	}
	//���� ������� ������ �������, ���� � ������� ����
	else if (key > tree->key)
	{
		tree->right = removeByKey(tree->right, key);
	}
	else
	{//�� ������ � �������, ������� ����� �������		
		Node* nodeLeft= tree->left;
		Node* nodeRight = tree->right;
		free(tree);//���������� �������� �������	
		printf("������ �������...\n");
		if (!nodeRight)
		{
			return nodeLeft;
		}
		Node* min = findMin(nodeRight);
		min->right = removeMin(nodeRight); //������ ��� ����������� ������� - ��� ������ ��������� ��������� ��� ��������
		min->left = nodeLeft; //����� ��� ����������� ������� - ����� ��� ���������
		return min;
	}
	return tree; 
}

void freeTree(Node* tree) 
{
	//������������ ������ � ������ ���� �����
	if (tree->left)
	{
		freeTree(tree->left);
	}
	if (tree->right)
	{
		freeTree(tree->right);
	}
	free(tree);
}