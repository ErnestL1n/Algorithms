#include<stdio.h>
#include<stdlib.h>


//Greedy Fractional Knapsack Problem

//Author:https://github.com/ErnestL1n

//define struct Items


typedef struct Item {
	int value;
	int weight;
}items;


//Comparison function to sort Item according to value/weight ratio 

int compare(items *A, items *B) {
	double ratio1 = (double)A->value / A->weight;
	double ratio2 = (double)B->value / B->weight;
	
	if (ratio1 > ratio2)return -1;
	else if (ratio1 == ratio2)return 0;
	else return 1;
}


//sort items on basis of ratio 
//Note the compare function return value<0  => A is before B after sorting
void sort(items* array, int arrayLen) {
	qsort(array, (size_t)arrayLen, sizeof(items), compare);
}


double FracKnap(int WeightOfBag, items array[],int n) {

	/* sort item array first,in non-increasing order */
	sort(array,n);

	/* weights in bag until full */
	int CurrentBagWeight = 0;

	/* Values in Bag,finally will be returned */
	double value = 0.0;

	for (int i = 0;i < n;i++) {


		if (CurrentBagWeight + array[i].weight <= WeightOfBag) {
			//we can put it in
			value += array[i].value;
			CurrentBagWeight += array[i].weight;
		}
		else {
			//can't put whole
			//we put item in fractional part
			int RemainBag = WeightOfBag-CurrentBagWeight;
			value += array[i].value * ((double)RemainBag / array[i].weight);
			//break for loop
			break;
		}

	}
	return value;
}

int main() {

	int W = 30;

	items array[] = { {50,5},{60,10,},{140,20} };
	int n = sizeof(array) / sizeof(array[0]);
	printf("Bookbag Capacity is %d\n",W);
	for(int i=0;i<n;i++)
		printf("Item%d's value is %d, weight is %d \t",(i+1),array[i].value,array[i].weight);
	printf("\n");
	printf("The Maximum Value BookBag can take(fractional parts are allowed) is : %5.2f\n", FracKnap(W, array, n));

	return 0;
}