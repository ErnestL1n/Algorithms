//author:
//https://github.com/ErnestL1n/


#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

//reference:
//Introduction to Algorithms, 3/e 
//https://devpost.com/Louis1992

//page690   Figure 25.1

/*
    adjacency matrix:

     i    
 j       (1)     (2)     (3)     (4)     (5)
    (1)   0       3       8      INF     -4

    (2)  INF      0      INF      1       7

    (3)  INF      4       0      INF     INF

    (4)   2      INF     -5       0      INF

    (5)  INF     INF     INF      6       0 

*/


#define INF 999999
#define V 5

//we don't use index 0
int Dist[V+1][V+1];
int Pi[V+1][V+1];


void PrintSolution();
void PrintPi();





void Floyd_Warshell(int Graph[][V+1]) {

	memset(Dist, 0, (sizeof Dist));
	memset(Pi, 0, (sizeof Pi));


	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			Dist[i][j] = Graph[i][j];
			
			/*
				Pi_ij(k)={
				          NIL                                         ,if wij=0 or i=j
				           i                                          ,else
						 }
			*/
			if (i == j || Graph[i][j] == INF) Pi[i][j] = INF;
			else Pi[i][j] = i;
		}
	}



	for (int k = 1; k <= V; k++) {
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {


				/* 
				Dij(k)={  
				          wij                                        ,if k=0
				          min{Dij(k-1), Dik(k-1)+Dkj(k-1)}           ,if k>=1
				        }
				*/


				/*
				Pi_ij(k)={
				            Pi_kj(k-1)                               ,if Dij(k-1)>Dik(k-1)+Dkj(k-1)
					    Pi_ij(k-1)                               ,else
					 }
				*/

				if (Dist[i][k] + Dist[k][j] < Dist[i][j]) {
					Dist[i][j] = Dist[i][k] + Dist[k][j];
					Pi[i][j] = Pi[k][j];
				}
			}
		}
	}

	PrintSolution();
	PrintPi();
}


void PrintSolution()
{
	printf("Following matrix shows the shortest distances"
		" between every pair of vertices \n");
	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			if (Dist[i][j] == INF)
				printf("%7s", "INF");
			else
				printf("%7d", Dist[i][j]);
		}
		printf("\n");
	}
}

void PrintPi()
{
	printf("Following matrix shows the Pi \n");
	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			if (Pi[i][j] == INF)
				printf("%7s", "NIL");
			else
				printf("%7d", Pi[i][j]);
		}
		printf("\n");
	}
}



int main()
{
	int graph[V+1][V+1] = {
		{INF, INF, INF, INF, INF, INF},
		{INF, 0, 3, 8, INF, -4},
		{INF, INF, 0, INF, 1, 7},
		{INF, INF, 4, 0, INF, INF},
		{INF, 2, INF, -5, 0, INF},
		{INF, INF, INF, INF, 6, 0}
	};


	//result is shown the same as Introduction to Algorithms, 3/e p.696
	Floyd_Warshell(graph);

	return 0;
}
