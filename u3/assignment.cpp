#include <iostream>
#include <cstring>

using namespace std;

/*
    一般来讲，需要自定义拷贝构造函数的类通常也需要自定义赋值操作符重载函数。 
        注意：要区别下面两个“=”的不同含义。
        A a;
        A b=a; //初始化，等价于：A b(a);，调用拷贝构造函数。
        ......
        b = a; //赋值，调用赋值操作符重载函数。

*/

class String {
private:
    char* data;

public:
    // 构造
    String(const char* s = "") {
        data = new char[strlen(s) + 1];
        strcpy(data, s);
    }

    // 析构
    ~String() {
        delete[] data;
    }

    // 拷贝赋值
    String& operator=(const String& other) {
        std::cout << "Copy assignment\n";
        if (this != &other) {//防止自赋值！！！
            delete[] data; // 释放资源
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
        }
        return *this;
    }

    // 移动赋值
    String& operator=(String&& other) noexcept {
        std::cout << "Move assignment\n";
        if (this != &other) {
            delete[] data; // 释放旧资源  PS：对 delete 和 delete[]，如果传入的是 nullptr，不会做任何事，也不会报错。
            data = other.data; // 盗取资源
            other.data = nullptr; // 防止 double free
        }
        return *this;
    }

    void print() const {
        std::cout << (data ? data : "(null)") << '\n';
    }
};

int main() {
    String a("hello");
    String b("world");

    b = a;          // 拷贝赋值
    b.print();

    b = String("temp"); // 移动赋值（右值）
    b.print();
}