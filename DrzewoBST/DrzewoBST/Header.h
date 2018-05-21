#pragma once
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

struct node
{
	int key;
	struct node *left, *right;
};


struct node *newNode(int value);
void display(struct node *root);
struct node* add(struct node* node, int key);
struct node * findMinNode(struct node* node);
struct node * findMaxNode(struct node* node);
struct node* deleteNode(struct node* root, int key);
void paint(node *root, int distance);
void safeFile(node *root);



