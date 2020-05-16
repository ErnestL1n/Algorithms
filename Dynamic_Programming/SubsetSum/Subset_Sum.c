//author:https://github.com/ErnestL1n
//reference:https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
//reference:https://sites.google.com/site/iitdarjuntyagi/home

#include<stdio.h>
#include<stdlib.h>

//return 1=true <=> has subset sum of set[] with given value

int SubsetSum(int set[], int value, int n) {

	//return subset[n][sum]
	int **subset=(int**)malloc(sizeof(int*)*(n+1));
	for (int i = 0;i <= n;i++)subset[i] = (int*)malloc(sizeof(int) * (value + 1));

	//sum=0=>always true
	for (int i = 0;i <= n;i++)subset[i][0] = 1;

	//n==0&&sum!=0=>alwats false
	for (int i = 1;i <= value;i++)subset[0][i] = 0;


	//bottom up fill up
	for(int i=1;i<=n;i++)
		for (int j = 1;j <= value;j++)
		{
			//case 1:check j=1~value<set[i-1]  ,must can't put
			if (j < set[i - 1])
				subset[i][j] = subset[i - 1][j];
			//case 2:check j=1~value>=set[i-1] can put or can't put
			else
				subset[i][j] = subset[i - 1][j - set[i - 1]] || subset[i - 1][j];
		}


	return subset[n][value];

}


// Driver program to test above function 
int main()
{
	int set[] = { 3, 34, 4, 12, 5, 2 };
	int sum = 9;
	int n = sizeof(set) / sizeof(set[0]);

	printf("given set with elements:{");
    for(int i = 0;i < n;i++)printf("%d ",set[i]);

	printf("\b}\n\n");

	if (SubsetSum(set, sum, n) == 1)
		printf("Found a subset with given sum=%d\n",sum);
	else
		printf("No subset with given sum=%d\n",sum);


	return 0;
}
