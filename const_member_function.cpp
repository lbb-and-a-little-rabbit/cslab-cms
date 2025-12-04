#include <bits/stdc++.h>

using namespace std;

//在成员函数后面加上 const，表示：
//这个成员函数不会修改对象的数据成员（成员变量）。

class A {
    int x;
    const int y=1;
    mutable int accessCount = 0;
public:
    A(){}

    void func() const{// 常成员函数
        //x++; error
    }
    int getX() const;      // 读取数据

    double length() const; // 计算但不修改

    void print() const;    // 打印

    void func2();

    void func3() const{
        accessCount++;// OK，mutable 允许
    }
};

int main(){
    const A a;
    a.getX();
    //a.func2(); error 不能给 const 对象调用非 const 函数
    //const 对象只能调用 const 成员函数。（除非成员是 mutable）
}
