#include <stdio.h>
#include <math.h>
#include <inttypes.h>
#include <string.h>
#define max_num 100
int jc[10];
int sz[10] = {0,1,2,3,4,5,6,7,8,9};
int init()
{
	jc[1] = 1; 
	for(int i = 2; i <= 9; i++)
	{
		jc[i] = jc[i - 1]*i;
	}
	/*for(int i = 1; i <= 9; i++)
	{
		printf("%d ",jc[i]);
	}*/
}

int change(int x,int y)
{
	int temp = sz[y + x];
	for(int i = x + y ; i > x; i--)
	{
		sz[i] = sz[i-1];
	}
	sz[x] = temp;
}

void doo(int t,int x)
{
	for(int i = 1; i <= t-1; i++)
	{
		
		int temp = x / jc[t - i];
		if(temp == 0) continue;
		x %= jc[t - i];
		change(i,temp);
	}
}

int main()
{
	init();
	doo(9,9972);
	for(int i = 1; i <= 9; i++)
	{
		printf(" %d",sz[i]);
	}
	printf("\n");

}
