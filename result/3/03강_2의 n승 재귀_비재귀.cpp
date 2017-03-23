#include<stdio.h>
int iteratorPowerOf2(int power);
int recursivePowerOf2(int power);
int  main()
{
	int power = 10;
	printf("2의 %d승의 값 =  %d\n" , power, iteratorPowerOf2(power) ) ;

	printf("2의 %d승의 값 =  %d\n" , power, recursivePowerOf2(power) ) ;

	getchar();
	return 0;
}

int iteratorPowerOf2(int power)
{

    int i,result=1;
    for(i = 0; i < power; i++){
        result = result * 2;
    }
	return result;
}

int recursivePowerOf2(int power)
{
    if(power < 1) return 1;
    return 2 * recursivePowerOf2(power-1);
}
