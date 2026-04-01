#include "strcmp.h"
#include <iostream>
#include <cstring>
int main()
{
    try
    {
        StrCmp str_comp;
        std::cout << str_comp.strcmpWithDigital("b90c", "c21a") << std::endl;
        // std::cout << "答案：" << strcmp("b90c", "c21a") << std::endl;
        std::cout << str_comp.strcmpWithDigital("a99", "a120") << std::endl;
        std::cout << str_comp.strcmpWithDigital("99a", "10c") << std::endl;
        std::cout << str_comp.strcmpWithDigital("abc23eg", "abc129b") << std::endl;
        std::cout << str_comp.strcmpWithDigital("abd23", "abc123") << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}