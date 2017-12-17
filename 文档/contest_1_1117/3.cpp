#include <stdio.h>
#include <math.h>
#include <inttypes.h>
#include <string.h>
#define max_num 1000000

int prime[max_num + 5] = {0};
int d[max_num + 5] = {0};
int min_sum[max_num + 5] = {0};
int p_sum[max_num + 5] = {0};
int p_min_sum[max_num + 50] = {0};
void init_prime() {
    // TO DO
    for(int i = 2; i <= max_num; i++)
    {
    	if(prime[i] == 0)
    	{
    		prime[++prime[0]] = i;
    		d[i] = i + 1;
    		min_sum[i] = i * i;

            p_sum[i] = 2;
            p_min_sum[i] = 2;
    	}
    	for(int j = 1; j <= prime[0]; j++)
    	{
    		if(i * prime[j] > max_num) break;
    		prime[i * prime[j]] = 1;
    		if(i % prime[j] == 0)
    		{
    			d[i*prime[j]] = d[i]/((1-min_sum[i])/(1-prime[j]))*((1-min_sum[i]*prime[j])/(1-prime[j]));
    			min_sum[i * prime[j]] = min_sum[i] * prime[j];

                p_sum[i*prime[j]] = p_sum[i] / (1+p_min_sum[i]) * (2+p_min_sum[i]);
                p_min_sum[i*prime[j]] = p_min_sum[i] + 1;
    			break;
    		}
    		else
    		{
    			d[i * prime[j]] = d[i] * d[prime[j]];
    			min_sum[i * prime[j]] = min_sum[prime[j]];

                p_sum[i*prime[j]] = p_sum[i] * p_sum[prime[j]];
                p_min_sum[i*prime[j]] = p_min_sum[prime[j]]; 
    		}
    	}
    }
   /* for(int i = 1; i <= 100; i++)
    {
        printf("%d %d %d\n",i,d[i],p_sum[i]);
    }*/
    int sum = 0;
    int t = 1;
    for(int i = 1; i <= max_num; i++)
    {
    	if(sum < d[i]*p_sum[i]) { sum =d[i]*p_sum[i]; t = i;}
    }
    printf("%d\n",t);
   // printf("%d %d\n",d[16384],p_sum[16384]);*/
}

int main()
{
     init_prime();	
}