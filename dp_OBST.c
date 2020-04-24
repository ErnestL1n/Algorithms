//author:
//https://github.com/ErnestL1n/


//Note:In some cases,No dummy keys are given,set their values as 0


#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


//The OBST should have dummy keys
//If you don't want to add dummy keys,set them all zero

//reference:
//Introduction to Algorithms, 3/e 
//https://github.com/gzc


//How many distinct internal nodes
#define Nodes 5

//internal nodes
double p[Nodes + 1] = {INT_MIN, 0.15, 0.1, 0.05, 0.1, 0.2 };
//external nodes
double q[Nodes + 1] = {0.05, 0.1, 0.05, 0.05, 0.05, 0.1   };


//declare arrays :
//for recording root for i,j
int root[Nodes][Nodes];
//for recording sum of probabilities
double w[Nodes + 2][Nodes + 2];
//for recording search costs
double e[Nodes + 2][Nodes + 2];

//ProtoType
//Build OBST
double OBST(double*, double*, int);
//Use above result to build the OBST
void Construct_And_Print_OBST(int,int,int);


//Introduction to Algorithms, 3/e page.402 pseudocode
double OBST(double *p,double *q,int n) {
	

	//index begins from 1
	for (int i = 1;i <= n + 1;i++) {
		e[i][i - 1] = q[i - 1];
		w[i][i - 1] = q[i - 1];
	}
	//length l
	for (int l = 1;l <= n;l++) {
		for (int i = 1;i <= n - l + 1;i++) {
			int j = i + l - 1;
			e[i][j] = INT_MAX;
			w[i][j] = w[i][j - 1] + p[j] + q[j];
			for (int r = i;r <= j;r++) {

				//Recursive Formulation
				double t= e[i][r - 1] + e[r + 1][j] + w[i][j];


				if (t < e[i][j])
				{
					e[i][j] = t;
					root[i][j] = r;
				}
			}
		}
	}
	//optimal cost stores here
	return e[1][Nodes];
}


void Construct_And_Print_OBST(int i, int j, int r)
{
	//root for i&j
	int RootChild = root[i][j];

	//Root for whole tree is stored here
	if (RootChild == root[1][Nodes])
	{
		//whole tree's root
		printf("K%d is root \n", RootChild);
		//recursively trace left and right subtree's root
		Construct_And_Print_OBST(i, RootChild - 1, RootChild);
		Construct_And_Print_OBST(RootChild + 1, j, RootChild);
		return;
	}


	//fault
	if (j < i - 1)
		return;



	//dummy keys case
	else if (j == i - 1)
	{
		if (j < r)
			//left dummy keys
			printf("D%d is the left  child of K%d\n", j, r);
		else
			printf("D%d is the right child of K%d\n", j, r);
		return;
	}


	//internal keys case
	else
	{
		if (RootChild < r)
			printf("K%d is the left  child of K%d\n", RootChild, r);
		else
			printf("K%d is the right child of K%d\n", RootChild, r);
	}

	Construct_And_Print_OBST(i, RootChild - 1, RootChild);
	Construct_And_Print_OBST(RootChild + 1, j, RootChild);
}


//driver program to test
int main()
{


	printf("OBST Expected Cost(Minimum Cost) is %f\n\n", OBST(p, q, Nodes));
	Construct_And_Print_OBST(1, Nodes, INT_MIN);
}

