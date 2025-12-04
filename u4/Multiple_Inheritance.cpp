#include <bits/stdc++.h>

using namespace std;

//多继承最常用于“多个接口 + 一个实现类”

class A {
public:
    int x = 10;
};

class B : public A { };
class C : public A { };

class D : public B, public C { };

//菱形继承解决方法：虚继承
class B1 : virtual public A { };
class C1 : virtual public A { };

//虚基类的数据成员在派生类中将会被合并！
class D1 : public B1, public C1 { 
    //多继承时可能出现名称冲突，要用 B1::func() 或 C1::func 指定
};

int main(){
    D d;
    //cout << d.x << '\n'; error x不明确,有两份A
    cout << d.B::x << ' ' << d.C::x << '\n';// 10 10 
    D1 d1;
    cout << d1.x << '\n'; // 10 只有一份A
}