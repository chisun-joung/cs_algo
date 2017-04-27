#include <stdio.h>
#define MAX_CNT 100
int weight[MAX_CNT+1];  // 물건의 무게를 저장하는 배열(0번방 사용 안함)
int value[MAX_CNT+1];   // 물건별 가치를 저장하는 배열 (0번방 사용 안함)
int n;                  // 물건의 개수 저장변수
int maxWeight;          // 배낭에 저장 가능한 최대 무게 저장 변수
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
	printf("최대 가치 : %d\n\n", knapsack(1,maxWeight));
	getchar();
	return 0;
}
/*--------------------------------------------------------------------------------------
함수명 및 기능: fineLoad() - 파일에서 물건의 정보(무게, 가치)를 입력 받아 초기화하는 함수
전달인자 : fileName - 물건의 정보를 저장하고 있는 파일명
리턴값: 없음
--------------------------------------------------------------------------------------*/
void fileLoad(const char * fileName)
{
	FILE *fp;
	int i; /* iterator */
	fp=fopen(fileName, "rt");
	if(fp == NULL)
		return;

	fscanf(fp, "%d %d\n", &n, &maxWeight);  /* 물건의 개수와 배낭에 저장가능한 최대무게 입력 */

	for(i=1; i<=n; ++i)
	{
		fscanf(fp, "%d %d\n", &weight[i], &value[i]); /* 물건의 무게와 가치 입력 */
	}
	fclose(fp);
	return;
}
/*------------------------------------------------------------------
함수명 및 기능: knapsack() - 해당하는 번호의 물건을 넣을 경우와 넣지 않을 경우 중 더 큰 가치를 리턴하는 재귀함수
전달인자 : i - 물건의 번호
        r - 남은 무게
리턴값: 해당물건을 넣은 경우의 가치와 넣지 않은 경우의 가치 중 큰 값
------------------------------------------------------------------*/
int knapsack(int i, int r)
{
	int res1, res2;
	if(DT[i][r]!=-1) return DT[i][r];
	if(i == n+1)  // 물건의 개수를 초과 했으면
		return DT[i][r] = 0;
	else if(r<weight[i])  // 남은 무게가  현재 물건의 무게보다 작으면 다음 물건을 넣을 수 있는지 확인하러 감
		return DT[i][r] = knapsack(i+1,r);
	else   // 현재 물건(itemNum)을 넣지 않은 경우와 넣는 경우를 호출 함
	{
		res1 = knapsack(i+1, r);
		res2 = knapsack(i+1, r-weight[i])+value[i];
		return DT[i][r] = (res1>res2)?res1:res2; // 현재 물건을 넣지 않은 경우와 넣는 경우 중 가치가 더 큰 경우를 리턴 함
	}
}
