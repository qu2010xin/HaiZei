#include <stdio.h>
#include <math.h>
#include <inttypes.h>
int main()
{
	int sum1=0;
	int sum2=0;
	for(int i=1;i<=100;i++)
	{
		sum1+=i*i;
	}
	sum2=5050*5050-sum1;
	printf("%d\n",sum2);
}