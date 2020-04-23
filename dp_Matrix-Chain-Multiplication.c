//author:
//https://github.com/ErnestL1n/


#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


//reference:
//Introduction to Algorithms, 3/e 
//https://github.com/gzc


//dimensions store in p[]


//m[i,j] values give the costs of optimal solutions to subproblems, but they
//do not provide all the information we need to construct an optimal solution.


//To help us do so, we define s[i,j] to be a value of k at which we split the product
//Ai*Ai+1*.......*Aj in an optimal parenthesization.


//A1:30*35
//A2:35*15
//A3:15*5
//A4:5*10
//A5:10*20
//A6:20*25


//m[][]  s[][]   should be return ,we keep them in parameters
//Introduction to Algorithms, 3/e page.375 pseudocode
void MATRIX_CHAIN_ORDER(int *p, int **m, int **s, int n)
{
	//n=p.length-1

	for (int i = 1;i <= n;i++)m[i][i] = 0;

	
	//length l
	for (int l = 2;l <= n;l++)
	{
		for (int i = 1;i <= n - l + 1;i++)
		{
			int j = i + l - 1;
			m[i][j] = INT_MAX;
			for (int k = i;k <= j - 1;k++)
			{
				int q = m[i][k] + m[k + 1][j] + p[i - 1]*p[k]*p[j];
				if (q < m[i][j])
				{
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
}


//Introduction to Algorithms, 3/e page.377 pseudocode
void PRINT_OPTIMAL_PARENS(int **s, int i, int j)
{
	if (i == j)
		printf("A%d*", i);
	else {
		printf("(");
		PRINT_OPTIMAL_PARENS(s, i, s[i][j]);
		PRINT_OPTIMAL_PARENS(s, s[i][j] + 1, j);
		printf("\b)");
	}
}



//driver program to test
int main()
{
	int n = 6;
	int p[7];
	p[0] = 30;
	p[1] = 35;
	p[2] = 15;
	p[3] = 5;
	p[4] = 10;
	p[5] = 20;
	p[6] = 25;


	
	int** m = (int**)calloc(n+1,sizeof(int*));
	for (int i = 1;i <= n;i++)m[i] = (int*)calloc(n + 1, sizeof(int));


	int** s = (int**)calloc(n, sizeof(int*));
	for (int i = 1;i <= n;i++)s[i] = (int*)calloc(n, sizeof(int));


	for (int i = 1;i <= n;i++)printf("A%d:%d*%d \t ",i,p[i-1],p[i]);

	printf("\n\n");

	

	MATRIX_CHAIN_ORDER(p, (int**)m, (int**)s, n);


	printf("The MATRIX_CHAIN_ORDER makes the minimum cost:%d\n\n", m[1][n]);
	

	//first is in s[1][n]
	PRINT_OPTIMAL_PARENS((int**)s, 1, n);


	printf("\n\n");


	return 0;
}