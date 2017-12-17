#include <stdio.h>
#include <math.h>
#include <inttypes.h>
#include <string.h>

int w(int k)
{
	int arry[8] = {1,2,5,10,20,50,100,200};
	return arry[k-1];
}
/*
int f(int k,int n)
{
	if(n==0) return 1;
	if(n<0) return 0;
	if(k==1) return 1;
		return (f(k-1,n)+f(k,n-w(k)));
}
*/
int main()
{
//	printf("%d\n",f(8,200));
	int f[205];
	for(int i = 0; i <= 200; i++)
	{
		f[i] = 1;
	}
	for(int i = 1; i <= 8; i++)
	{
		f[0] = 1;
	}
	for(int i = 2;i <= 8;i++)
	{
		for(int j = 1; j <= 200; j++)
		{
			int b = 0;
			if(j - w(i) >= 0)
			{
				b = f[j-w(i)];
			}
			f[j] = f[j] + b;
		}
	}
	printf("%d\n", f[200]);
}