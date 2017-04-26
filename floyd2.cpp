#include <stdio.h>
#define NEWL printf("\n")

const int INF = 1000; // 무한대를 의미하는 가중치
int N;  // 정점의 개수
int dist[100][100];
void prn();

int main(){
	FILE *fp;
	if((fp=fopen("d:\\data\\floyd2.txt", "rt"))==NULL)
		return 0;
	while(1){
		fscanf(fp, "%d", &N);
		// dist 배열 초기화
		if(N == 0) break;
		for(int i=1; i<=N; i++)
			for(int j=1; j<=N; j++)
				dist[i][j] = i==j ? INF : INF;
		// 간선 정보 입력받음
		for(int a=1; a<=N; a++){
			for(int b=1; b<=N; b++) {
				int c;
				fscanf(fp, " %d", &c);
				if(dist[a][b]>c && c!=0)
					dist[a][b] = c;
				else  // dist배열의 값이 변경이 없다면 플로이드 알고리즘을 수행할 필요가 없음
					continue;

				// 플로이드 알고리즘 적용
				//for(int k=1; k<=N; k++)
				for(int i=1; i<=N; i++)
					for(int j=1; j<=N; j++)
						for(int k=1; k<=N; k++)
							if(dist[i][j] > dist[i][k]+dist[k][j])
								dist[i][j] =  dist[i][k]+dist[k][j];


				NEWL;
				prn();
			}

		}
		printf("** 최종 결과 ");
		prn();
		getchar();
	}


	fclose(fp);
	getchar();
	return 0;
}

void prn()
{
	int i,j;         /* iterator */
	NEWL;
	printf("   ");
	/* 정점명 가로방향 출력 */
	for(i=1; i<=N; ++i)
		printf("%3d", i);

	NEWL;

	for(i=1; i<=N; ++i)
	{
		printf("%3d", i);
		for(j=1; j<=N; j++)
			if(dist[i][j]==INF)
				printf("%3s", "x");
			else
				printf("%3d", dist[i][j]? 1: 0);
		NEWL;
	}
	NEWL;

}
