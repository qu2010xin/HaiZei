#ifndef TESTH
#define TESTH

#include <stdio.h>
#include <stdlib.h>

#define TEST(a,b) \
	void test_##a##_##b(TEST_INFO *ti);	\
	int p_##a##_##b = my_test(test_##a##_##b, #a, #b);	\
	void test_##a##_##b(TEST_INFO *ti)

#define EXPECT(a,b) ({		\
	__typeof(b) p = b;	\
	__typeof(a) q = a;	\
	if(p == q)	ti->EQ++,ti->GE++,ti->LE++;	\
	else if(p < q)	ti->LT++,ti->NE++;		\
	else		ti->GT++,ti->NE++;		\
	ti->total++;					\
})

#define ASSIGN(a, b) ({		\
	if(a == b) ti->EQ++; 	\
	else			\
	{			\
		printf("\033[;32m [wrong] [answer]\033[0m \n");	\
		exit(0);				\
	}						\
	ti->total++;		\
})

#define max_test_num 1000

typedef struct TEST_INFO
{
	int total;
	int GT;
	int LT;
	int GE;
	int LE;
	int EQ;
	int NE;	
} TEST_INFO;


int my_test(void (*func)(TEST_INFO *), const char *s1, const char *s2)
{
	TEST_INFO ti = {0,0,0,0,0,0,0};
	printf("\033[;32m [run  ]\033[0m %s_%s \n", s1, s2);
	func(&ti);
	if(ti.EQ == ti.total)
	{
		printf("\033[;32m [ok   ]\033[0m total: %d\n", ti.total);
	}
	else
	{
		printf("\033[;32m [fail ]\033[0m total:%5d \n", ti.total);
		printf("	    GT:%5d\n", ti.GT);
		printf("	    LT:%5d\n", ti.LT);
		printf("	    GE:%5d\n", ti.GE);
		printf("	    LE:%5d\n", ti.LE);
		printf("	    EQ:%5d\n", ti.EQ);
		printf("	    NE:%5d\n", ti.NE);
	}
	return 0;
}

#endif
