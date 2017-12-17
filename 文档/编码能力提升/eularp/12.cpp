#include <stdio.h>
#include <string.h>
#include <math.h>
#include <inttypes.h>
#define max_num 100000
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
            num[i] = 2;
            sum_min[i] = 1;
        }
        for(int64_t j = 1; j <= prime[0]; j++)
        {
            if(prime[j] * i > max_num) break;
            prime[i*prime[j]] = 1;
            if(i%prime[j]==0)
            {
                num[i * prime[j]] = num[i] / (sum_min[i] + 1) * (sum_min[i] + 2);
                sum_min[i * prime[j]] = sum_min[i] + 1;
                break;
            }
            else
            {
                num[i * prime[j]] = num[i] * num[prime[j]];
                sum_min[i * prime[j]] = sum_min[prime[j]];
            }
        }
    }
    /*for(int i = 2; i <= 1000; i++)
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
    int64_t i=1;
    while(i++)
    {
        int64_t sum;


        if(i%2==0)
        {
            sum = num[i/2]*num[i-1];
        }
        else
        {
            sum = num[(i-1)/2]* num[i];
        }
        if(sum > 500) break;
    }
    printf("%"PRId64"\n",i*(i-1)/2);
}