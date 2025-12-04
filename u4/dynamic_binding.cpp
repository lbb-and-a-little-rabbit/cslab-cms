#include <bits/stdc++.h>

using namespace std;

/*
    C++默认采用的是静态绑定！在编译时刻，由引用和指针的类型来决定。
*/

/*
    在 C++ 中，如果通过 基类指针或引用 调用 虚函数（virtual function），运行时会根据对象 真实类型 来决定调用哪个函数，这就叫动态绑定
    实现方法：靠 虚函数表（vtable） 和 虚表指针（vptr）。
        ✔ 每个包含虚函数的类都有一个 vtable（虚表）
        ✔ 每个对象内部隐藏一个 vptr，指向该类的虚表
        ✔ 调用虚函数时，通过 vptr 找到对应类的方法

        Base object:
            [vptr] ---> Base::vtable ---> foo: Base::foo

        Derived object:
            [vptr] ---> Derived::vtable ---> foo: Derived::foo

*/

//只要类中有 virtual 函数，就应该将析构函数设为 virtual。下面的Base1的dtor不是虚函数，后面可能会造成内存泄漏

class Base1 {
public:
    virtual void foo() {
        cout << "Base foo\n";
    }
};

class Derived1 : public Base1 {
public:
    void foo() override {
        cout << "Derived foo\n";
    }

    void newcreate(){
        cout << "newcreat\n";
    }
};

class Base2 {
public:
    void foo() {
        cout << "Base foo\n";
    }
};

class Derived2 : public Base2 {
public:
    void foo() {
        cout << "Derived foo\n";
    }
};

class Animal {
public:
    virtual void speak() {
        cout << "Animal sound\n";
    }
    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    void speak() override {
        cout << "Dog: Woof!\n";
    }
};

class Cat : public Animal {
public:
    void speak() override {
        cout << "Cat: Meow!\n";
    }
};

class A{
public:
    virtual void f() final {}//final 不允许在之后的派生类中再重定义
};

class B final : public A{ //final 不允许继承

};

int main() {
    Base1* p1 = new Derived1();
    p1->foo();   //动态绑定 输出：Derived foo
    //p1->newcreate(); error p1只能访问A的成员 
    //安全方法：
    Derived1* q=dynamic_cast<Derived1*>(p1);
    if(q!=nullptr) q->newcreate();//如果p1指向的不是Derived1类对象，q为空
    delete p1;
    Base2* p2 = new Derived2();
    p2->foo();   //静态绑定 输出：Base foo
    delete p2;
    Base1 b=Derived1();
    b.foo();   //静态绑定 输出：Base foo
    cout << endl;
    Animal* a1 = new Dog();
    Animal* a2 = new Cat();
    a1->speak();   // Dog
    a2->speak();   // Cat
    delete a1;
    delete a2;
}

/*
    对虚函数几点说明
        只有类的成员函数才可以是虚函数，但静态成员函数不能是虚函数。
        构造函数不能是虚函数，析构函数可以（往往）是虚函数。
        只要在基类中说明了虚函数，在派生类、派生类的派生类、...中，与基类同型构的成员函数都是虚函数（virtual可以不写）。
        只有通过基类的指针或引用访问基类的虚函数时才进行动态绑定。
        基类的构造函数和析构函数中对虚函数的调用不进行动态绑定。
*/
