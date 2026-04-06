#include "refer_base.h"
#include <boost/lexical_cast.hpp>
#include <cctype>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <utility>

std::vector<std::string> BaseRef::parserLine(const std::string &line) {
  std::vector<std::string> result;
  std::string num;
  for (int i = 0; i < line.size(); i++) {
    auto word = line.at(i);
    if (isspace(word)) {
      auto fir_nempty_char = num.find_first_not_of(" \t\n\r\f\v");
      if (fir_nempty_char != std::string::npos) {
        // 去除首尾空字符
        auto last_nempty_char = num.find_last_not_of(" \t\n\r\f\v");
        auto valid_num = num.substr(fir_nempty_char, last_nempty_char + 1);
        // 如果valid_num中有括号，则抛出错误
        if (num.find_first_of("()") != std::string::npos) {
          throw std::runtime_error("[ERRO] 字段解析的错误： " + line);
        }
        result.push_back(valid_num);
        num.clear();
      } else {
        // 如果解析出的子字段为空，则不做处理
        num.clear();
      }
    } else {
      if (std::isdigit(word) || word == '.') {
        num = num + word;
      }
    }
  }
  return result;
}

void BaseRef::getBaseDate(const std::string &file_path) {
  std::fstream base_file;
  base_file.open(file_path);
  if (base_file.is_open()) {
    while (base_file.good()) {
      std::string line;
      getline(base_file, line);
      try {
        auto line_parsered = parserLine(line);
        if (line_parsered.size() != 3) {
          throw std::runtime_error("[ERRO] " + line +
                                   "解析错误，该行解析出字段个数：" +
                                   std::to_string(line_parsered.size()));
        }
        double width = boost::lexical_cast<double>(line_parsered.at(0));
        _base_width.push_back(width);
        BaseExpDate temp_data;
        temp_data["min"] = boost::lexical_cast<double>(line_parsered.at(1));
        temp_data["max"] = boost::lexical_cast<double>(line_parsered.at(2));
        _base_data[width] = temp_data;
      } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
      }
    }
  } else {
    throw std::runtime_error("[ERROR] 基准文件打开失败！");
  }
  base_file.close();
}

std::pair<double, BaseRef::BaseExpDate>
BaseRef::getBastExpanDate(const double &width) {
  std::pair<double, BaseExpDate> base_data;
  // 获取最佳扩张行宽度
  int bast_width_idx = -1;
  // 第一行对比
  if (width - _base_width.at(0) < 1.0e-20) {
    bast_width_idx = 0;
  } else {
    for (int i = 1; i < _base_data.size(); i++) {
      double cur_width = _base_width.at(i);
      if (width - cur_width < 1.0e-20) {
        bast_width_idx = i;
        break;
      }
    }
  }
  //   最后一行对比
  if (bast_width_idx == -1) {
    bast_width_idx = _base_width.size() - 1;
  }
  return std::make_pair(_base_width.at(bast_width_idx),
                        _base_data[_base_width.at(bast_width_idx)]);
}

bool BaseRef::isLastDate(const double &width) {
  return (std::abs(width - _base_width.at(_base_width.size() - 1)) < 1.0e-20)
             ? true
             : false;
}