//Write a C function to return minimum and maximum in an array. You program should make minimum number of comparisons.

//author:https://github.com/ErnestL1n

#include<stdio.h>
#include<stdlib.h>


/*
We do the naive version first:
A simple solution is to iteratively compare each element with current max and min
It requires 2n comparison
*/



typedef struct Pair {
	int min;
	int max;
}Pair;


//function to return max min
Pair getMinAndMax(int array[],int n) {

	Pair minmax;
	
	if (n == 1) {
		minmax.max = array[0];
		minmax.min = array[0];
		return minmax;
	}

	if (array[0] > array[1])
	{
		minmax.max = array[0];
		minmax.min = array[1];
	}
	else {
		minmax.max = array[1];
		minmax.min = array[0];
	}

	for (int i = 2;i < n;i++) {
		if (array[i] > minmax.max)
			minmax.max = array[i];
		else if (array[i] < minmax.min)
			minmax.min = array[i];
	}


	return minmax;

}


int main() {
	int array[] = { 13123,1791,9,1111,1238123,1 };
	int n = sizeof(array) / sizeof(array[0]);
	Pair minmax = getMinAndMax(array, n);
	printf("Maximum element is %d\n", minmax.max);
	printf("Minimum element is %d\n", minmax.min);
}