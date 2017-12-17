#include <stdio.h>
#include <math.h>
#include <inttypes.h>
int grub(int x,int y)
{
	if(x < y)
	{
		x^=y; y^=x; x^=y;
	}
	if(x%y == 0) return y;
	return grub(y,x%y);
}
int is_grub(int a,int b,int c)
{
	return grub(a,b)==1&&grub(b,c)==1&&grub(c,a)==1;
}
int main()
{
	int n = 1,m = 1;
	for(n = 1; n <= 1000; n++)
    {
		for(m = 1; m <+ 1000; m++)
		{
			int a = 2 * m * n;
			int b = m * m - n * n;
			int c = m * m + n * n;
			if((1000% (a+b+c)== 0&& a > 0 && b > 0 && c > 0 )&& is_grub(a,b,c))
			{
				printf("%f\n",pow(1000/(a+b+c), 3)*a*b*c);
				return 0;
			}
		}
	}
}