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


//Time complexity:O(n^2)
int JobsSelected(jobs array[],int n) {

	/* sort jobs array first,in non-increasing order */
	sort(array,n);

	//keep time slot for free time
	//use calloc func() to init value to 0
	//"0"=>free time slot

	int *timeslot = (int*)calloc(n, sizeof(int));
	int *findJob = (int*)calloc(n, sizeof(int));


	for (int i = 0;i < n;i++)
	{
		//checks slot from array[i] downto 0
		for (int index = minimum(n, array[i].Deadline)-1;index >= 0;index--)
		{
			if (!timeslot[index]) {
				findJob[index] = i;
				timeslot[index] = 1;
				break;
			}
		}
	}
	int totalprofit = 0;
	for (int i = 0;i < n;i++) {
		if (timeslot[i]) {
			printf("Job%d\t", array[findJob[i]].JobNumber);
			totalprofit += array[findJob[i]].profit;
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