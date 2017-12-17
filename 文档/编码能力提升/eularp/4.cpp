#include <stdio.h>
#include <math.h>
#include <inttypes.h>


int is_plat(int x)
{
	/**
	 * 1 ： 数翻转并比较
	 * 2 ： 将数的高位和低位比较
	 */
	//2
	int high = pow(10,floor(log10(x)));
	while(x>0)
	{
		if(x/high!=x%10)
		{
			return 0;
		}
		x%=high;
		x/=10;
		high/=100;
	}
	return 1;
}

int main()
{
	int max_num = 0;
	for(int i=100;i<1000;i++)
	{
		for(int j=i;j<1000;j++)
		{
			if(is_plat(i*j)&&max_num<i*j)
			{
				max_num = i*j;
			}
		}
	}
	printf("%d\n", max_num);
}