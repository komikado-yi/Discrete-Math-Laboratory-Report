//
// Created by 李若昊 on 7/8/20.
//
//C++ 20, CLion 2020.1.2 编译通过, 个人测试样例通过
#include <iostream>

using namespace std;

int main() {
    int dim; //方阵行(列)数
    cout << "请输入矩阵维数，按回车确认" << endl;
    cin >> dim;
    int r[dim][dim]; //定义关系方阵R

    cout << "请按从左到右从上到下的顺序依次输入矩阵元素，以空格键隔开" << endl;
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            cin >> r[i][j];
        }
    }

    cout << "你输入的矩阵是：" << endl; //回显确认
    int newLine = 0;
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            cout << r[i][j] << ' ';
            newLine++;
            if (newLine % dim == 0)
                cout << endl;
        }
    }

    //自反性
    int Reflexive = 1;//0代表无1代表有
    for (int i = 0; i < dim; i++) {
        if (r[i][i] != 1)
            Reflexive = 0;
    }
    if (Reflexive == 1)
        cout << "关系矩阵具有自反性" << endl;
    else
        cout << "关系矩阵不具有自反性" << endl;

    //反自反性
    int anti_Reflexive = 1;
    for (int i = 0; i < dim; i++) {
        if (r[i][i] == 1)
            anti_Reflexive = 0;
    }
    if (anti_Reflexive == 1)
        cout << "关系矩阵具有反自反性" << endl;
    else
        cout << "关系矩阵不具有反自反性" << endl;

    //对称性
    int Symmetric = 1;
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if (r[i][j] != r[j][i])
                Symmetric = 0;
        }
    }
    if (Symmetric == 1)
        cout << "关系矩阵具有对称性" << endl;
    else
        cout << "关系矩阵不具有对称性" << endl;

    //反对称性
    int anti_Symmetric = 1;
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if (i != j && r[i][j] * r[j][i] != 0)
                anti_Symmetric = 0;
        }
    }
    if (anti_Symmetric == 1)
        cout << "关系矩阵具有反对称性" << endl;
    else
        cout << "关系矩阵不具有反对称性" << endl;

    //传递性
    int Transitive = 1;
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            for (int k = 0; k < dim; k++) {
                if (r[i][j] == 1 && r[j][k] == 1) {
                    if (r[i][k] == 0)
                        Transitive = 0;
                }
            }
        }
    }
    if (Transitive == 1)
        cout << "关系矩阵具有传递性" << endl;
    else
        cout << "关系矩阵不具有传递性" << endl;

    return 0;
}
