#include <stdio.h>
#include <math.h>
#include <inttypes.h>


int main()
{
	int64_t num = 600851475143LL;
	int64_t max_prime = 0;
	for(int64_t i = 2;i*i <= num;i++)
	{
		if(num%i==0)
		{
			while(num%i==0)
			{
				num/=i;
			}
			max_prime = i;
			printf("%lld\n",num);
		}
		
	}
}