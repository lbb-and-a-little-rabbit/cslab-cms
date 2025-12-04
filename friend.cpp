#include <bits/stdc++.h>

using namespace std;

//友元（friend）允许 外部函数或类访问一个类的私有成员（private/protected）。
class A;  // 前置声明 A

class C {
public:
    void printA(const A& a);  // 先声明成员函数   
};


class A {
private:
    int x;

    friend class B;// B 是 A 的友元类  B是A的友元,不代表A是B的友元
    friend void C::printA(const A& a);

public:
    A(int val) : x(val) {}

    friend void show(const A& a);  // 声明友元函数
};

class B {
public:
    void printA(const A& a) {
        cout << a.x << endl;  // 可以访问 private
    }
};

void C::printA(const A& a){
    cout << a.x << endl;  // 可以访问 private
}

void show(const A& a) {
    cout << "x = " << a.x << endl;  // 可以访问 private 成员
}

class Point {
private:
    int x, y;

public:
    Point(int x, int y) : x(x), y(y) {}

    //友元用于运算符重载
    friend ostream& operator<<(ostream& os, const Point& p);
};

ostream& operator<<(ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}


int main() {
    A obj(10);
    B b;
    C c;
    show(obj);   // 调用友元函数
    b.printA(obj); // 10
    c.printA(obj); // 10
    Point point(3,5);
    cout << point << '\n'; // (3, 5)
}