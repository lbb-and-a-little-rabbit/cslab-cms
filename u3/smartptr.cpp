#include <iostream>
using namespace std;

//->和*的重载实现的unique_ptr

template<typename T>
class SmartPtr {
public:
    // 构造函数：接管原始指针
    explicit SmartPtr(T* ptr = nullptr)
        : ptr_(ptr) {}

    // 析构：自动释放
    ~SmartPtr() {
        delete ptr_;
    }

    // 禁止拷贝（模仿 unique_ptr 行为）
    SmartPtr(const SmartPtr&) = delete;
    SmartPtr& operator=(const SmartPtr&) = delete;

    // 移动构造
    SmartPtr(SmartPtr&& other) noexcept {
        ptr_ = other.ptr_;
        other.ptr_ = nullptr;
    }

    // 移动赋值
    SmartPtr& operator=(SmartPtr&& other) noexcept {
        if (this != &other) {
            delete ptr_;
            ptr_ = other.ptr_;
            other.ptr_ = nullptr;
        }
        return *this;
    }

    // 重载 * 运算符：返回引用
    T& operator*() const {
        return *ptr_;
    }

    // 重载 -> 运算符：返回指针
    T* operator->() const {
        return ptr_;
    }

private:
    T* ptr_;
};

// ------------------------
// 测试用的类
// ------------------------
class Foo {
public:
    Foo(int v) : value(v) {}
    void show() {
        cout << "value = " << value << endl;
    }
private:
    int value;
};

int main() {
    SmartPtr<Foo> p(new Foo(42));

    // 使用 -> 访问对象成员
    p->show();

    // 使用 * 解引用
    (*p).show();

    return 0;
}
