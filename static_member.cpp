#include <bits/stdc++.h>

using namespace std;

class A {
public:
    //静态成员变量
    static int count;   // 静态成员变量声明  
    /*
        属于类，不属于对象
        所有对象共享同一份内存
    */

    A(){ count++; }

    //静态成员函数
    static int add(int a,int b){
        return a+b;  //没有this指针，不能访问非静态成员，只能访问静态成员
    }
};

int A::count=0; //⚠ 注意：静态成员变量必须在类外定义，否则链接错误。

int main(){
    A a1,a2,a3;
    cout << A::count << endl;// 3
    cout << A::add(3,4);//7
}