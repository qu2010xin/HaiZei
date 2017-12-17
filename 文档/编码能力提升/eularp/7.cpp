#include <stdio.h>
#include <math.h>
#include <inttypes.h>

#define max_num 100000
int64_t prime[max_num] = { 0 };
int64_t num[max_num] = { 0 };
int64_t sum_min[max_num] = { 0 };


int main()
{
	/*int prime[max_num+5]={0};
	int ss[max_num]={0};
	for(int i = 2; i * i <= max_num; i++)
	{
		if(!prime[i])
		{
			for(int j = i * i ; j <= max_num; j += i)
			{
				prime[j]=1;
			}
		}
	}
	for(int i = 1; i < max_num; i++)
	{
		(prime[i]==0) && (ss[++ss[0]] = i);
		 
	}*/
	int i = 0;
	while(prime[0]	<10005)
	{
		i++;
		if(!prime[i])
        {
            prime[++prime[0]] = i;
            
        }
        for(int64_t j = 1; j <= prime[0]; j++)
        {
            if(prime[j] * i > max_num) break;
            prime[i*prime[j]] = 1;
            if(i%prime[j]==0)
            {
                
                break;
            }
            
        }
	}
	printf("%"PRId64,prime[1000]);
}