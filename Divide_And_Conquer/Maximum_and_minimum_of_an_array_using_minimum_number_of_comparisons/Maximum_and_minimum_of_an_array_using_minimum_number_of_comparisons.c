//Write a C function to return minimum and maximum in an array. You program should make minimum number of comparisons.

//author:https://github.com/ErnestL1n

//reference:https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/

#include<stdio.h>
#include<stdlib.h>



typedef struct Pair {
	int min;
	int max;
}Pair;




//Version1:(Linear Search)
//Time Complexity: O(n)
//total number of comparisons:
//1 + 2(n - 2) in worst case <=> in descending order
//1 + n ¡V 2 in best case <=> in ascending order

Pair getMinAndMaxVersion1(int array[],int n) {

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


//Version2:(Divide And Conquer)
//Time Complexity: O(n)
//total number of comparisons:
//(3n / 2 - 2) comparisons if n is a power of 2. 
//And it does more than 3n / 2 - 2 comparisons if n is not a power of 2.


Pair getMinAndMaxVersion2(int array[],int low,int high) {
	
	Pair minmax,MMleft,MMright;
	int middle;
	
	//base case:

	//one element
	if (low == high) {
		minmax.max = minmax.min = array[high];
		return minmax;
	}

	//two element=>one compare
	if (high==low+1) {
		if (array[high] > array[low]) {
			minmax.max = array[high];
			minmax.min = array[low];
		}
		else {
			minmax.max = array[low];
			minmax.min = array[high];
		}
		return minmax;
	}

	//recursive case,more than 2 elements
	middle = (low + high) / 2;
	//compare left and right part
	MMleft=getMinAndMaxVersion2(array,low,middle);
	MMright=getMinAndMaxVersion2(array,middle+1,high);

	//find minimum of two parts
	minmax.min = (MMleft.min < MMright.min) ? MMleft.min : MMright.min;


	//find maximum of two parts
	minmax.max = (MMleft.max > MMright.max) ? MMleft.max : MMright.max;


	return minmax;
}




//Version3:(Compare in pairs)
//Time Complexity: O(n)

//If n is odd : 3 * (n - 1) / 2

//If n is even : 1 Initial comparison for initializing min and max,
//3(n - 2) / 2 comparisons for rest of the elements=>1 + 3 * (n - 2) / 2 = 3n / 2 - 2


Pair getMinAndMaxVersion3(int array[],int n) {
	
	//index for where I have compared
	int index;

	Pair minmax;

	//If numbers of array is even
	if (n % 2 == 0) {
		//choose first and second element to begin comparison
		if (array[0] > array[1]) {
			minmax.max = array[0];
			minmax.min = array[1];
		}
		else {
			minmax.max = array[1];
			minmax.min = array[0];
		}

		//index begins with 2
		index = 2;
	}


	//If numbers of array is odd
	else {
		//choose first element to be min and max
		minmax.max = minmax.min = array[0];

		//index begins with 1
		index = 1;
	}

	//numbers of elements in remaining part must be even

	//keep doing until index reach to n
	while (index != n)
	{
		if (array[index] > array[index + 1]) {
			if (array[index] > minmax.max)minmax.max = array[index];
			if (array[index + 1] < minmax.min)minmax.min = array[index + 1];
		}
		else {
			if (array[index + 1] > minmax.max)minmax.max = array[index + 1];
			if (array[index] < minmax.min)minmax.min = array[index];
		}
		index += 2;
	}
	return minmax;
}



int main() {
	int array[] = { 13123,1791,9,1111,1238123,1 };
	int n = sizeof(array) / sizeof(array[0]);

	for (int i = 0;i < n;i++)printf("array[%d]=%10d\n", i, array[i]);

	//Can call different Version
	Pair minmax = getMinAndMaxVersion3(array,n);



	printf("Maximum element is %10d\n", minmax.max);
	printf("Minimum element is %10d\n", minmax.min);

	return 0;
}