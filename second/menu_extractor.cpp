#include "menu_extractor.h"
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <algorithm>

std::vector<std::string> MenuExtractor::parseMenuLine(const std::string &line)
{
    std::vector<std::string> parser_content;

    int num_ref = 0;
    size_t fir_ref = line.find('"');
    std::string content;
    for (size_t cur_idx = fir_ref; cur_idx < line.size(); cur_idx++)
    {
        auto word = line.at(cur_idx);
        if (word == '"')
        {
            num_ref += 1;
        }
        if (!std::isspace(word))
        {
            if (word != '"')
            {
                content += word;
            }
            if (word == '"' && num_ref % 2 == 0)
            {
                parser_content.push_back(content);
                content.clear();
            }
        }
        else
        {
            if (num_ref % 2 == 1)
            {
                content += word;
            }
            else
            {
                if (content != "")
                {
                    parser_content.push_back(content);
                    content.clear();
                }
            }
        }
    }
    return parser_content;
}

void MenuExtractor::parseMenu(const std::string &menu_path)
{
    std::fstream file;
    file.open(menu_path, std::ios_base::in);
    if (file.is_open())
    {
        std::string line;
        while (file.good())
        {
            std::getline(file, line);
            // 跳过#开头的注释行
            auto fir_nempty_char = line.find_first_not_of(" \t\n\r\f\v");
            if (line.at(fir_nempty_char) == '#')
            {
                continue;
            }
            // 解析每一行信息
            if (line.find("Menu") != std::string::npos)
            {
                size_t first_u = line.find_first_of("u");
                _menu_name = line.substr(first_u + 2);
            }
            else if (line.find("{") != std::string::npos || line.find("}") != std::string::npos)
            {
                continue;
            }
            else
            {
                auto content_parsered = parseMenuLine(line);
                if (content_parsered.size() != 4)
                {
                    throw std::runtime_error("[ERROR] " + line + "解析错误\n");
                }
                cmdItem temp_cmditem;
                temp_cmditem.label = content_parsered.at(0);
                temp_cmditem.type = content_parsered.at(1);
                temp_cmditem.dummy = content_parsered.at(2);
                temp_cmditem.tclCmd = content_parsered.at(3);
                _cmd_items.push_back(temp_cmditem);
            }
        }
    }
    else
    {
        throw std::runtime_error("[ERRO] >> 文件路径" + menu_path + "打开失败");
    }
    file.close();
}

void MenuExtractor::printInfo()
{
    if (_cmd_items.size() == 0)
    {
        std::cout << "[INFO] 当前信息为空" << std::endl;
    }
    else
    {
        std::cout << "Menu:" << _menu_name << std::endl;
        for (auto &item : _cmd_items)
        {
            std::cout << "CmdItem1:label=" << item.label << ", Type=" << item.type << ", Dummy=" << item.dummy << ", tclCmd=" << item.tclCmd << std::endl;
        }
    }
}
