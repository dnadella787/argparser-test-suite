#include <gtest/gtest.h>
#include "argparser-test-version.h"

class store_test : public ::testing::Test 
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


TEST_F(store_test, proper_setup_works)
{
    ASSERT_EQ(1, p.known_arguments.size()) << "STORE argument could not be added to parser" << std::endl;

    ASSERT_EQ(2, a.accepted_flags.size());
    EXPECT_EQ("-a", a.accepted_flags[0]);
    EXPECT_EQ("--apple", a.accepted_flags[1]);
    EXPECT_EQ(STORE, a.action);
    EXPECT_EQ("decides if apple or not", a.help_message);
    EXPECT_EQ(false, a.is_required);

    a.set_requirement(true);
    EXPECT_EQ(true, a.is_required);
    
}

TEST_F(store_test, help_message_works1)
{
    char* argv_help1[2] = { (char*)"prog_name", (char*)"-h" };
    int argc_help1 = 2;

    testing::internal::CaptureStdout();
    p.parse_args(argc_help1, argv_help1);
    std::cout.flush();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("-a"), std::string::npos);
    EXPECT_NE(output.find("--apple"), std::string::npos);
    EXPECT_NE(output.find("decides if apple or not"), std::string::npos);
    EXPECT_NE(output.find("description"), std::string::npos);
    EXPECT_NE(output.find("argparse_test1"), std::string::npos);
    EXPECT_NE(output.find("first argparse test in suite"), std::string::npos);
}

TEST_F(store_test, help_message_works2)
{
    char* argv_help1[4] = { (char*)"prog_name", (char*)"-a", (char*)"input1", (char*)"-h" };
    int argc_help1 = 2;

    
}

