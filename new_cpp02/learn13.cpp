//
// Created by jienow on 2022/9/10.
//

#include <iostream>
#include <memory>
#include <vector>
using namespace std;


unique_ptr<vector<vector<int>>> mo_vec() {
    unique_ptr<vector<vector<int>>> ptr{
        new vector<vector<int>>{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}};
    // auto a = ptr.release();

    // for (auto &v : (*ptr.get())) {
    //     for (auto i : v)
    //         cout << i << " ";
    //     cout << endl;
    // }

    return ptr;
}
//---------------------------------------------------------------------------
int main() {
    auto b = mo_vec();


    for (auto &v : (*b)) {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }

    vector<vector<int>> v1{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // int ju_zhen_dao_shu = calcul(v1) return 0;
}
