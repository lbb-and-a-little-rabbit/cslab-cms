#include <bits/stdc++.h>

using namespace std;

//语法：返回类型 operator符号(参数列表)

class Vec2 {
public:
    int x, y;

    //explicit 防止强制类型转化(int->Vec2)
    explicit Vec2(int x) : x(x),y(0) {}
    Vec2(int x,int y) : x(x),y(y) {}

    //成员函数重载（最常用）
    Vec2 operator+(const Vec2& other) const {//隐藏了一个this
        return Vec2(x + other.x, y + other.y);
    }

    Vec2& operator=(const Vec2& other) {
        if (this != &other) {//防止自赋值
            x = other.x;
            y = other.y;
        }
        return *this;
    }

    bool operator==(const Vec2& other) const {
        return x == other.x && y == other.y;
    }

    int& operator[](int index) {
        return (index == 0 ? x : y);
    }

    //类型转换
    operator int(){
        return x;
    }

    //前置++
    Vec2& operator++() {
        x++; y++;
        return *this;
    }

    //后置++
    Vec2 operator++(int) {
        Vec2 tmp(*this);
        x++; y++;
        return tmp;
    }

    //非成员 / 友元函数
    //friend Vec2 operator+(const Vec2& a, const Vec2& b);//这里同时重载了2个+，出现了二义性，只作示例，正常只留1个即可

    //必须用friend,因为左边是 ostream 对象（不是你的类）
    friend ostream& operator<<(ostream& os, const Vec2& v) {
        os << "(" << v.x << ", " << v.y << ")";
        return os;
    }

};

//Vec2 operator+(const Vec2& a, const Vec2& b) {
//    return Vec2(a.x + b.x, a.y + b.y);
//}

int main(){
    Vec2 v1(1,2);
    Vec2 v2(2,3);
    Vec2 v3=v1+v2;
    cout << v3 << '\n';
    cout << v1+2 << '\n';// 3
    ++(++v1);
    (++v1)++;
    cout << v1 << '\n';// (5, 6)
    ++(v1++); //如果写成const Vec2 operator++(int)则编译不通过
    (v1++)++; //如果写成const Vec2 operator++(int)则编译不通过
    cout << v1 << '\n';// (7, 8)
    int x=0;
    //(x++)++;//error
    //++(x++) error
    ++(++x);
    (++x)++;
    cout << x << '\n'; 
}


