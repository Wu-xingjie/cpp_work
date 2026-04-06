#include "rectangle_expansion.h"
#include <algorithm>
#include <boost/make_shared.hpp>
#include <stdexcept>

RecExpantion::RecExpantion(const std::string &file_path) {
  _base_ref = boost::make_shared<BaseRef>();
  _base_ref->getBaseDate(file_path);
}

std::array<double, 2> RecExpantion::update_rec(const double &num1,
                                               const double &num2,
                                               bool initial_data) {
  if (!_base_ref) {
    throw std::runtime_error("[ERROR] 参考扩张行为空");
  }
  if (num1 < 1.0e-20 or num2 < 1.0e-20) {
    throw std::runtime_error("[ERROR] 矩形两边必须为正，程序运行错误");
  }
  // 获取width
  double width = (num1 <= num2) ? num1 : num2;
  double length = (num1 <= num2) ? num2 : num1;
  // 获取最佳扩张行
  auto bast_ref_data = _base_ref->getBastExpanDate(width);
  // 进行数据扩张
  expantion(width, length, bast_ref_data.second);
  // 刷新width和length
  refreshWidth(width, length);
  // 如果需要行数扩张后大于当前最佳扩张行宽度，则递归地继续进行扩张
  // 直到满足退出条件
  std::array<double, 2> recur_date;
  if (width - bast_ref_data.first >= 1.0e-20 &&
      !_base_ref->isLastDate(bast_ref_data.first)) {
    recur_date = update_rec(width, length, false);
    return recur_date;
  }
  std::array<double, 2> new_rec{width, length};
  return new_rec;
}

void RecExpantion::expantion(double &width, double &length,
                             const BaseRef::BaseExpDate &base_data) {
  width += base_data.at("min");
  length += base_data.at("max");
}

void RecExpantion::refreshWidth(double &width, double &length) {
  if (width - length > 1.0e-20) {
    double temp = length;
    length = width;
    width = temp;
  }
}