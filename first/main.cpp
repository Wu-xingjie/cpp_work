#include "string_compare.h"
#include <cstring>
#include <iostream>
int main() {
  try {
    StrCmp str_comp;
    std::cout
        << "程序说明:\nstrcmpWithDigital(a, b)=1 :a >b\nstrcmpWithDigital(a, "
           "b)=-1 :a <b\nstrcmpWithDigital(a, b)=0 :a=b"
        << std::endl;
    std::cout << "-----------" << std::endl;
    // b90c <-> c21a
    std::cout << "b90c = 98 + 90 + 99 = 287" << std::endl;
    std::cout << "c21a = 99 + 21 + 97 = 217" << std::endl;
    std::cout << "b90c和c21a比较结果:"
              << str_comp.strcmpWithDigital("b90c", "c21a") << std::endl;

    // a99 <-> a120
    std::cout << "-----------" << std::endl;
    std::cout << "a99 = 97 + 99 = 196" << std::endl;
    std::cout << "a120 = 97 + 120 = 217" << std::endl;
    std::cout << "a99和a120比较结果:"
              << str_comp.strcmpWithDigital("a99", "a120") << std::endl;

    // 99a <-> 100c
    std::cout << "-----------" << std::endl;
    std::cout << "99a = 99 + 97 = 196" << std::endl;
    std::cout << "100c = 100 + 99 = 199" << std::endl;
    std::cout << "99a和100c比较结果:"
              << str_comp.strcmpWithDigital("99a", "100c") << std::endl;

    // abc23eg <-> abc129b
    std::cout << "-----------" << std::endl;
    std::cout << "abc23eg = 97 + 98 +99 + 23 +101 + 103= 521" << std::endl;
    std::cout << "abc129b = 97 + 98 + 99 + 129 + 98 = 521" << std::endl;
    std::cout << "abc23eg和abc129b比较结果:"
              << str_comp.strcmpWithDigital("abc23eg", "abc129b") << std::endl;

    // abd23 <-> abc123
    std::cout << "-----------" << std::endl;
    std::cout << "abd23 = 97 + 98 + 100 + 23= 318" << std::endl;
    std::cout << "abc123 = 97 + 98 + 99 + 123 = 417" << std::endl;
    std::cout << "abd23和abc123比较结果:"
              << str_comp.strcmpWithDigital("abd23", "abc123") << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
  return 0;
}