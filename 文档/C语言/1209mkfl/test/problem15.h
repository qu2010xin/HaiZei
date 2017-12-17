#ifndef PROBLE15
#define PROBLE15
#include <stdio.h>
#include <math.h>
#define __STDC_FORMAT_MACROS
#include <inttypes.h>

int64_t grub(int64_t a, int64_t b)
{
        if(a < b)
        {
                a ^= b;
                b ^= a;
                a ^= b;
        }
        if(a % b == 0) return b;
        return grub(b, a % b);
}

int64_t test_eular15(int n)
{

        int64_t sum_i = 1;
        int64_t sum_j = 1;
        int sz[50];
        int temp;
        int j=0;
        for(int i = n + 1; i <= 2 * n; i++)
        {
                sum_i*=i;
                j++;

                        sum_j *= j;

                temp = grub(sum_i, sum_j);
               while(temp!= 1)
                {
                        sum_i /= temp;
                        sum_j /= temp;
                        temp = grub(sum_i, sum_j);
                }
        }
        return sum_i;

}

#endif // PROBLE15

