#include <bits/stdc++.h>

using namespace std;
/*
    组合（Composition）——“强拥有”关系
    含义：A 负责创建/销毁 B，对象生命周期绑定

    部分（Part）属于整体（Whole）

    整体不存在 → 部分一定不能存在

    生命周期 严格绑定

    部分通常在构造函数初始化列表中创建

    整体析构时会自动销毁部分
*/

class Engine {
public:
    Engine() { cout << "Engine created\n"; }
    ~Engine() { cout << "Engine destroyed\n"; }
};

class Car {
private:
    Engine engine;  // Car 组合 Engine（Car 拥有 Engine）

public:
    Car() { cout << "Car created\n"; }
    ~Car() { cout << "Car destroyed\n"; }
};

int main() {
    Car c; // Car 构造 → Engine 构造
}         // Car 析构 → Engine 析构
        //上面两句不代表ctor,dtor调用顺序

/*
    输出结果：
    Engine created
    Car created
    Car destroyed
    Engine destroyed
*/

