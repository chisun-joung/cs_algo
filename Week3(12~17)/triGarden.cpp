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
	int around;  /* �ﰢȭ�� �ѷ��� ���� */
	int res;
	int startTime, endTime;

	srand((unsigned int)time(NULL));
	while(1){
		printf("�ﰢȭ�� �ѷ��� ���� �Է�(�����Է� �� ����) : ");
		res = scanf("%d", &around);
		if(res == 0){
			break;
		}
		end_temp = round(around/2.0)-1;
		startTime = clock();
		res=solve(around);
		endTime = clock();

		printf("ȭ�� �ѷ� ���� %d�� ȭ�� ������ �� : %d��\n", around, res);
		printf("�˰��� ���� �ҿ�ð� : %d(millisecond)\n", (endTime - startTime));
	}

	getchar(); getchar();
	return 0;
}

/*---------------------------------------------------------------------
 Function name 	: solve() - ȭ�� �ѷ��� �´� ��츦 ����ϰ� ����� ���� ����
 Parameters		: around - ȭ�� �ѷ��� ����
 Returns		: �ѷ� ���̿� �°� ���� �� �ִ� ���� �ٸ� ȭ���� ��
 --------------------------------------------------------------------*/
int solve(int around)
{
	int a,b,c;  	/* �ﰢȭ���� ������ ���� ���� ���� */
	int count=0;	/* �ѷ��� around���� ����� �� */



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
