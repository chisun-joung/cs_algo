//============================================================================
// Name        : distanceNode.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdlib.h>
#include <stdio.h>

int f(int,int);
int main() {
	int m,n;
	int res;
	while(1){
		scanf("%d %d",&m, &n);
		if(m == 0) break;
		res = f(m,n);
		printf("output : %d\n",res);
	}
	return 0;
}

int f(int m,int n)
{
	if(m == n){
		printf("co-parents : %d \n",m);
		return 0;
	}
	if( m > n )
		return f(m/2, n) + 1;
	else
		return f(m, n/2) + 1;
}
