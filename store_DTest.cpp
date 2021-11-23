#include <gtest/gtest.h>
#include "argparser-test-version.h"


/*
TEST CASE/SUITE: Death Tests for STORE action

This file is filled with action STORE tests where 
the test is meant to cause an exit of some kind 
whether it be for the help message (EXIT_SUCCESS) 
or an actual error (EXIT_FAILURE).

each test uses the objects defined in the class
store_DeathTest and have the starting behavior 
according to the SetUp() function.
*/
class store_DeathTest : public ::testing::Test 
{
protected:
    void SetUp() override 
    {
        a.arg_name = "STORE_ARG";
        a.set_flags("-a", "--apple");
        a.set_help_message("decides if apple or not");
        a.set_action(STORE);
        

        p.add_arguments(&a);
        p.set_prog_name("argparse_test1");
        p.set_description("first argparse test in suite");
    }

    argument a;
    parser p;
};


/*
simple test, just checks to see if help message 
is actually outputted

all help_message_worksx tests establish that help
message takes priority over any error that would
cause an exit

LOOK FOR BETTER SOLUTION THAN CaptureStdout for
all help_message_worksx tests
*/
TEST_F(store_DeathTest, help_message_works1)
{
    char* argv_help1[2] = { (char*)"prog_name", (char*)"-h" };
    int argc_help1 = 2;

    testing::internal::CaptureStdout();
    EXPECT_EXIT(p.parse_args(argc_help1, argv_help1), testing::ExitedWithCode(EXIT_SUCCESS), "");
    std::cout.flush();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("-a"), std::string::npos);
    EXPECT_NE(output.find("--apple"), std::string::npos);
    EXPECT_NE(output.find("decides if apple or not"), std::string::npos);
    EXPECT_NE(output.find("description"), std::string::npos);
    EXPECT_NE(output.find("argparse_test1"), std::string::npos);
    EXPECT_NE(output.find("first argparse test in suite"), std::string::npos);
    EXPECT_NE(output.find("generates this help/usage message"), std::string::npos);
}


/*
makes sure help message is outputted even though 
unrecognized flags are specified
*/
TEST_F(store_DeathTest, help_message_works2)
{
    char* argv_help2[4] = { (char*)"prog_name", (char*)"--a", (char*)"input1", (char*)"-h" };
    int argc_help2 = 4;

    testing::internal::CaptureStdout();
    EXPECT_EXIT(p.parse_args(argc_help2, argv_help2), testing::ExitedWithCode(EXIT_SUCCESS), "");
    std::cout.flush();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("generates this help/usage message"), std::string::npos);

    // EXPECT_NE(output.find("-a"), std::string::npos);
    // EXPECT_NE(output.find("--apple"), std::string::npos);
    // EXPECT_NE(output.find("decides if apple or not"), std::string::npos);
    // EXPECT_NE(output.find("description"), std::string::npos);
    // EXPECT_NE(output.find("argparse_test1"), std::string::npos);
    // EXPECT_NE(output.find("first argparse test in suite"), std::string::npos);
}


/*
makes sure that help message is outputted 
even though multiple invalid inputs are specified.
*/
TEST_F(store_DeathTest, help_message_works3)
{
    char* argv_help3[5] = { (char*)"prog_name", (char*)"--bjor", (char*)"-grskd", (char*)"-dfks", (char*)"-h" };
    int argc_help3 = 5;

    testing::internal::CaptureStdout();
    EXPECT_EXIT(p.parse_args(argc_help3, argv_help3), testing::ExitedWithCode(EXIT_SUCCESS), "");
    std::cout.flush();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("generates this help/usage message"), std::string::npos);
}


/*
makes sure that program ends if a required input
is not specified, in this case the -a, --apple.
Should EXIT_FAILURE and output to stderr, check both.
*/
TEST_F(store_DeathTest, requirement_works)
{
    a.set_requirement(true);
    ASSERT_EQ(true, a.is_required);

    char* argv_[3] = { (char*)"prog_name" , (char*)"nonsense", (char*)"nonsense" };
    int argc_ = 3;

    EXPECT_EXIT(p.parse_args(argc_, argv_), testing::ExitedWithCode(EXIT_FAILURE), "required STORE argument");
}


/*
make sure that the program ends if too many inputs 
are given for -a or --apple. Should EXIT_FAILURE and 
output to stderr, check both.
*/
TEST_F(store_DeathTest, too_many_inputs_works2)
{
    ASSERT_EQ(STORE, a.action);
    char* argv_1[4] = { (char*)"prog_name", (char*)"-a", (char*)"first", (char*)"second" };
    int argc_1 = 5;
    
    EXPECT_EXIT(p.parse_args(argc_1, argv_1), testing::ExitedWithCode(EXIT_FAILURE), "too many inputs");

    char* argv_2[4] = { (char*)"prog_name", (char*)"--apple", (char*)"first", (char*)"second" };
    int argc_2 = 5;

    EXPECT_EXIT(p.parse_args(argc_2, argv_2), testing::ExitedWithCode(EXIT_FAILURE), "too many inputs");
}


/*
same but check for 3
*/
TEST_F(store_DeathTest, too_many_inputs_works1)
{
    ASSERT_EQ(STORE, a.action);
    char* argv_1[5] = { (char*)"prog_name", (char*)"-a", (char*)"first", (char*)"second", (char*)"third" };
    int argc_1 = 5;
    
    EXPECT_EXIT(p.parse_args(argc_1, argv_1), testing::ExitedWithCode(EXIT_FAILURE), "too many inputs");

    char* argv_2[5] = { (char*)"prog_name", (char*)"--apple", (char*)"first", (char*)"second", (char*)"third" };
    int argc_2 = 5;

    EXPECT_EXIT(p.parse_args(argc_2, argv_2), testing::ExitedWithCode(EXIT_FAILURE), "too many inputs");
}


/*
same but shifted one back
*/
TEST_F(store_DeathTest, too_many_inputs_works3)
{
    ASSERT_EQ(STORE, a.action);
    char* argv_1[5] = { (char*)"prog_name", (char*)"first", (char*)"-a", (char*)"second", (char*)"third" };
    int argc_1 = 5;
    
    EXPECT_EXIT(p.parse_args(argc_1, argv_1), testing::ExitedWithCode(EXIT_FAILURE), "too many inputs");

    char* argv_2[5] = { (char*)"prog_name", (char*)"first", (char*)"--apple", (char*)"second", (char*)"third" };
    int argc_2 = 5;

    EXPECT_EXIT(p.parse_args(argc_2, argv_2), testing::ExitedWithCode(EXIT_FAILURE), "too many input");
}

/*
same but shifted one back and also has unrecognized arguments
but the unrecognized argument should be first error not
too many inputs
*/
TEST_F(store_DeathTest, false_arg_first)
{
    ASSERT_EQ(STORE, a.action);
    char* argv_1[5] = { (char*)"prog_name", (char*)"-first", (char*)"-a", (char*)"second", (char*)"third" };
    int argc_1 = 5;
    
    EXPECT_EXIT(p.parse_args(argc_1, argv_1), testing::ExitedWithCode(EXIT_FAILURE), "not a recognized");

    char* argv_2[5] = { (char*)"prog_name", (char*)"-first", (char*)"--apple", (char*)"second", (char*)"third" };
    int argc_2 = 5;

    EXPECT_EXIT(p.parse_args(argc_2, argv_2), testing::ExitedWithCode(EXIT_FAILURE), "not a recognized");
}


/*
check equal signs store as well
*/



