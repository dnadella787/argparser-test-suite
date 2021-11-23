#include <iostream>
#include "argparser-test-version.h"



int main(int argc, char* argv[])
{
    std::cout << "argc : " << argc << std::endl;
    std::cout << "--------------" << std::endl;
    for (int i = 1; i < argc; i++)
        std::cout << "argv[" << i << "] : " << argv[i] << std::endl;
    std::cout << "--------------" << std::endl;


    char* argv_[5] = { (char*)"prog_name", (char*)"-a", (char*)"first", (char*)"second", (char*)"third" };
    int argc_ = 5;

    argument a("first");
    a.set_flags("-a", "--apple");
    a.set_action(STORE);
    a.set_help_message("decide on apple or not");

    parser p;
    p.add_arguments(&a);
    p.parse_args(argc_, argv_);
}