#include <stdio.h>
#include <math.h>
#include <inttypes.h>
#include <string.h>

#define max_num 100000

int num[max_num];

int main()
{
	num[0] = num[1] = 1;
	for(int i = 1; i <= 100; i++)
	{
		for(int j = 1; j <= num[0];j++)
		{
			num[j]*=i;
		}
		for(int j = 1; j <= num[0]; j++)
		{
			if(num[j] < 10) continue;
			num[j+1] += num[j]/10;
			num[j]%=10;
			if(j == num[0]) num[0]++; 
		}
	}
	int sum = 0;
	for(int i = 1; i <= num[0]; i++)
	{
		sum += num[i];
	}
	printf("%d\n",sum );
}