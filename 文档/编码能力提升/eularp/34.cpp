

#include <stdio.h>
#include <math.h>
#include <inttypes.h>
#define max_num (362880*7)

int jc(int x)
{
	if(x==0)
	{
		return 1;
	}
	int i=1;
	while(x>0)
	{
		i*=x;
		x--;
	}
	return i;
}

int is_valid(int x)
{
	int i=0;
	int y=x;
	while(x>0)
	{
		i+=jc(x%10);
		x/=10;
	}
	if(y==i)
	{
		return 1;
	}
	return 0;
}

int main()
{
	int sum=0;
	for(int i=10;i<=(362880*7);i++)
	{
		if(is_valid(i))
		{
			sum+=i;
			printf("%d\n",i);
		}
	}
	printf("%d\n",sum);
}