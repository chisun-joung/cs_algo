#include<stdio.h>
#include <stdlib.h>

void f(int n);

int main() {
	int n;
	while(1){
		scanf("%d",&n);
		if(n==0) break;
		f(n);
	}

	getchar();
	return 0;
}


void f(int n)
{
	if (n == 1){
		printf("*\n");
		return;
	}
	else{
		f(n-1);
		for(int i=0; i < n; i++){
			printf("*");
		}
		printf("\n");
	}
}
