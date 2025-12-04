#include <fstream>
#include <iostream>
using namespace std;

int main() {
    fstream file("f_stream_data.txt", ios::in | ios::out | ios::app); // 可读写并追加
    if (!file) {
        cerr << "文件打开失败" << endl;
        return 1;
    }

    file << "追加一行文本\n";

    file.seekg(0);  // 回到文件开头读取
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}
