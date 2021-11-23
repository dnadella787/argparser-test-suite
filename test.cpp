#include <iostream>
#include <argparser.h>



int main(int argc, char* argv[])
{
    std::cout << "argc : " << argc << std::endl;
    std::cout << "--------------" << std::endl;
    for (int i = 1; i < argc; i++)
        std::cout << "argv[" << i << "] : " << argv[i] << std::endl;
    std::cout << "--------------" << std::endl;

    char** _argv = (char**)malloc(4 * sizeof(char*));
    _argv[1] = (char *)"-a";
    _argv[2] = (char *)"-b";
    _argv[3] = (char *)"dsalkfjdaslf";

    char* _argv[4] = { "prog_name", "-a", "input2", "--b" };

    for (int i = 1; i < 4; i++)
    {
        std::cout << "_argv[" << i << "] : " << _argv[i] << std::endl;
    }
    std::cout << "--------------" << std::endl;
}