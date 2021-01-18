//
// Created by 李若昊 on 7/8/20.
//
//C++ 20, CLion 2020.1.2 编译通过, 个人测试样例通过
#include <iostream>
#include <string>

using namespace std;

//p,q的否定
void negative(int p, int q) {
    cout << "p的否定是" << !p << "，q的否定是" << !q << endl;
}

//两者的合取
void Conjunction(int p, int q) {
    if (p == q == 1) {
        cout << "p, q的合取是真" << endl;
    } else {
        cout << "p, q的合取是假" << endl;
    }
}

//两者的析取
void Disjunctive(int p, int q) {
    if (p == 0 == q == 0) {
        cout << "p, q的析取是假" << endl;
    } else {
        cout << "p, q的析取是真" << endl;
    }
}

//p蕴含q吗
void imp(int p, int q) {
    if (p == 1 && q == 0) {
        cout << "p不蕴含q" << endl;
    } else {
        cout << "p蕴含q" << endl;
    }
}

//p, q等值吗
void Equivalence(int p, int q) {
    if (p == 1 == q == 1 || p == 0 == q == 0) {
        cout << "p和q等值" << endl;
    } else {
        cout << "p和q不等值" << endl;
    }
}

int main() {
    start:
    int p = 0, q = 0; //两个命题的真值，真为1，假为0
    string input;

    cin >> p >> q; //从键盘输入两个真值

    negative(p, q);
    Conjunction(p, q);
    Disjunctive(p, q);
    imp(p, q);
    Equivalence(p, q);

    //出结果后输exit才可退出程序，否则再来一次
    cout << "继续请输start again，结束请输exit" << endl;
    cin >> input;
    if (input != "exit") {
        goto start;
    }

    return 0;
}
