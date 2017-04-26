#include <stdio.h>
#define NEWL printf("\n")

const int INF = 1000; // ���Ѵ븦 �ǹ��ϴ� ����ġ
int N;  // ������ ����
int dist[100][100];
void prn();

int main(){
	int M;  // M-���� ����
	FILE *fp;
	if((fp=fopen("d:\\data\\floyd.txt", "rt"))==NULL)
		return 0;
	fscanf(fp, "%d %d", &N, &M);
	// dist �迭 �ʱ�ȭ
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
			dist[i][j] = i==j ? 0 : INF;
	// ���� ���� �Է¹���
	for(int l=0; l<M; l++){
		int a, b, c;

		fscanf(fp, "%d %d %d", &a, &b, &c);
		if(dist[a][b]>c)
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

		printf("#%d��° ������ ó�� �� ",l);
		NEWL;
		prn();
	}
	printf("** ���� ��� ");
	prn();

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
				printf("%3s", "��");
			else
				printf("%3d", dist[i][j]);
		NEWL;
	}
	NEWL;
	printf("    �� : %d������ ����\n\n", INF);
}
