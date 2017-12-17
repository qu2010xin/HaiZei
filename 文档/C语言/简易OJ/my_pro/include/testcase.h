#ifndef TESTCASE
#define TESTCASE


#include "test.h"
#include "problem6.h"
#include "problem7.h"
#include "problem15.h"
#include "problem16.h"
#include "problem31.h"
#include "oula.h"

TEST(test_,eular_6)
{
        for(int i = 1; i <= max_test_num; i++)
        {
                int my_num = test_eular6(i);
                int o_num = oula6(i);
		EXPECT(my_num,o_num);
                //ASSIGN(my_num, o_num);
        }
}

TEST(test_,eular_7)
{
        for(int i = 1; i <= max_test_num; i++)
        {
                int my_num = test_eular7(i);
                int o_num = 0;
                EXPECT(my_num, o_num);
        }
}


TEST(test_,eular_15)
{
        
        for(int i = 1; i <= max_test_num; i++)
        {
                int64_t my_num = test_eular15(i);
                int64_t o_num = (int64_t)oula15(i);
                EXPECT(my_num, o_num);
        }
        
        
}

TEST(test_,eular_16)
{
	for(int i = 1; i <= max_test_num; i++)
	{
		int my_num = test_eular16(i);
		int o_num = oula16(i);
		EXPECT(my_num, o_num);
	}
}

TEST(test_,eular_31)
{
	for(int i = 1; i <= 200; i++)
	{
		int my_num = test_eular31(i);
		int o_num = oula31(i);
		EXPECT(my_num, o_num);
	}
}

#endif
