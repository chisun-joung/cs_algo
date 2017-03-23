#include<stdio.h>
int solve(int around);

/*-------------------------------------------------------------------------------------
 Function name 	: main()
 ------------------------------------------------------------------------------------*/
int main()
{
	int around;  /* �ﰢȭ�� �ѷ��� ���� */
	int res;

	while(1){
		printf("�ﰢȭ�� �ѷ��� ���� �Է�(�����Է� �� ����) : ");
		res = scanf("%d", &around);
		if(res == 0){
			break;
		}
		res=solve(around);
		printf("ȭ�� �ѷ� ���� %d�� ȭ�� ������ �� : %d��\n", around, res);
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
