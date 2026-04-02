#include "menu_extractor.h"
#include <iostream>

int main()
{
    try
    {
        MenuExtractor menu_extractor;
        menu_extractor.parseMenu("/home/wuxingjie/workspace/cpp_work/second/menu.txt");
        menu_extractor.printInfo();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}