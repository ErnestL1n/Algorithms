#include<stdio.h>
#include<stdlib.h>
#include<limits.h>



//Greedy Job_Sequencing_Problem
//An efficient way to implement disjoint set data structures

//There are at most 3N total MAKE-SET, SimpleUnion, and FindSet operations
//each of which occur at most N times
//by Theorem 21.14() the runtime(Amortized Analysis) is O(n*£\(n)) 
//Introduction to Algorithms, 3rd Edition(page 581)



//Author:https://github.com/ErnestL1n

//reference:https://www.geeksforgeeks.org/job-sequencing-using-disjoint-set-union/


//define struct Job
//with Job number
//Job deadline(integer)
//Job profit(integer)


typedef struct Job {
	int JobNumber;
	int Deadline;
	int profit;
}jobs;



//define disjoint sets structure

static int* parent;

void MakeSet(n) {
	parent = calloc((n + 1), sizeof(int));
	for (int i = 0;i <= n;i++)
		parent[i] = i;
}


//simple way:let x be y's parent
void SimpleUnion(int x,int y) {
	parent[y] = x;
}


int FindSet(int x) {
	if (x != parent[x])
		parent[x] = FindSet(parent[x]);
	return parent[x];
}


//utility function to return max
int maximum(int a, int b) {
	return a > b ? a : b;
}


//Comparison function to sort Job according to Profit
//non-increasing order

int compare(jobs* A, jobs* B) {

	int profit1 = A->profit;
	int profit2 = B->profit;

	if (profit1 > profit2)return -1;
	else if (profit1 == profit2)return 0;
	else return 1;
}

//sort items on basis of ratio 
//Note the compare function return value<0  => A is before B after sorting

void sort(jobs* array, int arrayLen) {
	qsort(array, (size_t)arrayLen, sizeof(jobs), compare);
}



// Functions returns the maximum deadline from the set of jobs 
int findMaxDeadline(struct Job arr[], int n)
{
	int MaxDeadLine = INT_MIN;
	for (int i = 0; i < n; i++)
		MaxDeadLine = maximum(MaxDeadLine, arr[i].Deadline);
	return MaxDeadLine;
}




int JobsSelected(jobs array[], int n) {

	/* sort jobs array first,in non-increasing order */
	sort(array, n);

	//for maximum deadline among all jobs
	int MaxDeadLine = findMaxDeadline(array, n);

	//Build disjoint set data structure
	MakeSet(MaxDeadLine);


	//profit to be return
	int totalprofit = 0;


	for (int i = 0;i < n;i++) {

		int freeTimeSlot = FindSet(array[i].Deadline);

	
		if (freeTimeSlot > 0) {
			SimpleUnion(FindSet(freeTimeSlot - 1), freeTimeSlot);

			printf("Job%d\t", array[i].JobNumber);

			totalprofit += array[i].profit;
		}
	}

	printf("are selected\n\n");

	return totalprofit;
}


// Driver program to test methods 
int main()
{
	jobs array[] = { {1, 2, 40}, {2, 4, 15}, {3, 3, 60},
					 {4, 2, 20}, {5, 3, 10}, {6, 1, 45},
					 {7, 1, 55} };

	printf("JobNumber\t DeadLine\t Profit\n");
	int n = sizeof(array) / sizeof(array[0]);
	for (int i = 0;i < n;i++)
		printf("%5d\t\t%5d\t\t%5d\n", array[i].JobNumber, array[i].Deadline, array[i].profit);
	printf("\n");
	printf("Select jobs and Maximum the total profit within deadlines:\n");
	printf("\n");
	printf("Total profit is: %d\n", JobsSelected(array, n));
	return 0;
}