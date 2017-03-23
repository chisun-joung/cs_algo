#include<stdio.h>
int solve(int around);

/*-------------------------------------------------------------------------------------
 Function name 	: main()
 ------------------------------------------------------------------------------------*/
int main()
{
	int around;  /* 삼각화단 둘레의 길이 */
	int res;

	while(1){
		printf("삼각화단 둘레의 길이 입력(문자입력 시 종료) : ");
		res = scanf("%d", &around);
		if(res == 0){
			break;
		}
		res=solve(around);
		printf("화단 둘레 길이 %d인 화단 종류의 수 : %d개\n", around, res);
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
	int a,b,c;
	int count = 0;

	for(a=1;a<=around;a++)
        for(b=a;b<=around;b++)
            for(c=b;c<=around;c++) {
                if(a+b+c==around && a+b > c){
                    count++;
                    printf("(%d %d %d) ",a,b,c);
                }
            }
    printf("\n");
	return count;
}
