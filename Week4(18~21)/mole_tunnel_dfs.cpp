
#include<stdio.h>
#include<malloc.h>
enum BOOL {FALSE, TRUE};
#define NL printf("\n") /* �� �ٲٱ� ��ũ�� */
#define MAX_SIZE 30		/* map�� ����(row), ����(column)�� �ִ� ũ�� */
int map[MAX_SIZE + 1][MAX_SIZE + 1];  /* �δ��� ���� ���� ����(0��, 0�� ��� ����) */
BOOL dataLoad(const char *fileName);	/* ������ ���Ͽ��� map������ �Է� �޾� map�� �ʱ�ȭ �ϴ� �Լ� */
void initTunnelInfo(); 	/* ���� ������ ������ ����ü �迭 �ʱ�ȭ �Լ� */
void solve(); 			/* �δ��� ���� ����, ũ�⸦ ����ϴ� �Լ�(���ȣ�� ������ dfs()�Լ� �̿�) */
BOOL inRange(int row, int col);	/* row, column ���� ���ռ� �Ǻ� �Լ� */
void dfs(int row, int col, int tNum);	/* row, col�� ���� �δ��� ������ dfs������� ���ȣ���ϸ� �˻��ϴ� �Լ� */
void output();			/* �δ��� �� ���� ��� �Լ� */
void solve_bfs();
void bfs(int row, int col, int tNum);

typedef struct tunnel_info {
	int number;  /* �� ��ȣ */
	int size;    /* �� ũ�� */
}TunnelInfo;

typedef struct rowcol { /* �࿭ ��ǥ 1 ��Ʈ�� �����ϴ� ����ü */
	int row;
	int col;
}RC;

typedef struct _queue {
	RC *queue;
	int size;
	int front, rear;
} Queue;



TunnelInfo tunnelInfo[MAX_SIZE * 2 + 1];    /* �δ��� ���� ũ�� ����(2�� ����� ���) */
int n;  			/* map�� ����(row), ����(column)�� ũ�� ���� ���� */
int tunnelNumber;  /* �δ����� ��ȣ */

BOOL createQueue(Queue* qp, int size)
{
	if(qp == NULL){
		return FALSE;
	}
	qp->queue = (RC *)calloc(size,sizeof(RC));

	if(qp->queue != NULL) {
		qp->size = size;
		qp->front = 0;
		qp->rear = 0;
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

BOOL isQueueEmpty(const Queue *qp)
{
	if (qp == NULL) {  /* qp������ NULL check*/
		return FALSE;
	}

	if (qp->front == qp->rear)	/* queue�� �ֺ�� ������ */
		return TRUE;
	else
		return FALSE;
}
/*--------------------------------------------------------------------------------------
Function name	: isQueueFull - ť�� �����ִ°� �˻�
Parameters		: qp - ť ����ü�� �ּ�
Returns			: ���� ������ TRUE ����, �ƴϸ� FALSE ����
--------------------------------------------------------------------------------------*/
BOOL isQueueFull(const Queue *qp)
{
	if (qp == NULL) {  /* qp������ NULL check*/
		return FALSE;
	}

	if (qp->front == (qp->rear + 1) % qp->size) /* queue�� ������ ��� ������ */
		return TRUE;
	else
		return FALSE;
}
/*--------------------------------------------------------------------------------------
Function name	: enqueue() - ť�� ������ �ϳ��� ������
Parameters		: qp - ť ����ü�� �ּ�
			  	  enqueData - ť�� ������ ������
Returns			: ���������� �����ϸ� TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
BOOL enqueue(Queue * qp, RC enqueData)
{
	if (qp == NULL) {  /* qp������ NULL check*/
		return FALSE;
	}

	if (isQueueFull(qp))	/* queue�� ���������� enqueue �Ұ� */
	{
		return FALSE;
	}

	/* rear ��ġ�� ������ ���� �� rear ���� */
	qp->queue[qp->rear] = enqueData;
	qp->rear = (qp->rear + 1) % qp->size;
	return TRUE;

}
/*--------------------------------------------------------------------------------------
Function name	: dequeue() - ť���� ������ �ϳ��� ����
Parameters		: qp - ť ����ü�� �ּ�
				  dequeData - ���� �����͸� ������ �������� �ּ�
Returns			: ���������� ������ TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
BOOL dequeue(Queue * qp, RC * dequeData)
{
	if (qp == NULL) {  /* qp������ NULL check*/
		return FALSE;
	}

	if (isQueueEmpty(qp))	/* ť�� ��������� dequeue �Ұ� */
	{
		return FALSE;
	}

	/* �����͸� front��ġ���� ���� dequeData�� ����Ű�� ���� ���� �� */
	*dequeData = qp->queue[qp->front];
	qp->front = (qp->front + 1) % qp->size;

	return TRUE;
}
/*--------------------------------------------------------------------------------------
Function name	: printQueue() - ť ���� ��� �����͸� ��� ��
Parameters		: qp - ť ����ü�� �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void printQueue(const Queue * qp)
{
	if (qp == NULL) {  /* qp������ NULL check*/
		return;
	}
	/* queue���� ��� ������ ��� (dequeue �ϸ� ��µǴ� ������ ���) */
	for (int i = qp->front; i != qp->rear; i = (i + 1) % qp->size)
	{
		printf("(%d,%d) ", qp->queue[i].row, qp->queue[i].col);
	}
	printf("\n");
}
/*--------------------------------------------------------------------------------------
Function name	: destroyQueue() - ť �Ҹ� �Լ�
Parameters		: qp - ť ����ü�� �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void destroyQueue(Queue * qp)
{
	if (qp == NULL) {  /* qp������ NULL check*/
		return;
	}

	if (qp->queue != NULL) { /* queue�� ���Ǵ� �迭 �޸� ���� */
		free(qp->queue);
	}
	qp->queue = NULL;	/* queue ����� NULL pointer�� �ʱ�ȭ */
	qp->size = 0;		/* size����� 0���� �ʱ�ȭ */
	qp->front = qp->rear = 0;	/* front, rear ����� 0���� �ʱ�ȭ */
}
/*-------------------------------------------------------------------------------------
Function name 	: main() - �׷����� �����ϰ� DFS Ž���� �ǽ��Ѵ�.
------------------------------------------------------------------------------------*/
int main()
{
	const char *fileName[] = { "d:\\data\\�δ�����1.txt" , "d:\\data\\�δ�����2.txt", "d:\\data\\�δ�����3.txt" };
	size_t i;
	for (i = 0; i < sizeof(fileName) / sizeof(fileName[0]); ++i) {
		tunnelNumber = 2; /* �δ����� ��ȣ(1�� �ͳ��� ������ �ǹ��ϹǷ� 2�� ���� ���) */
		if (dataLoad(fileName[i]) == FALSE) return 0;
		solve_bfs();
		output();
		NL;
		printf("===================================================================\n\n");
		getchar();
	}
	getchar();
	return 0;
}
/*--------------------------------------------------------------------------------------
Function name 	: dataLoad() - ������ ���Ͽ��� �˻��� �����͸� �Է� �޾� map�� �����ϴ� �Լ�
Parameters		: char *fileName - �δ��� ���� ������ ����� ������ ���ϸ�
Returns			: ���� �бⰡ �����ϸ� TRUE ����, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
BOOL dataLoad(const char *fileName)
{
	FILE *fp;

	int i, j; /* iterator */
	fp = fopen(fileName, "rt");
	if (fp == NULL) {
		printf("file open error!!!\n");
		getchar();
		return FALSE;
	}
	if (fscanf(fp, "%d", &n) != 1) return FALSE;
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= n; ++j) {
			if (fscanf(fp, "%d", &map[i][j]) != 1) return FALSE;
		}
	}
	fclose(fp);
	return TRUE;
}
/*--------------------------------------------------------------------------------------
Function name 	: initTunnelInfo() - ���� ������ ������ ����ü �迭 �ʱ�ȭ �Լ�
Parameters		: ����
Returns			: ����
--------------------------------------------------------------------------------------*/
void initTunnelInfo()
{
	int i;
	for (i = 0; i <= MAX_SIZE*2; ++i) {
		tunnelInfo[i].number = i;
		tunnelInfo[i].size = 0;  /* extern���� ����� �迭�� ����̹Ƿ� ���ص� �� */
	}
}
/*--------------------------------------------------------------------------------------
Function name 	: solve() - �δ��� ���� ����, ũ�⸦ ����ϴ� �Լ�(���ȣ�� ������ dfs�� �̿��� Ǯ��)
Parameters		: ����
Parameters		: ����
--------------------------------------------------------------------------------------*/
void solve()
{
	int i, j;
	initTunnelInfo(); /* ���� ������ ������ ����ü �迭 �ʱ�ȭ */
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= n; ++j) {
			if (map[i][j] == 1) {  /* �ͳ��� �߰ߵǸ� */
				dfs(i, j, tunnelNumber);  /* ���� �켱Ž�� ���� */
				++tunnelNumber;  /* �δ��� �� ��ȣ(tunnelNumber)�� ������Ŵ */
			}
		}
	}
	return;
}

void solve_bfs()
{
	int i, j;
	initTunnelInfo(); /* ���� ������ ������ ����ü �迭 �ʱ�ȭ */
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= n; ++j) {
			if (map[i][j] == 1) {  /* �ͳ��� �߰ߵǸ� */
				bfs(i, j, tunnelNumber);  /* �ʺ� �켱Ž�� ���� */
				++tunnelNumber;  /* �δ��� �� ��ȣ(tunnelNumber)�� ������Ŵ */
			}
		}
	}

	return;
}
void bfs(int row, int col, int tNum)
{
	Queue que;
	RC rc,start,tRC;
	RC rcxy[4] ={ {-1,0},{1,0},{0,-1},{0,1}};
	int tY, tX;
	createQueue(&que,MAX_SIZE);
	start.row = row;
	start.col = col;
	enqueue(&que,start);
	while(!isQueueEmpty(&que)) {
		dequeue(&que,&rc);

		for(int i = 0; i< 4; i++) {
			tY = rc.row + rcxy[i].row;
			tX = rc.col + rcxy[i].col;
			if (inRange(tY, tX) && map[tY][tX] == 1) {
						map[tY][tX] = tNum; 		/*  map�� row�� col���� ���� �δ��� �� ��ȣ�� ���� */
						++tunnelInfo[tNum].size;  	/* �δ������� ũ�� ���� */
						  tRC.row = tY;
						  tRC.col = tX;
						  enqueue(&que,tRC);
			}
		}


	}
	destroyQueue(&que);

}
/*--------------------------------------------------------------------------------------
Function name 	: inRange() - row, column�� ���ռ� �Ǻ� �Լ�
Parameters		: int row - �� ��
                  int col - �� ��
Returns			: ������ �����̸� TRUE ����, �������� �����̸� FALSE ����
--------------------------------------------------------------------------------------*/
BOOL inRange(int row, int col)
{
	if((0<row && row<=n) && (0<col && col<=n))
		return TRUE;
	else
		return FALSE;
}
/*--------------------------------------------------------------------------------------
Function name 	: dfs() - row, col�� ���� �δ��� ������ dfs������� ���ȣ���ϸ� �˻��ϴ� �Լ�
Parameters		: int row - �� ��
				  int col - �� ��
                  int tNum - �δ��� �� ��ȣ
Returns			: ����
--------------------------------------------------------------------------------------*/
void dfs(int row, int col, int tNum)
{
	if (inRange(row, col) == FALSE) return;
	if (map[row][col] != 1) return;
	map[row][col] = tNum; 		/*  map�� row�� col���� ���� �δ��� �� ��ȣ�� ���� */
	++tunnelInfo[tNum].size;  	/* �δ������� ũ�� ���� */
	dfs(row - 1, col, tNum);
	dfs(row + 1, col, tNum);
	dfs(row, col - 1, tNum);
	dfs(row, col + 1, tNum);
}
/*--------------------------------------------------------------------------------------
Function name 	: output() - �δ��� �� ���� ����Լ�
Parameters		: ����
Returns			: ����
--------------------------------------------------------------------------------------*/
void output()
{
	int i, j;
	printf("** �δ��� �� ���� : %d��\n", tunnelNumber-2);
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= n; ++j) {
			printf("%3d", map[i][j]);
		}
		NL;
	}
	NL;

	printf("** �δ��� �� ���� ��� **\n");
	for (i = 2; i < tunnelNumber; ++i) {
		printf("size of tunnel %d : %d\n", tunnelInfo[i].number, tunnelInfo[i].size);
	}

}
