#include <stdio.h>
#include <time.h>
void getSum1(int n);
void getSum2(int n);
int main(){
	int n;			/* 누적할 수 저장 */
	int startTime, endTime;
	printf("# 누적할 데이터의 개수를 입력하시오(100000000(1억)~1000000000(10억)) : ");
	scanf("%d", &n);		/* 누적할 수 입력 */
	startTime = clock();
	getSum1(n);
	endTime = clock();
	printf("getSum1()함수 알고리즘 실행 소요시간 : %d(millisecond)\n", (endTime-startTime));

	startTime = clock();
	getSum2(n);
	endTime = clock();
	printf("getSum2()함수 알고리즘 실행 소요시간 : %d(millisecond)\n", (endTime-startTime));

	getchar();  getchar();
	return 0;
}
void getSum1(int n){
	long long res=0;
	for(int i=1; i<=n; i++)
		res += i;
	printf("1~%d까지의 합 : %lld\n", n, res);
	return;
}
void getSum2(int n){
	printf("1~%d까지의 합 : %lld\n", n, (long long)n*(n+1)/2 );
	return;
}
