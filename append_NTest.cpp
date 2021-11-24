#include <gtest/gtest.h>
#include "argparser-test-version.h"

class store_NormTest : public ::testing::Test 
{
protected:
    void SetUp() override 
    {
        a.arg_name = "APPEND_ARG";
        a.set_flags("-a", "--apple");
        a.set_help_message("decides if apple or not");
        a.set_nargs(3);
        a.set_action(APPEND);
        
        p.add_arguments(&a);
        p.set_prog_name("argparse_test2");
        p.set_description("second argparse test in suite");
    }

    argument a;
    parser p;
};