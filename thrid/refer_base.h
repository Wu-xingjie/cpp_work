#pragma once
#include <map>
#include <string>
#include <vector>

// 记录扩张基准数据
class BaseRef {
public:
  BaseRef() = default;
  ~BaseRef() = default;
  // 解析扩张基准文件，给成员变量赋值
  void getBaseDate(const std::string &file_path);
  typedef std::map<std::string, double> BaseExpDate;
  // 获取最佳扩张行
  BaseExpDate getBastExpanDate(const double &width);

protected:
  // 解析有效行
  std::vector<std::string> parserLine(const std::string &line);

private:
  // 存储扩展基准width
  std::vector<double> _base_width;
  std::map<double, BaseExpDate> _base_data;
};