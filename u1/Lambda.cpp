#include <bits/stdc++.h>

using namespace std;

/*
    [capture](params) -> return_type {
        body;
    };
    return_type可省
*/

//示例：
auto example = [](){ 
    cout << "Hello Lambda"; 
};

auto add = [](int a, int b) {
    return a + b;
};

auto maxValue = [](int a, int b){
    return a > b ? a : b;
};

auto divide = [](double a, double b) -> double {
    return a / b;
};

int main(){
    //值捕获
    int x = 10;
    auto f = [x]() {
        cout << x << '\n';
    };
    f(); // 输出 10
    x = 99;
    f(); // 仍然输出 10

    //引用捕获
    auto g = [&x](){
        cout << x << '\n';
    };
    g();//输出 99
    x = 10;
    g();//输出 10

    //全部值捕获
    int y=1,z=2;
    auto func1 = [x,y,z](){
        cout << x << ' ' << y << ' ' << z << '\n';
    };
    auto func2 = [=](){
        cout << x << ' ' << y << ' ' << z << '\n';
    };
    func1();// 10 1 2
    func2();// 10 1 2

    //全部引用捕获
    auto func3 = [&](){
        cout << x << ' ' << y << ' ' << z << '\n';
    };
    func3();// 10 1 2
    x=y=z=1;
    func3();// 1 1 1

    //混合捕获
    auto func4 = [=,&x](){
        cout << x << ' ' << y << ' ' << z << '\n';
    };
    func4();// 1 1 1
    x=y=z=2;
    func4();// 2 1 1

    //应用：作为 STL 回调
    vector<int> v{3,2,1};
    sort(v.begin(),v.end(),[](int a,int b){
        return a<b;
    });

    for(int i=0;i<v.size();i++){
        cout << v[i] << ' ';
    }
    cout << '\n';// 1 2 3
    for_each(v.begin(),v.end(),[](int x){
        cout << x << ' ';
    });
    cout << '\n';// 1 2 3

    //在容器中找到第一个满足条件的元素
    auto it=find_if(v.begin(),v.end(),[](int x){
        return x>2;
    });
    cout << *it << '\n';// 3

    //可变lambda
    auto func5 = [x](){
        //x++; error!
        cout << x << '\n';
    };
    auto func6 = [x]() mutable {
        x++;
        cout << x << '\n';
    };//mutable 只会让 lambda 内“自己那份副本”可修改，不会影响外部原始变量。
    func5();// 2
    func6();// 3
    cout << x << '\n';// 2

    //存入sts::function
    //std::function<返回类型(参数类型...)>
    std::function<int(int, int)> Add = [](int a, int b){
        return a + b;
    };

    cout << Add(3, 4);  // 输出 7
}

