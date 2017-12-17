#include <stdio.h>
#include <math.h>
#include <inttypes.h>
#include <string.h>
#define max_num 1000000
int number[max_num + 5] = {0};
int sum[max_num + 5] = {0};
int f(int k)
{
	number[0] = number[1] = 1;
	for(int i = 2; i <= k; i++)
	{
		for(int j = 1; j <= number[0]; j++)
		{
			number[j] *= i;
		}
		for(int j = 1; j <= number[0]; j++)
		{
			if(number[j] < 10) continue;
			number[j+1] += number[j]/10;
			number[j] %= 10;
			if(j == number[0]) number[0]++;
		}
	}
	sum[0] = sum[1] = 1;
	for(int i = 1; i <= number[0]; i++)
	{
		if(number[i] == 0)  continue;
		for(int j = 1; j <= sum[0]; j++)
		{
			sum[j] *= number[i];
		}
		for(int j = 1; j <= sum[0]; j++)
		{
			if(sum[j] < 10) continue;
			sum[j + 1] += sum[j]/10;
			sum[j]%=10;
			if(j== sum[0]) sum[0]++;
		}
	}


	/*for(int i = number[0]; i >= 1; i--)
	{
		printf("%d",number[i]);
	}
	printf("\n");*/
	for(int i = sum[0]; i >= 1; i--)
	{
		printf("%d",sum[i]);
	}
	printf("\n");
}

int main()
{
	f(100);
}