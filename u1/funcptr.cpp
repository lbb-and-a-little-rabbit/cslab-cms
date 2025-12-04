#include <bits/stdc++.h>

using namespace std;
using FUNC=int (*)(int,int);

//函数指针
//return_type (*fp)(params) = 函数名;

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int (*fp)(int,int)=add;

FUNC funcptr=add;

int (*op[2])(int,int)={add,sub};

void run(void (*func)()){
    func();
}

void test(){
    cout << "hello World\n";
}

int main(){
    int r1=fp(1,2);
    int r2=(*fp)(1,2);
    cout << r1 << ' ' << r2 << '\n';// 3 3 
    cout << funcptr(3,4) << ' ' << (*funcptr)(3,4) << '\n';// 7 7
    cout << op[0](5,6) << ' ' << (*op[1])(5,6) << '\n';//11 -1
    void (*f)()=test;
    run(f);// "hello World"
}