#include <iostream>
using namespace std;

template <typename T>   // 或 template<class T>
T Max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << Max(3, 7) << endl;      // int
    cout << Max(3.5, 2.1) << endl;  // double
}
