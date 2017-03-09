#include<stdio.h>
#include<time.h>    // time()
#include<stdlib.h>  // rand(), srand()
void iteratorBubbleSort(int *ary, int n);
void recursiveBubbleSort(int *ary, int n);
void initArray(int *ary, int n), printArray(int *ary, int n);

int  main()
{
	int numberArray[10], arySize;
	arySize = sizeof(numberArray)/sizeof(numberArray[0]);
	srand((unsigned int) time(NULL));

	initArray(numberArray, arySize);
	iteratorBubbleSort(numberArray, arySize);
	printArray(numberArray, arySize);

	initArray(numberArray, arySize);
	recursiveBubbleSort(numberArray, arySize);
	printArray(numberArray, arySize);
	getchar();
	return 0;
}

void iteratorBubbleSort(int *ary, int n)
{
    int i, j;
    int temp;
    
    for(i=n-1; i > 0; i--){
        for(j=0; j<i; j++){
            if(ary[j] > ary[j+1]){
                temp = ary[j];
                ary[j] = ary[j+1];
                ary[j+1] = temp;
            }
        }
    }
}

void recursiveBubbleSort(int *ary, int n)
{
    int i;
    int temp;
    if(n==1) return;
    for(i=0; i<n-1; i++){
        if(ary[i] > ary[i+1]){
            temp = ary[i];
            ary[i] = ary[i+1];
            ary[i+1] = temp;
        }
    }
    recursiveBubbleSort(ary, n-1);
}
void initArray(int *ary, int n)
{
	int i;
	for(i=0; i<n; ++i)
		ary[i] = rand() % 20 + 1;
}

void printArray(int *ary, int n)
{
	int i;
	printf("배열 내용 : ");
	for(i=0; i<n; ++i)
		printf("%4d", ary[i]);
	printf("\n");
}
