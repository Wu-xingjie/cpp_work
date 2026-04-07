#include "rectangle_expansion.h"
#include <iostream>

int main(int argc, char *argv[]) {
  try {
    if (argc != 2) {
      throw std::runtime_error(
          "[ERRO] 输入格式异常\n程序调用方式: ./main [menu文件路径]");
    }
    std::string file_path = argv[1];
    RecExpantion rec_expantion(file_path);
    auto expan_1 = rec_expantion.update_rec(0.03, 0.05);
    std::cout << expan_1.at(0) << ", " << expan_1.at(1) << std::endl;
    auto expan_2 = rec_expantion.update_rec(0.08, 0.044);
    std::cout << expan_2.at(0) << ", " << expan_2.at(1) << std::endl;
    std::cout << "按题目算法(0.052,0.052)这组数据的迭代过程为(0.052,0.052)->"
                 "\n最佳扩张行0.053,扩张结果(0.061,0.081)->\n最佳扩张行0.06,"
                 "扩张结束，扩张结果(0.064,0.095)"
              << std::endl;
    auto expan_3 = rec_expantion.update_rec(0.052, 0.052);
    std::cout << expan_3.at(0) << ", " << expan_3.at(1) << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
  return 0;
}