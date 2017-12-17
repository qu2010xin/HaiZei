#include <stdio.h>
#include <math.h>
#include <inttypes.h>
#include <string.h>

int64_t sum_tran(int64_t x)
{
    if(x%2 == 0)
    {
        return (x / 2) * (x + 1);
    }
    return ((x + 1) / 2) * x;
}

int64_t sum_penta(int64_t x)
{
    if(x%2 == 0)
    {
        return (x / 2) * (3 * x - 1);
    }
    return ((3 * x - 1) / 2) * x;
}

int64_t sum_hex(int64_t x)
{   
    
    return (2 * x - 1) * x;
}

int64_t is(int64_t n,int64_t(*fun)(int64_t))
{
    int64_t max = n;
    int64_t mid;
    int64_t min = 1;
    while(min <= max)
    {
        mid = (max + min) >> 1;
        int64_t y = fun(mid);
        if(n == y)
        {
            return 1;
        }
        else if(n < y)
        {
            max = mid -1;
        }
        else
        {
            min = mid + 1;
        }
    }
    return 0;
}



int main()
{
    int64_t i = 1;
    while(1)
    {
        if(is(i,sum_hex)&&is(i,sum_penta)&&is(i,sum_tran))  
        {
            printf("%"PRId64"\n", i);
        }
       
        i++;
    }
}