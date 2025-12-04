#include <bits/stdc++.h>

using namespace std;

/*
    函数对象（仿函数）指 可以像函数一样被调用的对象。
    实现方式：
    重载 operator() 让一个类的对象表现得像函数。
*/

//示例
struct Add {
    int operator()(int a, int b) const {
        return a + b;
    }
};

/*
    函数对象比普通函数更强大，因为它们是 对象，可以：

    保存状态

    携带参数

    在算法中作为策略对象

    比普通函数更容易被内联（更快）
*/
struct Counter {
    int count = 0;

    int operator()(int x) {
        return ++count * x;
    }
};

int main(){
    Add add;
    cout << add(3,4) << '\n';// 7
    Counter ct;
    //普通函数无法记住上一次调用的值，但函数对象可以。
    cout << ct(10) << '\n' << ct(10) << '\n';// 10 20
}

/*
    Lambda 本质上就是 匿名函数对象！
*/
auto f = [](int a, int b) { return a + b; };

//编译
struct __lambda_xxx {
    int operator()(int a, int b) const { return a + b; }
};

