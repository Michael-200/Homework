#include "BinaryTree.h"
#include <stdio.h>





Node *addNode(Node *tree, int key, char *value) {
	//���������� ����� � �����

	if (tree == NULL)
	{//���� ������ ���, �� ��������� ������
		tree = (Node *)malloc(sizeof(Node));//������ ��� ����
		tree->key = key;//����
		tree->item = strdup(value);//���� ������
		tree->count = 1;
		//������������� ������ �������
		tree->left = NULL;
		tree->right = NULL;
	}
	//���������� ����� ��� ������� ������
	//���� � ��� �� ����, ������� ��������
	else if (key == tree->key)
	{
		tree->count++;
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
	if (localeNode->left == 0)
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
		return min; //����������� ������� �������
	}
	return tree; //�� ������ �� �����, ����������� ������
}

void freeTree(Node* tree) {
	//������������ ������ � ������ ���� �����
	if (tree->left)   freeTree(tree->left);
	if (tree->right)  freeTree(tree->right);
	free(tree);
}