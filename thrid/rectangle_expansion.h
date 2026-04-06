#pragma once
#include "refer_base.h"
#include <array>
#include <boost/shared_ptr.hpp>

class RecExpantion {
public:
  RecExpantion(const std::string &file_path);
  ~RecExpantion() = default;

  std::array<double, 2> update_rec(const double &num1, const double &num2,
                                   bool initial_data = true);

protected:
  void expantion(double &width, double &length,
                 const BaseRef::BaseExpDate &base_data);

public:
  boost::shared_ptr<BaseRef> _base_ref;
};