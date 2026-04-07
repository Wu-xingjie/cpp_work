#include "menu_extractor.h"
#include <iostream>

int main(int argc, char *argv[]) {
  try {
    if (argc != 2) {
      throw std::runtime_error(
          "[ERRO] 输入格式异常\n程序调用方式: ./main [menu文件路径]");
    }
    MenuExtractor menu_extractor;
    std::string file_path = argv[1];
    menu_extractor.parseMenu(file_path);
    menu_extractor.printInfo();
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  return 0;
}