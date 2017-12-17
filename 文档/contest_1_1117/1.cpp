#include <stdio.h>
#include <math.h>
#include <inttypes.h>
#include <string.h>
#define max_num 1000000

int prime[max_num + 5] = {0};
int d[max_num + 5] = {0};
int min_sum[max_num + 5] = {0};
void init_prime() {
    // TO DO
    for(int i = 2; i <= max_num; i++)
    {
    	if(prime[i] == 0)
    	{
    		prime[++prime[0]] = i;
    		d[i] = i + 1;
    		min_sum[i] = i * i;
    	}
    	for(int j = 1; j <= prime[0]; j++)
    	{
    		if(i * prime[j] > max_num) break;
    		prime[i * prime[j]] = 1;
    		if(i % prime[j] == 0)
    		{
    			d[i*prime[j]] = d[i]/((1-min_sum[i])/(1-prime[j]))*((1-min_sum[i]*prime[j])/(1-prime[j]));
    			min_sum[i * prime[j]] = min_sum[i] * prime[j];
    			break;
    		}
    		else
    		{
    			d[i * prime[j]] = d[i] * d[prime[j]];
    			min_sum[i * prime[j]] = min_sum[prime[j]];
    		}
    	}
    }
    int sum = 0;
    for(int i = 1; i <= max_num; i++)
    {
    	if(sum < d[i]) sum = d[i]; 
    }
    printf("%d\n",sum);
}

int main()
{
     init_prime();	
}