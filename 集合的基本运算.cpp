//C++ 20, CLion 2020.1.2 编译通过, 个人测试样例通过
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> A; //不定长数组表示集合A
    vector<int> B;
    vector<int> C;
    int element_a; //A中元素
    int element_b;

    //输入集合A
    cout << "请输入集合A中的元素，回车结束" << endl;
    while (cin >> element_a) {
        A.push_back(element_a);
        if (cin.peek() == '\n')
            break;
    }
    //回显集合A
    cout << "你输入的集合A是：" << endl;
    for (int i : A) {
        cout << i << ' ';
    }
    cout << endl;

    //输入集合B
    cout << "请输入集合B中的元素，回车结束" << endl;
    while (cin >> element_b) {
        B.push_back(element_b);
        if (cin.peek() == '\n')
            break;
    }
    //回显集合B
    cout << "你输入的集合B是：" << endl;
    for (int i : B) {
        cout << i << ' ';
    }
    cout << endl;

    //交集：循环比较A与B中每个元素，相等则放入集合C
    for (int i : A) {
        for (int j : B) {
            if (i == j)
                C.push_back(i);
        }
    }
    //输出交集
    cout << "A与B的交集是：" << endl;
    for (int i : C) {
        cout << i << ' ';
    }
    cout << endl;

    C.clear();//清空集合C

    //并集：A→C，然后C中的元素在B中已有则不管，没有则添加
    C.assign(A.begin(), A.end()); //集合A复制到集合C

    for (int i : B) {
        for (int j = 0; j < C.size(); j++) {
            if (i == C[j])
                break;
            else if (j == C.size() - 1)
                C.push_back(i);
        }
    }
    //输出并集
    cout << "A与B的并集是：" << endl;
    for (int i : C) {
        cout << i << ' ';
    }
    cout << endl;

    C.clear();

    //差集：A→C，然后C中存在B的元素则删除
    C.assign(A.begin(), A.end());

    for (int i : B) {
        for (int j = 0; j < C.size(); j++) {
            if (i == C[j])
                C.erase(C.begin() + j); //从集合C中移除存在的B中元素
        }
    }
    //输出差集
    cout << "A与B的差集是：" << endl;
    for (int i : C) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}