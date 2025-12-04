#include <bits/stdc++.h>

using namespace std;

/*
    迭代器的类型

    STL 迭代器分为几类，每种支持的操作不同：

    类型	                        说明	                            支持操作
    Input Iterator	            只读，单向遍历	                        *it, ++it
    Output Iterator	            只写，单向遍历	                        *it = val, ++it
    Forward Iterator	        单向读写，可多次遍历	                上两者的结合
    Bidirectional Iterator	    可前后遍历	                            ++it, --it
    Random Access Iterator	    可随机访问	                            +, -, []，支持算术

    常用容器的迭代器类型：

    容器	                                迭代器类型
    vector, deque, array	            Random Access
    list, forward_list	                Bidirectional / Forward
    set, map	                        Bidirectional
*/

int main() {
    vector<int> v = {1, 2, 3, 4, 5};

    // 定义迭代器
    vector<int>::iterator it;

    // 遍历容器
    for(it = v.begin(); it != v.end(); ++it) {
        cout << *it << " "; // 输出元素
    }
    cout << endl;

    //下面这段代码等价于上面的代码，是通过迭代器实现的
    for(auto x : v) {
        cout << x << " ";
    }

    return 0;
}

/*
    常用迭代器操作

        获取迭代器

        auto it1 = v.begin();  // 指向第一个元素
        auto it2 = v.end();    // 指向容器末尾的下一个位置


        访问元素

        cout << *it1 << endl;   // 访问元素
        *it1 = 10;              // 修改元素（可写迭代器）


        移动迭代器

        ++it1;  // 前进
        --it2;  // 后退（双向或随机访问迭代器）
        it1 += 3; // 随机访问迭代器


        常量迭代器

        vector<int>::const_iterator cit = v.cbegin(); // 只读
*/