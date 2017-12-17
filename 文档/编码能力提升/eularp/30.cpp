/**
 *  上界
 */

#include <stdio.h>
#include <math.h>
#include <inttypes.h>

#define MAX_NUM 354294

int is_valid(int x)
{
	int y=x;
	int sum=0;
	while(x>0)
	{
		int i=x%10;
		sum+=i*i*i*i*i;
		x/=10;
	}
	if(sum==y)
	{
		return 1;
	}
	return 0;
}

int main()
{
	int sum=0;
	for(int i=2;i<MAX_NUM;i++)
	{
		if(is_valid(i))
		{
			sum+=i;
		}
	}
	printf("%d\n",sum);
}