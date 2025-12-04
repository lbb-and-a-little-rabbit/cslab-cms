#include <bits/stdc++.h>

using namespace std;

/*
    柯里化是一种函数式编程技术：
    将一个接受多个参数的函数，转换成 一系列只接受一个参数的函数，每次返回一个新的函数，直到所有参数都传完为止，最终返回结果。

    即：
    f(a, b, c)  --->  f(a)(b)(c)
*/

/*
    柯里化的特点

        分步传参：函数参数可以逐步传递

        返回函数：每一步返回一个函数等待下一个参数

        高阶函数：返回值本身是函数

        便于函数组合：可以与 lambda 和闭包结合
*/

//普通：
int add(int a, int b, int c) {
    return a + b + c;
}

//柯里化：
auto addCurried = [](int a) {
    return [a](int b) {
        return [a, b](int c) {
            return a + b + c;
        };
    };
};

auto multiply = [](int a) {
    return [a](int b) { return a * b; };
};

int main(){
    cout << add(1, 2, 3) << endl; // 输出 6
    auto step1 = addCurried(1);     // 返回一个函数，等待 b
    auto step2 = step1(2);          // 返回一个函数，等待 c
    int result = step2(3);          // 返回最终结果
    cout << result << endl;         // 输出 6

    // 或直接链式调用
    cout << addCurried(1)(2)(3) << endl; // 输出 6

    auto doubleValue = multiply(2); // 固定 a = 2
    cout << doubleValue(5) << endl; // 10
    cout << doubleValue(10) << endl; // 20
}