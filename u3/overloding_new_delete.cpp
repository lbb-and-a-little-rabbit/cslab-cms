#include <iostream>
#include <cstdlib>   // malloc/free

using namespace std;

class Foo {
public:
    int x;

    Foo(int v) : x(v) {
        cout << "Foo constructor\n";
    }

    ~Foo() {
        cout << "Foo destructor\n";
    }

    // -------------------------------
    // 重载 operator new（类级别）
    // -------------------------------
    void* operator new(size_t size) {
        cout << "[Foo::new] allocate " << size << " bytes\n";
        void* p = malloc(size);
        return p;
    }

    // -------------------------------
    // 重载 operator delete（类级别）
    // -------------------------------
    void operator delete(void* ptr) {
        cout << "[Foo::delete] free memory\n";
        free(ptr);
    }
};

int main() {
    Foo* p = new Foo(42);   // 使用类内定制的 operator new
    delete p;               // 使用类内定制的 operator delete
    return 0;
}
