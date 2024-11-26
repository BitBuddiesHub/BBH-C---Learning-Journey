#include <iostream>
#include <array>
#include <vector>
#include <algorithm> // 包含 sort, find 等 STL 算法

using namespace std;

int main() {
    // ------------------ 1. 使用 std::array ------------------
    array<int, 5> arr = {10, 20, 30, 40, 50};

    cout << "1. std::array 内容: ";
    for (const auto& val : arr) {
        cout << val << " ";
    }
    cout << endl;

    cout << "std::array 大小: " << arr.size() << endl;

    sort(arr.begin(), arr.end());
    cout << "排序后的 std::array: ";
    for (const auto& val : arr) {
        cout << val << " ";
    }
    cout << endl;

    arr[2] = 100;
    cout << "修改后的 std::array: ";
    for (const auto& val : arr) {
        cout << val << " ";
    }
    cout << endl;

    // ------------------ 2. 使用 std::vector ------------------
    vector<int> vec = {10, 20, 30, 40, 50};
    vec.push_back(60);
    vec.push_back(70);

    cout << "2. std::vector 内容: ";
    for (const auto& val : vec) {
        cout << val << " ";
    }
    cout << endl;

    vec.pop_back();
    cout << "删除最后一个元素后: ";
    for (const auto& val : vec) {
        cout << val << " ";
    }
    cout << endl;

    vec.insert(vec.begin() + 2, 100);
    cout << "插入元素后的 std::vector: ";
    for (const auto& val : vec) {
        cout << val << " ";
    }
    cout << endl;

    vec.erase(vec.begin() + 2);
    cout << "删除指定元素后的 std::vector: ";
    for (const auto& val : vec) {
        cout << val << " ";
    }
    cout << endl;

    auto it = find(vec.begin(), vec.end(), 40);
    if (it != vec.end()) {
        cout << "找到元素 40，索引: " << distance(vec.begin(), it) << endl;
    } else {
        cout << "未找到元素 40" << endl;
    }

    // ------------------ 3. 动态二维数组 ------------------
    vector<vector<int>> matrix(3, vector<int>(3, 0));
    int value = 1;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matrix[i][j] = value++;
        }
    }

    cout << "3. 二维数组内容:" << endl;
    for (const auto& row : matrix) {
        for (const auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    matrix.push_back({10, 20, 30});
    cout << "添加新行后的二维数组:" << endl;
    for (const auto& row : matrix) {
        for (const auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
