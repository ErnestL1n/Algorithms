//Author:
//https://github.com/ErnestL1n/AlogorithmsInC
//Reference:
//https://www.amazon.com/Introduction-Algorithms-3rd-MIT-Press/dp/0262033844
//https://www.geeksforgeeks.org
//https://leetcode.com/
//environment:
//https://visualstudio.microsoft.com/zh-hant/vs/?rr=https%3A%2F%2Fwww.google.com%2F



#include <stdio.h>
#include<stdlib.h>
#include<string.h>



    //create an utility function to
int minimum(int a, int b) {
	return a < b ? a : b;
}



int minDistance(char* word1, char* word2) {      //Goal : convert word1 to word2


    //we first get the length of the string
	int length1 = strlen(word1);
	int length2 = strlen(word2);


	//now we create a DP array with row "2" dimension and column "string1.length"

	//dynamic allocate array
	int** DParray = (int**)malloc(sizeof(int*) * 2);
	for (int i = 0;i < 2;i++)
		*(DParray + i) = (int*)malloc(sizeof(int) * (length1 + 1));



	//use function to fill up array first
	for (int i = 0;i < 2;i++)
		for (int j = 0;j < (length1 + 1);j++)
			DParray[i][j] = 0;

	//starting filling up the array
	//with the base case,string2 is empty ,we perform deletion

	for (int i = 0;i <= length1;i++)
		DParray[0][i] = i;



	//recursive case
	for (int i = 1;i <= length2;i++) {   //we start from i=1 because we have already filled up array
		for (int j = 0;j <= length1;j++) {

			//if string1 is empty ,we perform insertion to string1 to get second string
			if (j == 0)DParray[i % 2][j] = i;

			//if two string have same character
			//we assume the 2 row upper is the odd number otherwise it is even number
			//if the two string have the same character
			else if (word1[j - 1] == word2[i - 1])DParray[i % 2][j] = DParray[(i - 1) % 2][j - 1];


			// not the above case we get the min of the three 
			else DParray[i % 2][j] = 1 + minimum(DParray[(i - 1) % 2][j - 1]
				, minimum(DParray[(i - 1) % 2][j], DParray[(i % 2)][j - 1]));


		}
	}
	//the final length is store in DParray[length2 % 2][length1]
	return DParray[length2 % 2][length1];

	free(DParray);

}


// Driver program 
int main(void)
{
	char *str1 = "Hello";
	char *str2 = "Word";
	printf("%d",minDistance(str1, str2));
	return 0;
}


//Time complexity O(m*n)
//Auxiliary Space O(m)
