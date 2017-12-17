#ifndef PROBLE16
#define PROBLE16
#include <string.h>
int sz[2005];
int test_eular16(int x)
{
	if(x < 0) return 0; 
	int sum = 0;
	memset(sz, 0, sizeof(sz));
	sz[0] = sz[1] = 1;
	for(int i = 1; i <= x; i++)
	{
		for(int j = 1; j <= sz[0]; j++)
		{
			sz[j] *= 2;
		}
		for(int j = 1; j <= sz[0]; j++)
		{
			if(sz[j] < 10) continue;
			sz[j + 1] += sz[j]/10;
			sz[j] %= 10;
			if(j == sz[0]) sz[0]++;
			if(sz[0] > 2000) return 0;
		}
	}
	for(int i = 1; i <= sz[0]; i++)
	{
		sum += sz[i];
	}
	return	sum;
}

#endif
