#include <stdio.h>
#include <math.h>
#include <inttypes.h>

//最大公约数: gcb(a,b) = gcb(b,a%b)
int gcb(int x,int y)
{
	if(y==0) return x;
	return gcb(y,x%y);
}
//最小公倍数: c = a*b/gcb(a,b)
int gb(int a,int b)
{
	return a/gcb(a,b)*b;
}
int main()
{
	int sum=1;
	int i;
	for(i=1;i<=20;i++)
	{
		sum=gb(sum,i);
	}
	printf("%d\n",sum%11);
	return 0;
}