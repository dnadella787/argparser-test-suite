#include <gtest/gtest.h>
#include "argparser-test-version.h"

class append_DeathTest : public ::testing::Test 
{
protected:
    void SetUp() override 
    {
        a.arg_name = "APPEND_ARG";
        a.set_flags("-v", "--verbose");
        a.set_help_message("decides output style");
        a.set_nargs(3);
        a.set_action(APPEND);
        
        p.add_arguments(&a);
        p.set_prog_name("argparse_test2");
        p.set_description("second argparse test in suite");
    }

    argument a;
    parser p;
};




TEST_F(append_DeathTest, h_message_works1)
{

}


