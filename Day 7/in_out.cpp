#include <iostream>
#include <fstream>   // 包含文件输入输出所需的库
#include <string>

using namespace std;

int main() {
    // 1. 文件输出（写入文件）
    ofstream outFile("example.txt");  // 打开一个文件进行写操作，如果文件不存在会自动创建

    if (!outFile) { // 检查文件是否成功打开
        cerr << "Error opening file for writing!" << endl;
        return 1; // 返回错误码
    }

    // 向文件写入一些内容
    outFile << "Hello, world!" << endl;
    outFile << "This is a C++ file input/output example." << endl;
    outFile << "Writing multiple lines into the file." << endl;

    outFile.close(); // 关闭文件
    cout << "Data written to file successfully." << endl;

    // 2. 文件输入（读取文件）
    ifstream inFile("example.txt");  // 打开一个文件进行读操作

    if (!inFile) { // 检查文件是否成功打开
        cerr << "Error opening file for reading!" << endl;
        return 1; // 返回错误码
    }

    cout << "\nReading data from file:" << endl;
    string line;
    while (getline(inFile, line)) { // 按行读取文件内容
        cout << line << endl;       // 输出每一行
    }

    inFile.close(); // 关闭文件
    return 0;
}
