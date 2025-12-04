#include <iostream>
using namespace std;

double divide(int a, int b) {
    if (b == 0) throw runtime_error("除数不能为 0");
    return double(a) / b;
}

int main() {
    int x,y;
    cin >> x >> y;
    try {
        cout << divide(x, y) << endl;
    }
    catch (runtime_error &e) {
        cout << "捕获异常：" << e.what() << endl;
    }
}
