#include <iostream>
#include <memory>
using namespace std;

class Foo {
public:
    Foo(int v) : value(v) {
        cout << "Foo(" << value << ") constructed\n";
    }
    ~Foo() {
        cout << "Foo(" << value << ") destroyed\n";
    }
    void show() {
        cout << "Foo value = " << value << endl;
    }
private:
    int value;
};

int main() {
    // -----------------------------
    // 1. unique_ptr —— 独占所有权
    // -----------------------------
    unique_ptr<Foo> up1 = make_unique<Foo>(1);  // 自动构造
    up1->show();

    // unique_ptr 独占资源，不能复制：
    // unique_ptr<Foo> up2 = up1; // ❌ 编译错误

    // 但可以移动所有权：
    unique_ptr<Foo> up2 = move(up1); // up1 被置空
    if (!up1) cout << "up1 is now null after move\n";
    up2->show();                     // 资源现在由 up2 管理

    // -----------------------------
    // 2. shared_ptr —— 共享所有权
    // -----------------------------
    shared_ptr<Foo> sp1 = make_shared<Foo>(2);
    cout << "sp1 count = " << sp1.use_count() << endl;

    {
        shared_ptr<Foo> sp2 = sp1;   // 引用计数 +1
        cout << "sp1 count = " << sp1.use_count() << endl;
        sp2->show();
    }                                // sp2 离开作用域，引用计数 -1

    cout << "sp1 count after sp2 destroyed = " << sp1.use_count() << endl;

    // -----------------------------
    // 3. weak_ptr —— 弱引用，不增加计数
    // -----------------------------
    weak_ptr<Foo> wp = sp1;          // 不增加引用计数
    cout << "sp1 count (with weak_ptr) = " << sp1.use_count() << endl;

    if (auto locked = wp.lock()) {   // 尝试提升为 shared_ptr
        cout << "weak_ptr locked successfully\n";
        locked->show();
    }

    // 当 shared_ptr 全部析构后，weak_ptr 会指向过期对象
    sp1.reset();   // 手动释放资源
    cout << "sp1 reset\n";

    if (wp.expired()) {
        cout << "weak_ptr is expired\n";
    }

    return 0;
}
