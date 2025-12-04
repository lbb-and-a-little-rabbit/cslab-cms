#include <bits/stdc++.h>

using namespace std;

//普通递归
int factorial_normal(int n) {
    if (n == 0) return 1;
    return n * factorial_normal(n-1);  // 乘法在返回时执行 → 非尾递归
}

//尾递归
int factorialHelper(int n, int acc) {
    if (n == 0) return acc;
    return factorialHelper(n-1, n*acc);  // 递归调用是最后一步
}

int factorial(int n) {
    return factorialHelper(n, 1);
}

int fibTail(int n, int a=0, int b=1) {
    if (n == 0) return a;
    return fibTail(n-1, b, a+b);
}

int main() {
    cout << fibTail(10) << endl; // 输出: 55
    cout << factorial(4) << endl; // 输出: 24 
}

/*
    尾递归 = 递归调用在函数最后一步，不做额外操作

    优势：节省栈空间、防止栈溢出

    通过 累积参数（accumulator） 实现

    C++ 编译器可优化成循环，提高性能

    由于递归调用回来不再做其它事，从而不会再使用递归调用前的栈空间的内容，因此，递归调用时不必额外为它分配栈空间，可直接使用（复用）当前的栈空间。
    可以自动转成迭代。
*/
