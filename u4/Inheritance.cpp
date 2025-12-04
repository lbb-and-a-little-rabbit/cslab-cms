#include <bits/stdc++.h>

using namespace std;

/*
    继承方式	基类 public	基类 protected	基类 private
    public	    public	    protected	    不可访问
    protected	protected	protected	    不可访问
    private	    private	    private	        不可访问
*/

//基本语法
class Base {
protected:
    int x=10;

public:
    Base() { cout << "Base ctor\n"; }

    Base(int x) : x(x) { cout << "Base ctor with x\n"; }

    virtual ~Base() { cout << "Base dtor\n"; }//一定要加virtual

    void show() { cout << "Base show\n"; }

    virtual void foo() {
        cout << "Base foo\n";
    }

    void Print(){
        cout << x << '\n';
    }
};

class Derived : public Base {   // public 继承
public:
    Derived() { cout << "Derived ctor\n"; }

    Derived(int x) : Base(x) { cout << "Derived ctor with x\n"; }

    ~Derived() { cout << "Derived dtor\n"; }

    void display() { cout << "Derived display\n"; }

    void foo() override {      // override 可选但强烈推荐
        cout << "Derived foo\n";
    }
};

int main(){
    /*
        构造顺序：基类 → 派生类
        析构顺序：派生类 → 基类
    */
{
    Derived dx(5);
    dx.Print(); // 5
}  
    Derived d;
    d.Print(); // 10
    //d.x=1; error protectd在外部不可访问
    Base* p = new Derived();   // 指向派生类对象
    p->foo();                  // 调用 Derived::foo（多态）
    delete p;
}