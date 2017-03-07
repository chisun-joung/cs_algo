#include <stdio.h>
#include <string.h>
enum BOOL {FALSE, TRUE};
#define MAX_BSIZE 1000

typedef struct _relativeCoordinate
{
	int y;  /* y 상대 좌표 */
	int x;  /* x 상대 좌표 */
}RCoordinate;

BOOL initBoard(FILE *fp);
BOOL boggleGame(const char *searchWord);
BOOL hasWord(int y, int x, const char * word);
BOOL inRange(int y,int x);

int maxY;   /* y좌표의 최대값 저장 */
int maxX;   /* x좌표의 최대값 저장 */

RCoordinate RCXY[8] = { {-1,-1},{-1,0},{-1,1},{1,-1},{1,0},{1,1},{0,-1},{0,1} }; /* 상대 좌표 목록 배열 */
/* ( 0, 0 )을 기준위치로 볼때의 상대좌표 표기
(-1,-1) ( 0,-1) ( 1,-1)
(-1, 0) ( 0, 0) ( 1, 0)
(-1, 1) ( 0, 1) ( 1, 1)
*/
char board[MAX_BSIZE][MAX_BSIZE+2]; /* NULL문자와 개행문자를 고려해서 column에 +2 */
/*----------------------------------------------------------------------------------------
 함수명 : main()
----------------------------------------------------------------------------------------*/
int main()
{
	FILE *fp;
	int res;  /* 단어 검색 성공 시 1, 실패 시 0 저장 */
	const char *searchWord[] = {"LECTOPIA", "LGE", "ASDVX"};
	int count=0;  /* 게임 횟수 누적변수 */

	fp=fopen("d:\\data\\boggleGame.txt", "rt");
	if(fp==NULL) {
		printf("FILE open error!!\n");
		return 1;
	}

	while(initBoard(fp))
	{
		res = boggleGame(searchWord[count]); /* 보글 게임 함수 호출 */

		if(res == TRUE)  /* 단어를  찾았으면 */
			printf("+ Existence!!(%s)\n", searchWord[count]);
		else   /* 단어를 못찾았으면 */
			printf("- Nonexistence!!(%s)\n", searchWord[count]);
		++count;
		getchar();
	}
	fclose(fp);
	return 0;
}
/*--------------------------------------------------------------------------------------
Function name 	: initBoard() - 파일에서 보글 게임의 board정보를 입력 받아 초기화하는 함수
Parameters		: fp - board정보를 저장하고 있는 파일의 파일 포인터
Returns			: board정보를 정상적으로 초기화 하면 1리턴, 실패하면 0 리턴
--------------------------------------------------------------------------------------*/
BOOL initBoard(FILE *fp)
{
	int i; /* iterator */
	fscanf(fp, "%d %d\n", &maxY, &maxX);  /* 문자의 가로 개수와 세로 개수 읽기 */
	if(maxY==0 || maxX==0) return FALSE;  /* 가로 또는 세로 크기가 0이면 초기화 실패 */

	for(i=0; i< maxY; ++i)
	{
		fgets(board[i], maxX+2, fp); /* 개행문자와 널문자의 크기 고려해서 +2 */
		board[i][maxX]='\0';  /* 함께 읽혀들어온 한 줄 뒤의 개행문자 삭제 */
		puts(board[i]);  /* 읽어들인 배열 출력 */
	}
	return TRUE;  /* board 초기화 성공 */
}
/*--------------------------------------------------------------------------------------
Function name 	: boggleGame() - board에 전달된 문자열이 있는가 검사하는 함수
Parameters		: searchWord - 검색할 단어문자열의 시작주소
Returns			: board에 찾는 문자열이 있으면 TRUE 리턴, 없으면 FALSE 리턴
--------------------------------------------------------------------------------------*/
BOOL boggleGame(const char *searchWord)
{
	int i,j;  /* iterator */
	int res;  /* 단어 검색 성공여부 저장 */
	for(i=0; i<maxY; ++i){
		for(j=0; j<maxX; ++j){
			res = hasWord(i, j, searchWord); /* 배열 전체의 각 방을 단어 검색 시작점으로 설정하여 반복 호출 함 */
			if(res == TRUE)  /* 단어를 찾았으면 바로 TRUE 리턴 */
				return TRUE;
		}
	}
	return FALSE;
}
/*--------------------------------------------------------------------------------------
Function name 	: inRange() - 전달된 y, x 좌표의 유효성 검사 함수
Parameters		: y - 유효성 검사할 y 좌표
             	  x - 유효성 검사할 y 좌표
Returns			: y,x 좌표가 모두 유효하면 TRUE 리턴, 한 좌표라도 유효하지 않으면 FALSE 리턴
--------------------------------------------------------------------------------------*/
BOOL inRange(int y,int x)
{
	// TODO
	return 0;  // 리턴값은 수정하세요.
}
/*--------------------------------------------------------------------------------------
Function name 	: hasWord() - 전달된 y, x 좌표에 찾는 문자가 존재하는가 검사하는 재귀함수
Parameters		: y - 검사할 y 좌표
             	  x - 검사할 x 좌표
			 	  word - 검사할 문자열의 시작주소
Returns			: 해당좌표에 찾는 문자 있으면 TRUE 리턴, 좌표가 유효하지 않거나 찾는 문자 없으면 FALSE 리턴
--------------------------------------------------------------------------------------*/
BOOL hasWord(int y, int x, const char * word)
{
	// TODO
	return 0;  // 리턴값은 수정하세요.
}
