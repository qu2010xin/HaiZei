#include <stdio.h>
#include <math.h>
#include <inttypes.h>
#define max_num 100



int main()
{
	int prime[max_num+5]={0};
	
	for(int i = 2; i  <= max_num; i++)
	{
		if(!prime[i]) 
		{
			
			prime[++prime[0]] = i;
		}
		
		for(int j = 1 ; j <= prime[0] && prime[j]*i <= max_num; j++)
		{
			prime[prime[j]*i] = 1;
			if(i%prime[j] == 0) break;

		}		
		
	}
	for(int i = 1; i <= prime[0]; i++)
	{
		printf("%d\n",prime[i]);
	}
	

}