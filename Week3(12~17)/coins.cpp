//============================================================================
// Name        : coins.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <time.h>
#include <stdlib.h>
#include<stdio.h>
#include<math.h>
enum BOOL {FALSE, TRUE};
int solve();

int change;
int nCoins;
int kCoins[10];


BOOL dataLoad(FILE *fp)
{


	int i; /* iterator */

	if (fscanf(fp, "%d", &change) != 1) return FALSE;
	if (change == 0) return FALSE;
	if (fscanf(fp, "%d", &nCoins) != 1) return FALSE;
	for (i = 1; i <= nCoins; ++i) {
		if (fscanf(fp, "%d", &kCoins[i]) != 1) return FALSE;
	}

	return TRUE;
}

void printData()
{
	printf(" Change : %d \n", change);
	printf(" number of coins : %d \n", nCoins);
	for(int i = 1; i <=nCoins; i++){
		printf("%d ",kCoins[i]);
	}
	printf("\n");
}


/*-------------------------------------------------------------------------------------
 Function name 	: main()
 ------------------------------------------------------------------------------------*/
int main()
{
	int res;
	int startTime, endTime;

	FILE *fp;
	fp = fopen("d:\\data\\changeCoin.txt", "rt");
		if (fp == NULL) {
			printf("file open error!!!\n");
			getchar();
			return FALSE;
		}
	while(1){
		res = dataLoad(fp );
		if(res == FALSE){
			break;
		}
		printData();
		startTime = clock();
		res=solve();
		endTime = clock();

		printf("동전의 수 : %d개\n", res);
		printf("알고리즘 실행 소요시간 : %d(millisecond)\n", (endTime - startTime));
	}

	fclose(fp);
	getchar(); getchar();
	return 0;
}

int solve()
{
	int count=0;

	for(int i = nCoins; i >= 1 ; i--){
		if(kCoins[i] <= change){
			count += change / kCoins[i];
			change = change % kCoins[i];
		}

	}

	return count;
}

