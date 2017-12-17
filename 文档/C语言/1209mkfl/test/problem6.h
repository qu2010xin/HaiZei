#ifndef PROBLE6
#define PROBLE6
int test_eular6(int n)
{
        int sum1 = 0;
	int sum2 = 0;
	for(int i=1;i<=n;i++)
	{
		sum1+=i*i;
		sum2 += i;
	}
	sum2=sum2*sum2-sum1;
	return sum2;
}
#endif // PROBLE6
