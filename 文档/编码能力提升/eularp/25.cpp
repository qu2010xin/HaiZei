#include <stdio.h>
#include <math.h>
#include <inttypes.h>
#include <string.h>

int main()
{
	int64_t fib[3][1005] = {0};
	fib[0][2] = fib[0][1] = 1;
	fib[1][2] = fib[1][1] = 1;
	//fib[2][2] = fib[2][1] = 2;
	fib[0][0] = fib[1][0] = 2;
	int n = 2;
	printf("%d\n", n);
	while(fib[(n-1)%3][0] <= 1000)
	{
		
		fib[n%3][0] = fib[(n-1)%3][0];
		for(int i = 1; i <= fib[(n)%3][0]; i++)
		{
			fib[(n)%3][i] = fib[(n-2)%3][i] + fib[(n-1)%3][i];
		}
		for(int i = 1; i <= fib[(n)%3][0]; i++)
		{
			if(fib[(n)%3][i] < 10)  continue;
			fib[(n)%3][i+1] += fib[(n)%3][i]/10;
			fib[(n)%3][i] %= 10;
			if(i==fib[(n)%3][0])  fib[(n)%3][0]++;
		}
		n++;
	}
	printf("%d\n", n);
}