#pragma once

class StrCmp{
    public:
    StrCmp() = default;
    ~StrCmp() = default;
    // 进行c风格字符串对比
    int strcmpWithDigital(const char* c1st, const char* c2st);
    protected:
    // 解析字符串在ASCII码中的长度
    int strLength(const char* cst);
    // 判断输入的字符是否是阿拉伯数字
    bool isDigit(const char* c)
};