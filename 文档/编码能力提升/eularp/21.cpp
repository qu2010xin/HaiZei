#include <stdio.h>
#include <string.h>
#include <math.h>

#include <inttypes.h>
#define max_num 10000 
int64_t prime[max_num] = { 0 };
int64_t num[max_num] = { 0 };
int64_t sum_min[max_num] = { 0 };
int primes()
{
    for(int64_t i = 2; i <= max_num; i++)
    {
        if(!prime[i])
        {
            prime[++prime[0]] = i;
            num[i] = 1 + i;
            sum_min[i] = i * i;
        }
        for(int64_t j = 1; j <= prime[0]; j++)
        {
            if(prime[j] * i > max_num) break;
            prime[i*prime[j]] = 1;
            if(i%prime[j]==0)
            {
                //sum_min
                num[i * prime[j]] = num[i] / ((1-sum_min[i])/(1-prime[j])) * ((1-sum_min[i]*prime[j])/(1-prime[j]));
                sum_min[i * prime[j]] = sum_min[i]*prime[j];
                break;
            }
            else
            {
                num[i * prime[j]] = num[i] * num[prime[j]];
                sum_min[i * prime[j]] = sum_min[prime[j]];
            }
        }
    }
 /*   for(int i = 2; i <= 100; i++)
    {
        printf("%5d:%8"PRId64,i,num[i]);
        if(i%3==0)
        {
            printf("\n");
        }
    }*/
}


int main()
{
    primes();
    int sum = 0;
    for(int i = 1; i <= max_num; i++)
    {
        for(int j = i+1 ; j <= max_num; j++)
        {
            if(num[j]-j==i&&num[i]-i == j)
            {
                sum+=i;
                if(i!=j)
                {
                    sum+=j;
                }
                printf("%5d %5d\n",i,j);
                
            }
        }
    }
    printf("%d\n",sum);
   
}
