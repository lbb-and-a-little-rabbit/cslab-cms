#include <iostream>
#include <vector>
#include <numeric>   // accumulate
#include <algorithm> // sort, find, transform

using namespace std;

int main() {
    // =========================
    // 示例 1：累加求和
    // =========================
    vector<int> v1 = {1, 2, 3, 4, 5};
    int sum = accumulate(v1.begin(), v1.end(), 0); // 求和
    cout << "示例 1 - sum = " << sum << endl;     // 输出: 15

    // =========================
    // 示例 2：排序和查找
    // =========================
    vector<int> v2 = {5, 3, 1, 4, 2};
    
    // 排序
    sort(v2.begin(), v2.end());
    cout << "示例 2 - sorted: ";
    for(auto x : v2) cout << x << " "; // 输出: 1 2 3 4 5
    cout << endl;

    // 查找元素 3
    auto it = find(v2.begin(), v2.end(), 3);
    if(it != v2.end())
        cout << "示例 2 - Found 3 at index " << distance(v2.begin(), it) << endl;

    // =========================
    // 示例 3：函数式 transform（平方操作）
    // =========================
    vector<int> v3 = {1, 2, 3, 4, 5};
    vector<int> res(v3.size());

    transform(v3.begin(), v3.end(), res.begin(), [](int x){ return x * x; });
    cout << "示例 3 - squared: ";
    for(auto x : res) cout << x << " "; // 输出: 1 4 9 16 25
    cout << endl;

    return 0;
}
