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

int solve(int n);
BOOL isPrime(int num);
int main() {

	int n;
	int res;
	int startTime, endTime;
	while(1){
		printf("���° �Ҽ�?: ");
		scanf("%d",&n);
		if(n==0)break;
		startTime = clock();
		res = solve(n);
		endTime = clock();
		printf("�Ҽ� : %d\n", res);
		printf("�˰��� ���� �ҿ�ð� : %d(millisecond)\n", (endTime - startTime));
	}
	getchar();getchar();
	return 0;

}


int solve(int n){
	int num=2;
	int count = 0;
	while(1){
		if(isPrime(num)){
			if(++count == n) break;
		}
		num++;
	}
	return num;
}

BOOL isPrime(int num){

	for(int i = 2; i*i <= num ; i++){
		if(num % i == 0) return FALSE;
	}
	return TRUE;
}
