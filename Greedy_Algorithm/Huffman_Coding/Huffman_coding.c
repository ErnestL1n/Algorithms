#include<stdio.h>
#include<stdlib.h>

//code for huffman coding
//Author:https://github.com/ErnestL1n



typedef struct node *treenodepointer;
typedef struct node {
	
	char data;

	double freq;

	treenodepointer leftchild, rightchild;

}treenode;

