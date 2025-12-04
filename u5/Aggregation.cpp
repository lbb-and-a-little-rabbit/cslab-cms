#include <bits/stdc++.h>

using namespace std;
/*
    聚合（Aggregation）——“弱拥有”关系
    含义：整体依赖部分，但部分不归整体管理

    部分可以 独立存在

    生命周期 不绑定

    整体只是 引用、指针 形式存储部分

    部分不由整体创建或销毁
*/
class Wheel {
public:
    Wheel() { cout << "Wheel created\n"; }
    ~Wheel() { cout << "Wheel destroyed\n"; }
};

class Car {
private:
    Wheel* wheel;  // Car 只聚合 Wheel，不拥有它

public:
    Car(Wheel* w) : wheel(w) {}
};

int main() {
    Wheel w;       // w 独立创建
    Car c(&w);     // c 使用 w（聚合）
}

/*
    继承更容易实现子类型：
        在C++中，public继承的派生类往往可以看成是基类的子类型。
        在需要基类对象的地方可以用派生类对象去替代。
        发给基类对象的消息也能发给派生类对象。
    具有聚合/组合关系的两个类不具有子类型关系！ 
*/

