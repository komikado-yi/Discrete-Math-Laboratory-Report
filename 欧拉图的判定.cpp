//
// Created by 李若昊 on 7/8/20.
//
// C++ 20, CLion 2020.1.2 编译通过, 个人测试样例通过

#include <iostream>

using namespace std;

int main() {
    int dim; //关系矩阵行(列)数
    cout << "请输入矩阵维数，回车确认" << endl;
    cin >> dim;
    int r[dim][dim]; //关系矩阵定义

    //输入关系矩阵
    cout << "请按从左到右从上至下依次输入矩阵元素，以空格隔开，回车结束输入" << endl;
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            cin >> r[i][j];
        }
    }
    //矩阵回显
    cout << "你输入的矩阵是：" << endl;
    int new_row = 0;
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            new_row++;
            cout << r[i][j] << " ";
            if (new_row % dim == 0)
                cout << endl;
        }
    }

    //判断无向图是否是欧拉图
    int no_dir_graph = 1;
    int deg;
    for (int i = 0; i < dim; i++) {
        deg = 0;
        for (int j = 0; j < dim; j++) {
            if (r[i][j])
                deg++; //某顶点的度是第i行(列)所有非零元的个数
        }
        if (deg % 2 == 1)
            no_dir_graph = 0;
    }

    if (no_dir_graph == 1)
        cout << "无向图是欧拉图" << endl;
    else
        cout << "无向图不是欧拉图" << endl;

    //判断有向图是否是欧拉图
    int dir_graph = 1;
    int point_to_i = 0;
    int out_from_i = 0;
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if (r[j][i])
                point_to_i++; //某顶点的入度是第i列所有非零元的个数
            if (r[i][j])
                out_from_i++; //某顶点的出度是第i行所有非零元的个数
        }
        if (point_to_i != out_from_i)
            dir_graph = 0;
    }

    if (dir_graph == 1)
        cout << "有向图是欧拉图" << endl;
    else
        cout << "有向图不是欧拉图" << endl;

    return 0;
}
