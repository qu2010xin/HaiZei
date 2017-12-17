#ifndef TESTCASE
#define TESTCASE
#include "cjtest.h"
#include "newton.h"
#include "problem6.h"
#include "problem7.h"
#include "problem15.h"
/*
TEST(test_,my_newton)
{

        for(int i = 1; i < 100; i++)
        {
                EXPECT(i, my_newton(i));
        }

}

TEST(test_,eular_6)
{
        for(int i = 1; i <= 100; i++)
        {
                int my_num = test_eular6(i);
                int o_num = 0;
                EXPECT(my_num, o_num);
        }
}

TEST(test_,eular_7)
{
        for(int i = 1; i <= 100; i++)
        {
                int my_num = test_eular7(i);
                int o_num = 0;
                EXPECT(my_num, o_num);
        }
}
*/

TEST(test_,eular_15)
{
        /*
        for(int i = 1; i <= 100; i++)
        {
                int my_num = test_eular7(i);
                int o_num = 0;
                EXPECT(my_num, o_num);
        }
        */
        EXPECT((int64_t)137846528820, (int64)test_eular15(20));
}

#endif // TESTCASE
