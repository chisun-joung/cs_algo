//============================================================================
// Name        : primenumber2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//============================================================================
// Name        : primenumber.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <time.h>
#include <stdlib.h>
#include<stdio.h>
enum BOOL {FALSE, TRUE};

int solve();
BOOL isPrime(int num);
void initPrime();
void insertPrime(int n);
void quickSort(int *ary, int size);
void printPrime(void);
int numDigit;
char digit[100];
int prime[1000];
int numPrime;

/* Function to swap values at two pointers */
void swap (char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permute(char *a, int i, int n)
{
   int j;
   if (i == n){
       if(isPrime(atoi(a)))
    		   insertPrime(atoi(a));
   }
   else
   {
        for (j = i; j <= n; j++)
       {
          swap((a+i), (a+j));
          permute(a, i+1, n);
          swap((a+i), (a+j)); //backtrack
       }
   }
}

void initPrime(){
	for(int i=0;i<1000;i++){
		prime[i] = 0;
	}
	numPrime=0;
}

void insertPrime(int n){
	for(int i = 0; i< numPrime;i++){
		if(prime[i] == n) return;
	}
	prime[numPrime++] = n;
}

void printPrime(void){
	for(int i = 0 ; i< numPrime; i++){
		printf("%d  ",prime[i]);
	}
	printf("\n");
}

void quickSort(int *ary, int size)
{
	int pivot, temp;
	int i, j;

	if(size<=1) return; // 구간값이 1이하이면 sort가 완료된 것 이므로 return

	pivot = ary[size-1];

    i = -1;
    j = size-1;

    while(1){
        while(ary[++i]<pivot);
        while(--j>=0 && ary[j]>pivot);
        if(i>=j)
            break;
        temp = ary[i];
        ary[i] = ary[j];
        ary[j] = temp;
    }
    temp = ary[i];
    ary[i] = ary[size-1];
    ary[size-1] = temp;

    quickSort(ary,i);
    quickSort(ary+i+1, size-i-1);
}

int main() {

	int res;
	int startTime, endTime;
	while(1){
		numDigit=0;
		initPrime();
		printf("숫자를 입력하시라 : ");
		gets(digit);
		if(digit[0]=='0')break;
		while(digit[numDigit]!='\0'){
				printf("%c ",digit[numDigit++]);
		}
		printf("\n");
		startTime = clock();
		res = solve();
		endTime = clock();
		printPrime();
		printf("소수갯수 %d\n",res);
		printf("알고리즘 실행 소요시간 : %d(millisecond)\n", (endTime - startTime));
	}
	getchar();getchar();
	return 0;

}


int solve()
{
	permute(digit,0,numDigit-1);
	quickSort(prime,numPrime);
	return numPrime;
}


BOOL isPrime(int num){

	for(int i = 2; i*i <= num ; i++){
		if(num % i == 0) return FALSE;
	}
	return TRUE;
}
