#ifndef PROBLE7
#define PROBLE7
#include <math.h>
#define __STDC_FORMAT_MACROS
#include <inttypes.h>

#define max_num 10000000
int64_t prime[max_num] = { 0 };
int64_t num[max_num] = { 0 };
int64_t sum_min[max_num] = { 0 };

int test_eular7(int n)
{

	int i = 1;
	if(n > 10003) return 0;
	while(prime[0]	<10005)
	{
		i++;
		if(!prime[i])
                {
                    prime[++prime[0]] = i;
                    if(prime[0] == n)
                    {
                            return i;
                    }

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
}

#endif // PROBLE7
