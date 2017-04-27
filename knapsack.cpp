#include <stdio.h>
#define MAX_CNT 100
int weight[MAX_CNT+1];  // ������ ���Ը� �����ϴ� �迭(0���� ��� ����)
int value[MAX_CNT+1];   // ���Ǻ� ��ġ�� �����ϴ� �迭 (0���� ��� ����)
int n;                  // ������ ���� ���庯��
int maxWeight;          // �賶�� ���� ������ �ִ� ���� ���� ����
void fileLoad(const char * fileName);
int knapsack(int i, int r);
int DT[MAX_CNT+2][MAX_CNT+2];

int main()
{
	fileLoad("d:\\data\\knapsack3.txt");
	for(int i=0; i<=MAX_CNT; i++){
		for(int j=0; j<=MAX_CNT; ++j){
			DT[i][j] = -1;
		}
	}
	printf("�ִ� ��ġ : %d\n\n", knapsack(1,maxWeight));
	getchar();
	return 0;
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: fineLoad() - ���Ͽ��� ������ ����(����, ��ġ)�� �Է� �޾� �ʱ�ȭ�ϴ� �Լ�
�������� : fileName - ������ ������ �����ϰ� �ִ� ���ϸ�
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void fileLoad(const char * fileName)
{
	FILE *fp;
	int i; /* iterator */
	fp=fopen(fileName, "rt");
	if(fp == NULL)
		return;

	fscanf(fp, "%d %d\n", &n, &maxWeight);  /* ������ ������ �賶�� ���尡���� �ִ빫�� �Է� */

	for(i=1; i<=n; ++i)
	{
		fscanf(fp, "%d %d\n", &weight[i], &value[i]); /* ������ ���Կ� ��ġ �Է� */
	}
	fclose(fp);
	return;
}
/*------------------------------------------------------------------
�Լ��� �� ���: knapsack() - �ش��ϴ� ��ȣ�� ������ ���� ���� ���� ���� ��� �� �� ū ��ġ�� �����ϴ� ����Լ�
�������� : i - ������ ��ȣ
        r - ���� ����
���ϰ�: �ش繰���� ���� ����� ��ġ�� ���� ���� ����� ��ġ �� ū ��
------------------------------------------------------------------*/
int knapsack(int i, int r)
{
	int res1, res2;
	if(DT[i][r]!=-1) return DT[i][r];
	if(i == n+1)  // ������ ������ �ʰ� ������
		return DT[i][r] = 0;
	else if(r<weight[i])  // ���� ���԰�  ���� ������ ���Ժ��� ������ ���� ������ ���� �� �ִ��� Ȯ���Ϸ� ��
		return DT[i][r] = knapsack(i+1,r);
	else   // ���� ����(itemNum)�� ���� ���� ���� �ִ� ��츦 ȣ�� ��
	{
		res1 = knapsack(i+1, r);
		res2 = knapsack(i+1, r-weight[i])+value[i];
		return DT[i][r] = (res1>res2)?res1:res2; // ���� ������ ���� ���� ���� �ִ� ��� �� ��ġ�� �� ū ��츦 ���� ��
	}
}
