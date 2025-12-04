#include <bits/stdc++.h>

using namespace std;

/*
    纯虚函数特点：
        只有声明，没有实现（也可以有默认实现，但一般不用）
        继承它的类必须重写它，否则该类也成为抽象类

    包含至少一个纯虚函数的类就是抽象类。
    抽象类的特点：
        ✔ 无法实例化对象（不能直接创建对象）
        ✔ 可以有普通函数、虚函数、成员变量等
        ✔ 用来作为“接口”或“基类”
*/

// 抽象类：Shape
class Shape {
public:
    virtual void draw() = 0;   // 纯虚函数
    virtual ~Shape() {}        // 虚析构函数（多态情况下必须）
};

// 派生类：Circle
class Circle : public Shape {
public:
    void draw() override {
        cout << "Draw Circle\n";
    }
};

// 派生类：Square
class Square : public Shape {
public:
    void draw() override {
        cout << "Draw Square\n";
    }
};

//这就是一个纯接口类（类似 Java interface）
class Animal {
public:
    virtual void speak() = 0;
    virtual void eat() = 0;
};


int main() {
    // Shape s;         // ❌ 抽象类不能实例化

    Shape* p1 = new Circle();
    Shape* p2 = new Square();

    p1->draw();        // Draw Circle
    p2->draw();        // Draw Square

    delete p1;
    delete p2;
}
