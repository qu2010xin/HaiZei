#include <stdio.h>
#include <math.h>



#define epsl 1e-7

double fabs(double x)
{
	return x>0?x:-x;
}
double sqr(double x)
{
	if(x <= 0) return 0;
	double min_num = 0;
	double max_num = x + 1;
	double mid_num;
	while(max_num - min_num > epsl)
	{
		mid_num = (max_num + mid_num)/2	;
		if(fabs(mid_num*mid_num - x) < epsl)
		{
			max_num = mid_num; 
		}
		else if(mid_num * mid_num > x)
		{
			min_num = mid_num;
		}
		else if(mid_num * mid_num < x)
		{
			break;
		}
	}
	return mid_num;
}

static int out()
{
	printf("hello\n");
	return 1;
}

int num = out();

int main()
{
	float x;
	while(~scanf("%f", &x))
	{
		int a =  *(int *)(&x);
		a>>=1;
		float b = *(float *)(&a);
		printf("%f\n", b);
	}
}