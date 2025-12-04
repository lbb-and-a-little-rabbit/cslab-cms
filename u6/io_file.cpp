#include <fstream>
#include <iostream>
using namespace std;

/*
    模式	        描述
    ios::in	    读模式（默认 for ifstream）
    ios::out	写模式（默认 for ofstream）
    ios::app	追加模式，在文件末尾写
    ios::ate	打开后定位到文件末尾
    ios::trunc	打开文件前清空文件内容
    ios::binary	二进制模式
*/

int main() {
    ofstream outFile("data.txt",ios::out | ios::app);  // 打开文件写入，如果不存在则创建
    if (!outFile) {
        cerr << "打开文件失败" << endl;
        return 1;
    }
    
    outFile << "Hello,File!";
    outFile.close();  // 关闭文件

    ifstream inFile("data.txt");   // 打开文件读取
    string s;
    inFile >> s;                    // 读取单词
    cout << "读取内容: " << s << endl;
    inFile.close();

    return 0;
}
