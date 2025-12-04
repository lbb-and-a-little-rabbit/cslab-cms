//#define NDEBUG 禁用断言
#include <cassert>

int main() {
    int x = 5;
    assert(x > 0); // 条件成立，程序继续运行
    assert(x < 0); // 条件不成立，程序终止
}
//输出 Assertion failed: x < 0, file ...\cslab-cms\u7\assertion.cpp, line 7