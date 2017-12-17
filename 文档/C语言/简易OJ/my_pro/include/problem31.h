#ifndef PROBLE31
#define PROBLE31

#include <math.h>
#include <inttypes.h>

int w(int k)
{
	int arry[8] = {1,2,5,10,20,50,100,200};
	return arry[k-1];
}

int test_eular31(int x)
{
	int sz[2005];
	if(x < 0||x >= 2000) return 0;
	for(int i = 0; i <= 2000; i++)
	{
		sz[i] = 1;
	}
	for(int i = 2; i <= 8; i++)
	{
		for(int j = 1; j <= x; j++)
		{
			if(j >= w(i))
			{
				if(sz[j] >= INT32_MAX - sz[j - w(i)]) return 0;
				sz[j] += sz[j - w(i)];
			}
		}
	}
	return sz[x];
}

#endif
