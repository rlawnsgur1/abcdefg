#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	srand(time(NULL));
	int num1, num2, num3;
	
	num1 = rand() % 10;
	do{ num2 = rand() % 10; }while(num2 == num1);
	do{ num3 = rand() % 10; }while(num3 == num2 || num3 == num1);
	
	int cnt = 0;
	int strike, ball;
	printf("You can try 7 times. Go for it.")
	do
	{
		if(cnt >= 7) break;
		strike = 0, ball = 0;
		
		int input;
		scanf("%d", &input);
		
		if(input >= 1000 || input < 100)
		{
			printf("input 3-digit numbers\n");
			continue;
		}
		
		int d1, d2, d3;
		d1 = input / 100;
		d2 = (input % 100) / 10;
		d3 = input % 10;
		cnt++;
		if(d1 == d2 || d2 == d3 || d3 == d1)
		{
			printf("%d count : number overlap\n", cnt);
			continue;
		}
		
		if(num1 == d1) strike++;
		else if(num1 == d2 || num1 == d3) ball++;
		if(num2 == d2) strike++;
		else if(num2 == d1 || num2 == d3) ball++;
		if(num3 == d3) strike++;
		else if(num3 == d1 || num3 == d2) ball++;
		
		printf("%d count : %d Strike, %d Ball\n", cnt, strike, ball);
	}while(strike != 3);
	
	if(cnt >= 7)
		printf("Fail! Answer Number : %d%d%d", num1, num2, num3);
	else
		printf("SUCCESS! Try count : %d", cnt);
		
	return 0;
}
