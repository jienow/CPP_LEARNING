//
// Created by jienow on 2022/9/10.
//

#include <iomanip>
#include "../include/ju_zhen.h"


vector<vector<int>> ju_zhen::init_read(string file) {
    fstream ofs;
    ofs.open(/*"/home/jienow/Development/CPP_DEVELOPMENT/CPP_LEARNING/new_cpp02/learn14/shuju/" +*/
            file,
            ios::in);
    if (!ofs.is_open()) {
        cout << "文件没有打开" << endl;
        exit(-2);
    }

    vector<vector<int>> mat;
    stringstream ss;
    string str;
    while (getline(ofs, str)) {
        ss << str;
        int number;
        vector<int> v;
        while (ss >> number) {
            v.push_back(number);
        }
        mat.push_back(v);
        ss.clear();
    }
    ofs.close();
    return mat;
}

int ju_zhen::fu_hao(int x, int y) { return pow(-1, x + y); }

int ju_zhen::dai_shu_yu_zi_shi(vector<vector<int>> &mat, int x, int y) {
    vector<vector<int>> tmp;
    for (int i = 0; i < mat.size(); i++) {
        if (i == x)
            continue;
        vector<int> v;
        for (int j = 0; j < mat.size(); j++) {
            if (j == y)
                continue;
            v.push_back(mat[i][j]);
        }
        tmp.push_back(v);
    }

    // debug -----------------

    // auto ans = calcul(tmp, 0, 0, (int) tmp.size() - 1, (int) tmp.size() - 1);
//    auto ans =
//    cout << "x" << x << "   y" << y << "  ans:" << ans << endl;
//    for (auto &a: tmp) {
//        for (auto b: a)
//            cout << b << " ";
//        cout << endl;
//    }
//
//    return ans;
    // debug end -----------------

    return calcul(tmp, 0, 0, (int) tmp.size() - 1, (int) tmp.size() - 1);
}

int ju_zhen::yu_zi_shi(vector<vector<int>> &mat, int x, int y) {
    return mat[x][y] * fu_hao(x, y) * dai_shu_yu_zi_shi(mat, x, y);
}


int ju_zhen::calcul(vector<vector<int>> &mat, int x1, int y1, int x2, int y2) {
    int res = 0;
    if (x1 == x2)
        return mat[0][0];
    if (x2 - x1 == 1) {
        return mat[x2][y2] * mat[x1][y1] - mat[x2][y1] * mat[x1][y2];
    } else {
        for (int i = 0; i < mat.size(); i++) {
            res += yu_zi_shi(mat, 0, i);
        }
    }
    return res;
}

int ju_zhen::ju_zhen_ji_suan(vector<vector<int>> &v) {
    return this->calcul(v, 0, 0, v.size(), v.size());
}

vector<vector<double>> ju_zhen::ban_sui_ju_zhen(vector<vector<int>> &v) {
    vector<vector<double>> ans{v.size(), vector<double>(v.size(), 0.0)};
    for (int i = 0; i < v.size(); i++)
        for (int j = 0; j < v[0].size(); j++)
            ans[i][j] = (double) dai_shu_yu_zi_shi_not_mat_x_y(v, i, j);
    return ans;
}

void ju_zhen::number_mult_ju_zhen(vector<vector<double>> &v, double val) {
    for (auto &a: v)
        for (auto &i: a)
            i *= val;
}

void ju_zhen::zhuan_zhi(vector<vector<double>> &v) {
    for (int i = 0; i < v.size(); i++)
        for (int j = 0; j < i; j++) {
            auto tmp = v[i][j];
            v[i][j] = v[j][i];
            v[j][i] = tmp;
        }
}

int ju_zhen::dai_shu_yu_zi_shi_not_mat_x_y(vector<vector<int>> &mat, int x, int y) {
    return fu_hao(x, y) * dai_shu_yu_zi_shi(mat, x, y);
}

void ju_zhen::print_ju_zhen(vector<vector<double>> &v) {
    for (auto &hang: v) {
        for (auto &val: hang)
            cout << setw(4) << internal << val << setw(4)<< "  ";
        cout << endl;
    }
}


