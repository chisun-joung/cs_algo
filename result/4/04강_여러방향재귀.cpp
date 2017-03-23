#include<stdio.h>

int cnt;
void f(int n);

int main()
{
	int  num = 10 ;
	f(num);
	printf("%d\n" , cnt) ;
	getchar();
	return 0;
}
void f(int n)
{
	if(n<=1)
		cnt++;	/* n<=1 이면 cnt 1증가 */
	else
	{
		f(n/2);	/* n을 2로 나눈 몫으로 재귀호출 */
		f(n/2);	/* n을 2로 나눈 몫으로 재귀호출 */
	}
    return;
}
