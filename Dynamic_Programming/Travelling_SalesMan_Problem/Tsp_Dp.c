//author:
//https://github.com/ErnestL1n/


#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

//reference:
//Foundations of Algorithms, Fifth Edition,Richard Neapolitan
//graph: CLRS 3/E page690   Figure 25.1

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
#define Citys 5

//we don't use index 0
int City[Citys + 1][Citys + 1];
int visited[Citys + 1];

int PrintPath(int city) {

	for (int i = 0;i <= Citys;i++)visited[i] = 0;


};



int main()
{
	int graph[V + 1][V + 1] = {
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
