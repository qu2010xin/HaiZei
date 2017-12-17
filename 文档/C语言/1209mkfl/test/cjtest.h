#ifndef CJTEST
#define CJTEST
#include <stdio.h>
#define TEST(a,b) \
        void test##a##_##b(TEST_INFO *ti);   \
        int p##a##_##b = my_test(test##a##_##b, #a, #b); \
        void test##a##_##b(TEST_INFO *ti)


#define EXPECT(a,b) ({                  \
        a==b?ti->yesnum++:ti->nonum++;    \
        ti->testnum++;                   \
})


typedef struct TEST_INFO{
        int testnum;
        int yesnum;
        int nonum;
/*
        int GF;
        int LT;
        int GE;
        int LE;
        int EQ;
        int NE;
*/
}TEST_INFO;



int my_test(void (*func)(TEST_INFO *), const char *s1, const char *s2)
{
        TEST_INFO ti = {0,0,0};
        //  TEST_INFO ti = {0,0,0,0,0,0};
        printf("[run    ]%s%s\n", s1, s2);
        func(&ti);
        if(ti.nonum == 0)
        {
                printf("[ok     ]%s%s  total:%d\n", s1, s2, ti.testnum);
        }
        else
        {
                printf("[failed ]%s%s  %d pass %d failed\n", s1, s2, ti.yesnum, ti.nonum);
                //printf("[failed ]%s%s", );
        }
        return 0;
}
#endif // CJTEST
