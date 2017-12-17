#include <stdio.h>
#include <math.h>
#include <inttypes.h>
#include <string.h>

#define max_num 15
int f[max_num+2][max_num+2];

	int max(int x,int y)
	{
		return x > y ? x : y;
	}

int main()
{
	for(int i = 0; i < max_num; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			scanf("%d",&f[i][j]);
		}
	}
	for(int i = max_num - 2; i >= 0; i--)
	{
		for(int j = 0; j <= i; j++)
		{
			f[i][j] += max(f[i+1][j],f[i+1][j+1]);
		}
	}
	printf("%d\n", f[0][0]);
}