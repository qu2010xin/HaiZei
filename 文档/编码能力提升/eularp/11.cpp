#include <stdio.h>
#include <math.h>
#include <inttypes.h>
#include <string.h>

#define min_num 5
#define max_num 24

int number[40][40];
int pos[4][2] = { 0,1,1,1,1,0,1,-1};

int main()
{
	freopen("./input","r",stdin);
	
	memset(number,0,sizeof(number));
	for(int i = min_num; i <= max_num; i++)
	{
		for(int j = min_num; j <= max_num; j++)
		{
			scanf("%d",number[i]+j);
		}
	}
	long long sum = 0;
	for(int i = min_num; i <= max_num; i++)
	{
		for(int j = min_num; j <= max_num; j++)
		{
			//printf("%d", number[i][j]);
			
			for(int t = 0; t < 4; t++)
			{
				long long temp = 1;
				for(int q = 0; q < 4; q++)
				{
					temp *= number[i+pos[t][0]*q][j+pos[t][1]*q];
				}
				(sum < temp) && (sum = temp);
			}
			 
		}
		//printf("\n");  21447
	}
	printf("%lld\n", sum);
}