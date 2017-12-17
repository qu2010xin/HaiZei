#include <stdio.h>
#include <math.h>
#include <inttypes.h>
#include <string.h>
#include "my_h.h"
#define max_num 13

int main()
{
	long long sum = 0;
	int i = 0;
	long long n = 1;
	int k = 0;
	while(i < 1000)
	{
		int b = s[i] - '0';
		n *= b;
		if(b != 0)
		{
			k++;
		}
		else
		{
			k = 0;
			n = 1;
		}
		if(k > max_num )
		{
			n /= (s[i-max_num] - '0');
			k--;
		}
    	
    	
    	
		(sum < n && k == max_num) && (sum = n);
		i++;
		//printf("%d :  %d\n",i,n);
	}	
	printf("%lld \n",sum);
}