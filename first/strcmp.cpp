#include <stdexcept>
#include <ctype.h>
#include "strcmp.h"
#include <cstring>
#include <algorithm>
#include <boost/lexical_cast.hpp>

bool StrCmp::isDigit(const std::string &content)
{
    if (content.size() == 0)
    {
        throw std::runtime_error("[ERRO] isdigit输入字符串为空");
    }
    return !content.empty() && std::all_of(content.begin(), content.end(),
                                           [](unsigned char ch)
                                           { return std::isdigit(ch); });
}

int StrCmp::strLength(const char *cst)
{
    // cst为空时直接返回长度为0
    if (cst == nullptr)
    {
        return 0;
    }
    int str_length = 0;
    auto splite_str = splitStr(cst);
    for (auto &&content : splite_str)
    {
        if (isDigit(content))
        {
            str_length += boost::lexical_cast<int>(content);
        }
        else
        {
            str_length += static_cast<int>(content[0]);
        }
    }

    return str_length;
}

std::vector<std::string> StrCmp::splitStr(const char *cst)
{
    if (cst == nullptr)
    {
        return {};
    }
    std::vector<std::string> str_splite;
    std::string temp_num;
    for (const char *p = cst; *p != '\0'; p++)
    {
        if (isdigit(*p))
        {
            temp_num += std::string(std::string(1, *p));
            if (*(p+1) == '\0'){
                str_splite.push_back(temp_num);
                break;
            }
        }
        else
        {
            if (temp_num.size() != 0)
            {
                str_splite.push_back(temp_num);
                temp_num.clear();
            }
            str_splite.push_back(std::string(1, *p));
        }
    }
    return str_splite;
}

int StrCmp::strcmpWithDigital(const char *n1st, const char *n2st)
{
    int n1st_len = strLength(n1st);
    int n2st_len = strLength(n2st);
    if (n1st_len > n2st_len)
    {
        return 1;
    }
    else if (n1st_len == n2st_len)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}