#include <stdio.h>
#define NEWL printf("\n")

const int INF = 1000; // ���Ѵ븦 �ǹ��ϴ� ����ġ
int N;  // ������ ����
int dist[100][100];
void prn();

int main(){
	FILE *fp;
	if((fp=fopen("d:\\data\\floyd2.txt", "rt"))==NULL)
		return 0;
	while(1){
		fscanf(fp, "%d", &N);
		// dist �迭 �ʱ�ȭ
		if(N == 0) break;
		for(int i=1; i<=N; i++)
			for(int j=1; j<=N; j++)
				dist[i][j] = i==j ? INF : INF;
		// ���� ���� �Է¹���
		for(int a=1; a<=N; a++){
			for(int b=1; b<=N; b++) {
				int c;
				fscanf(fp, " %d", &c);
				if(dist[a][b]>c && c!=0)
					dist[a][b] = c;
				else  // dist�迭�� ���� ������ ���ٸ� �÷��̵� �˰����� ������ �ʿ䰡 ����
					continue;

				// �÷��̵� �˰��� ����
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
		printf("** ���� ��� ");
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
	/* ������ ���ι��� ��� */
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
