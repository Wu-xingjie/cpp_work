#include "rectangle_expansion.h"
#include <iostream>

int main() {
  RecExpantion rec_expantion(
      "/home/wxj/workspace/cpp_work/thrid/width_info.txt");
  auto expan_1 = rec_expantion.update_rec(0.03, 0.05);
  std::cout << expan_1.at(0) << ", " << expan_1.at(1) << std::endl;
  return 0;
}