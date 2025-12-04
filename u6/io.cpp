#include <iostream>
using namespace std;

class Point {
private:
    int x, y;

public:
    Point(int a=0, int b=0) : x(a), y(b) {}

    // 输出重载（友元函数）
    friend ostream& operator<<(ostream& out, const Point& p) {
        out << "(" << p.x << "," << p.y << ")";
        return out;
    }

    // 输入重载（友元函数）
    friend istream& operator>>(istream& in, Point& p) {
        in >> p.x >> p.y;
        return in;
    }
};

int main() {
    Point p1;
    cout << "请输入点的坐标 (x y): ";
    cin >> p1;          // 使用 >> 重载
    cout << "你输入的点是: " << p1 << endl;  // 使用 << 重载
}
