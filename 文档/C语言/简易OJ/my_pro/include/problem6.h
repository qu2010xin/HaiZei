#ifndef PROBLE6
#define PROBLE6
#include <math.h>
#include <inttypes.h>

int test_eular6(int n)
{
	if(n < 0) return 0;
        int64_t sum1 = 0;
	int64_t sum2 = 0;
	for(int i=1;i<=n;i++)
	{
		sum1+=i*i;
		sum2 += i;
		if(sum1 > INT32_MAX)
		{
			return 0;
		}
	}
	sum2=sum2*sum2-sum1;
	return (int)sum2;
}
#endif // PROBLE6
