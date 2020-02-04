#include <stdio.h>
#include <stdlib.h>


typedef struct BinartTree
{
	int count;//����� ���������
	char *key, *item;//����� � ���� ������
	unsigned char height; //������ ���������
	struct tree *left;//����� �������
	struct tree *right;//������ �������
} Node;

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
	int tSame;//��� ������ �����
	if (tree == NULL) 
	{//���� ������ ���, �� ��������� ������
		tree = (Node *)malloc(sizeof(Node));//������ ��� ����
		tree->key = strdup(key);//����
		tree->item = strdup(value);//���� ������
		tree->count = 1;
		//������������� ������ �������
		tree->left = tree->right = NULL;
	}
	//���������� ����� ��� ������� ������
	//���� � ��� �� ����, ������� ��������
	else if ((tSame = strcmp(key, tree->key)) == 0)
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
		Node* min;
		min = findmin(ndRight);
		min->right = removemin(ndRight); //������ ��� ����������� ������� - ��� ������ ��������� ��������� ��� ��������
		min->left = ndLeft; //����� ��� ����������� ������� - ����� ��� ���������
		return balance(min); //����������� ������� �������
	}
	return balance(tree); //�� ������ �� �����, ����������� ������
}

char *strToLower(char *value)
{//�������������� ������ � ������ �������
	const len = strlen(value);
	for (int i = 0; i<len; i++)
	{
		if (value[i] >= 'A' && value[i] <= 'Z')
		{
			value[i] += 'z' - 'Z';
		}
		if (value[i] >= '�' && value[i] <= '�')
		{
			value[i] += '�' - '�';
		}
	}
	return value;
}

int menu()
{//���������� ���� ���������
	system("CLS");//������� ���� �������
	printf("[MENU]\n");
	printf("1. ���� ��������\n");
	printf("2. ����� �������� �� �������\n");
	printf("3. �������� ������� ��������� �����\n");
	printf("4. �������� ������\n");
	printf("5. �����\n");
	printf("Input number: ");

	char *choose = (char *)malloc(100*sizeof(char));//��������� ������ ��� �����;
	scanf("%s", choose);
	//������� ���������� ������ ����
	if (choose < '0' && choose >'9')
	{
		free(choose);//�����������������
		return 0;
	}
	else
	{
		int nChouse = atoi(choose);
		free(choose);//�����������������
		return nChouse;
	}
}

int test()
{
	//������������ �������
	
	//�������� �� ����������
	Node *tree = NULL;
	char *key = "a";
	tree = addNode(tree, key, "value1");
	if (!tree)
	{
		return 0;
	}
	//�������� �� ��������
	tree = removeByKey(tree, key);
	if (tree)
	{
		return 0;
	}

	//�������� �� ������� �������� � ������ �������
	char *value = (char *)malloc(100 * sizeof(char));//��������� ������ ��� ��������
	strcpy(value, "���");
	if (strcmp(strToLower(value), "���") != 0)
	{
		return 0;
	}

	return 1;
}

int main()
{
	system("chcp 1251");
	
	if (!test())
	{
		printf("���� �� �������...\n");
		system("pause");
	}
	
	Node *tree = NULL;//������ ��� ����
	char *key = (char *)malloc(100*sizeof(char));//��������� ������ ��� �����
	char *value = (char *)malloc(100*sizeof(char));//��������� ������ ��� ��������



	int loop = 1;
	while (loop)
	{
		int choose = menu();
		switch (choose)
		{
			case 1:
			{
				system("cls");
				printf("���������� ����� ����������\n");
				printf("������� �������: ");
				scanf("%s", key);
				key = strToLower(key);
				printf("������� ����� ��������: ");
				scanf("%s", value);
				tree = addNode(tree, key, value);
				printf("������ �������!\n");
				system("pause");
				break;
			}

			case 2:
			{
				system("cls");
				printf("����� ���������� �� �����\n");
				printf("������� �������: ");
				scanf("%s", key);
				key = strToLower(key);
				Node *found = searchByKey(tree, key);
				if (found)
				{
					printf("\n%s %s\n", found->key, found->item);
				}
				else
				{
					printf("������ �� �������!\n");
				}
				system("pause");
				break;
			}
				

			case 3:
			{
				system("cls");
				printf("�������� �����\n");
				printf("������� ������� ��� �������� �����: ");
				scanf("%s", key);
				key = strToLower(key);
				Node *searchKey = searchByKey(tree, key);
				if (searchKey)
				{
					printf("������ ���� ����������\n");
				}
				else
				{
					printf("������ ����� ���!\n");
				}
				system("pause");				
				break;
			}
				
			case 4:
			{
				system("cls");
				printf("�������� ������\n");
				printf("������� ������� ��� ��������: ");
				scanf("%s", key);
				key = strToLower(key);
				tree = removeByKey(tree, key);
				system("pause");
				break;
			}
				
			case 5:
			{
				loop = 0;
				break;
			}

			default:
			{
				printf("�������� �����...\n");
				break;
			}
				
		}//switch
	}//while 

	free(tree);
	free(value);
	free(key);
	
	return 0;
}