#include <stdio.h>
#define MAX_CONTROL 40	/* 온도가 0~40도 이므로 최대 조작횟수가 40을 초과하지 않음 */
int currentTemperature; /* 현재온도 */
int settingTemperature; /* 설정온도 */
int minControl; /* 최소 리모컨 조절 횟수 */

void solve(int temp, int cnt);
/*-------------------------------------------------------------------------------------
 Function name 	: main()
 ------------------------------------------------------------------------------------*/
int main()
{
	while (1) {
		minControl = MAX_CONTROL;
		printf("# 현재온도 설정온도 입력(문자입력 시 종료) : ");
		if (scanf("%d %d", &currentTemperature, &settingTemperature) != 2)
			break;
		solve(currentTemperature, 0);
		printf("리모컨 최소 조작 횟수 : %d회\n", minControl);
	}
	getchar(); 	getchar(); getchar();

	return 0;
}
/*---------------------------------------------------------------------
 Function name 	: solve() - 온도 조절을 위해 리모컨을 조작 해야 할 횟수 계산
 Parameters		: temperature - 현재 온도
 	 	 	 	  cnt - 현재까지의 리모컨 조작 횟수
 Returns		: 없음
 --------------------------------------------------------------------*/
void solve(int temperature, int cnt)
{
	// TODO
	return;
}
