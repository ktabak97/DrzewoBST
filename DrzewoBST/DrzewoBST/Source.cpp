#include "Header.h"

struct node *newNode(int value)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = value;
	temp->left = temp->right = NULL;
	return temp;
}

void display(struct node *root)
{
	if (root != NULL)
	{
		display(root->left);
		cout << root->key << endl;
		display(root->right);
	}
}

struct node * findMinNode(struct node* node)
{
	struct node* seek = node;

	while (seek->left != NULL)
		seek = seek->left;

	cout << seek->key << " <- This is min value" << endl;
	return seek;
}

struct node * findMaxNode(struct node* node)
{
	struct node* seek = node;

	while (seek->right != NULL)
		seek = seek->right;

	cout << seek->key << " <- This is max value" << endl;
	return seek;
}


struct node* add(struct node* node, int key)
{
	if (node == NULL) return newNode(key);

	if (key < node->key)
		node->left = add(node->left, key);
	else if (key > node->key)
		node->right = add(node->right, key);

	return node;
}

struct node* deleteNode(struct node* root, int key)
{
	if (root == NULL) return root;

	if (key < root->key)
		root->left = deleteNode(root->left, key);

	else if (key > root->key)
		root->right = deleteNode(root->right, key);

	else
	{
		if (root->left == NULL)
		{
			struct node *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			struct node *temp = root->left;
			free(root);
			return temp;
		}

		struct node* temp = findMinNode(root->right);
		root->key = temp->key;
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}
void paint(struct node *root, int distance)
{
	int place = 10;

	if (root == NULL)
		return;

	distance += place;
	paint(root->right, distance);

	cout << endl;
	for (int i = place; i < distance; i++)
	{
		cout << " ";
	}
	cout << root->key << endl;
	paint(root->left, distance);
}
