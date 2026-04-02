#pragma once
#include <string>
#include <vector>

class MenuExtractor
{
public:
    MenuExtractor() = default;
    ~MenuExtractor() = default;

    // 解析输入文件
    void parseMenu(const std::string &menu_path);
    // 输出信息
    void printInfo();

protected:
    // 解析menu中的每一行
    std::vector<std::string> parseMenuLine(const std::string &line);
    // 判断字符串line中是否包含子字符串
private:
    struct cmdItem
    {
        std::string label;
        std::string type;
        std::string dummy;
        std::string tclCmd;
    };
    std::string _menu_name;
    std::vector<cmdItem> _cmd_items;
};