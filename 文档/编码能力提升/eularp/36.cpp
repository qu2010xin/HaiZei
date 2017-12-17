#include <stdio.h>
#include <math.h>
#include <inttypes.h>

int gcb(int x,int y)
{
	if(y==0) return x;
	return gcb(y,x%y);
}

int main()
{
	int sum=1;
	int i;
	for(i=1;i<=20;i++)
	{
		sum=sum/gcb(sum,i)*i;
	}
	printf("%d\n",sum);
	return 0;
}