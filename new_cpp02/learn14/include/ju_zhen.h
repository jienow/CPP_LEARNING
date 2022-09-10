//
// Created by jienow on 2022/9/10.
//

#ifndef LEARN14_JU_ZHEN_H
#define LEARN14_JU_ZHEN_H

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class ju_zhen {
public:
    int ju_zhen_ji_suan(vector<vector<int>> &v);

    vector<vector<double>> ban_sui_ju_zhen(vector<vector<int>> &v);

    void number_mult_ju_zhen(vector<vector<double>> &v, double val);

    vector<vector<int>> init_read(string file);
private:

    int dai_shu_yu_zi_shi(vector<vector<int>> &mat, int x, int y);

    int calcul(vector<vector<int>> &mat, int x1, int y1, int x2, int y2);

    int fu_hao(int x, int y);



    int yu_zi_shi(vector<vector<int>> &mat, int x, int y);
};

#endif // LEARN14_JU_ZHEN_H
