#include <bits/stdc++.h>

using namespace std;

int main(){
    int x;
    cin >> x;
    try {
        // 可能抛出异常的代码
        if(x)
            throw 10;  // 抛出异常
        else 
            throw "114514";
    }
    catch (int e) {
        // 捕获异常
        std::cout << "捕获到 int 异常：" << e << std::endl;
    }
    catch (...) {
        // 捕获其他所有异常
        std::cout << "捕获到未知异常" << std::endl;
    }
}