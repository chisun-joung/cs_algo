#include <time.h>
#include <stdlib.h>
#include<stdio.h>
#include<math.h>

int solve(int around);
int end_temp;
/*-------------------------------------------------------------------------------------
 Function name 	: main()
 ------------------------------------------------------------------------------------*/
int main()
{
	int around;  /* 삼각화단 둘레의 길이 */
	int res;
	int startTime, endTime;

	srand((unsigned int)time(NULL));
	while(1){
		printf("삼각화단 둘레의 길이 입력(문자입력 시 종료) : ");
		res = scanf("%d", &around);
		if(res == 0){
			break;
		}
		end_temp = round(around/2.0)-1;
		startTime = clock();
		res=solve(around);
		endTime = clock();

		printf("화단 둘레 길이 %d인 화단 종류의 수 : %d개\n", around, res);
		printf("알고리즘 실행 소요시간 : %d(millisecond)\n", (endTime - startTime));
	}

	getchar(); getchar();
	return 0;
}

/*---------------------------------------------------------------------
 Function name 	: solve() - 화단 둘레에 맞는 경우를 출력하고 경우의 수를 리턴
 Parameters		: around - 화단 둘레의 길이
 Returns		: 둘레 길이에 맞게 만들 수 있는 서로 다른 화단의 수
 --------------------------------------------------------------------*/
int solve(int around)
{
	int a,b,c;  	/* 삼각화단의 세변의 길이 저장 변수 */
	int count=0;	/* 둘레가 around값이 경우의 수 */



	for(a=1; a<=end_temp; ++a)
		for(b=a; b<=end_temp; ++b)
		{
			c = around - (a + b);
			if(c < b) break;
			if(a+b+c==around && a+b > c){
					++count;
			}
		}

	return count;
}
