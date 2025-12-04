#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    T data[100];
    int top;
public:
    Stack() : top(0) {}
    void push(T val) { data[top++] = val; }
    T pop() { return data[--top]; }
    bool empty() { return top == 0; }
};

int main() {
    Stack<int> s1;
    s1.push(10);
    cout << s1.pop() << endl;

    Stack<double> s2;
    s2.push(3.14);
    cout << s2.pop() << endl;
}

//多个类型参数
template <typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;
};

Pair<int,double> pr;

//非类型参数
template <typename T, int size>
class Array {
    T data[size];
};

Array<int,3> arr;