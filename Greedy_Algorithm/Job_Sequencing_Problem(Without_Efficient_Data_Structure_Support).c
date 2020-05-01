#include<stdio.h>
#include<stdlib.h>


//Greedy Job_Sequencing_Problem
//An efficient way to implement disjoint set data structures
//in another c file in my github site

//Author:https://github.com/ErnestL1n

//define struct Job
//with Job number
//Job deadline(integer)
//Job profit(integer)

typedef struct Job {
	int JobNumber;
	int Deadline;
	int profit;
}jobs;



//utility function to return min
int minimum(int a, int b) {
	return a < b ? a : b;
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



//1) Sort all jobs in decreasing order of profit.
//2) Iterate on jobs in non-increasing order of profit.
//   For each job ,Do the following :
//a) Find a time slot i, such that slot is empty and i < deadline and i is greatest.
//   Put the job in this slot and mark this slot filled.
//b) If no such i exists, then ignore the job.


void printJobsSelected(jobs array[],int n) {

	/* sort jobs array first,in non-increasing order */
	sort(array,n);

	//keep time slot for free time
	//use calloc func() to init value to 0
	//"0"=>free time slot

	int *timeslot = (int*)calloc(n, sizeof(int));
	int *findJob = (int*)malloc(sizeof(int)*n);


	for (int i = 0;i < n;i++)
	{
		//checks slot from array[i] downto 0
		for (int index = minimum(n, array[i].Deadline);index >= 0;index--)
		{
			if (!timeslot[index]) {
				findJob[index] = i;
				timeslot[index] = 1;
				break;
			}
		}
	}
	for (int i = 0;i < n;i++) {
		if (timeslot[i])
			printf("%d\t", array[findJob[i]].JobNumber);
	}
}

// Driver program to test methods 
int main()
{
	jobs array[] = { {1, 2, 100}, {2, 1, 19}, {3, 2, 27},
				   {4, 1, 25}, {5, 3, 15} };
	int n = sizeof(array) / sizeof(array[0]);
	
	printJobsSelected(array, n);
	return 0;
}