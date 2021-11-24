#include <gtest/gtest.h>
#include "argparser/argparser-test-version.h"

class appendDeathTest : public ::testing::Test 
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



/*
check that help message is triggered and appropriate 
help message is actualy outputted, must include 
functionality unique to action APPEND
*/
TEST_F(appendDeathTest, h_message_works1)
{
    char* argv_[2] = { (char*)"prog_name", (char*)"-h" };
    int argc_ = 2;

    testing::internal::CaptureStdout();
    EXPECT_EXIT(p.parse_args(argc_, argv_), testing::ExitedWithCode(EXIT_SUCCESS), "");
    std::cout.flush();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("-v"), std::string::npos);
    EXPECT_NE(output.find("--verbose"), std::string::npos);
    EXPECT_NE(output.find("decides output style"), std::string::npos);
    EXPECT_NE(output.find("description"), std::string::npos);
    EXPECT_NE(output.find("argparse_test2"), std::string::npos);
    EXPECT_NE(output.find("second argparse test in suite"), std::string::npos);
    EXPECT_NE(output.find("[inputk]"), std::string::npos);
    EXPECT_NE(output.find("generates this help/usage message"), std::string::npos);
}

TEST_F(appendDeathTest, h_message_works2)
{
    char* argv_[6] = { (char*)"prog_name", (char*)"--verbose", (char*)"two", (char*)"one", (char*)"--help" };
    int argc_ = 6;

    testing::internal::CaptureStdout();
    EXPECT_EXIT(p.parse_args(argc_, argv_), testing::ExitedWithCode(EXIT_SUCCESS), "");
    std::cout.flush();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("generates this help/usage message"), std::string::npos);
}


/*
check that the set_requirement works and force an 
exit(EXIT_FAILURE)
*/

TEST_F(appendDeathTest, requirement_works)
{
    a.set_requirement(true);
    char* argv_[3] = { (char*)"prog_name", (char*)"two", (char*)"one" };
    int argc_ = 3;

    EXPECT_EXIT(p.parse_args(argc_, argv_), testing::ExitedWithCode(EXIT_FAILURE), "required ");
}
