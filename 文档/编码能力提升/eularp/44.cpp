#include <stdio.h>
#include <math.h>
#include <inttypes.h>
#include <string.h>

inline int64_t penta(int64_t n)
{
    return n*(3*n-1)/2;
}

int is_penta(int64_t x)
{
    int64_t min = 1;
    int64_t max = x ;
    int64_t y;
    int64_t mid ;
    while(min <= max)
    {
        mid = ( min + max) >> 1;
        y = penta(mid);	
        if(x == y)
        {
            return 1;
        }
        else if(x < y)
        {
            max = mid -1;
        }
        else if(x > y)
        {
            min = mid + 1;
        }
    }
    return 0;
}

int main()
{
    int k = 2;
    int j;
    int64_t D = INT64_MAX;
    while((penta(k) - penta(k-1)) < D)
    {
        j = k -1;
        while((penta(k) - penta(j)) < D)
        {
            if(is_penta(penta(k) - penta(j)) && is_penta(penta(k) + penta(j)))
            {
                D = penta(k) - penta(j);
            }
            j--;
            if(j == 0) break;
        }
        k++;
    }
    printf("%"PRId64"\n",D);
}