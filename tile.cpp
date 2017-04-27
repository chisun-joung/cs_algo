//============================================================================
// Name        : tile.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <stdio.h>
#include <stdlib.h>
int f(int n);
int main() {
	int n, m;
	int res;
	while(1){
		scanf("%d %d",&n,&m);
		if(n == 0) break;
		res = f(n);
		printf("output :%d  , %d \n", res%m, res);
	}

	getchar();
	return 0;
}

int f(int n)
{
	if(n <=1)
	{
		return 1;
	}
	return f(n-1) + 2 * f(n-2);
}
