#include <stdio.h>
#include <math.h>
#include <inttypes.h>
#include <string.h>

int mem[1000005];
long long actlen(long long x)
{
	if(x < 1000000)
	{
		if(mem[x] != -1)
		{
			return mem[x];
		}
		if(x == 1) return mem[x]=1;
	    if(x%2 == 0) return mem[x]=actlen(x/2)+1;
	}
	if(x%2 == 0) return actlen(x/2)+1;
	return actlen(x*3+1)+1;
	//return====
}

int main()
{
	long long lenth = 0;
	long long number = 0;
	memset(mem,-1,sizeof(mem));
	for(long long i = 1; i < 1000000; i++)
	{
		long long temp = actlen(i);
		if(lenth < temp)
		{
			lenth = temp;
			number = i;
		}
	}
	printf("%lld\n", number);
}




















