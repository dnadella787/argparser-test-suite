#include <gtest/gtest.h>
#include "argparser/argparser-test-version.h" 

class storeTFDeathTest : public ::testing::Test 
{
protected:
    void SetUp() override 
    {
        a.arg_name = "STORET_ARG";
        a.set_flags("-t", "--true");
        a.set_help_message("check truthness");
        a.set_action(STORE_TRUE);

        b.arg_name = "STOREF_ARG";
        b.set_flags("-f", "--false");
        b.set_help_message("check falseness");
        b.set_action(STORE_FALSE);
        
        p.add_arguments(&a, &b);
        p.set_prog_name("argparse_test4");
        p.set_description("fourth argparse test in suite");
    }

    argument a;
    argument b;
    parser p;
};


