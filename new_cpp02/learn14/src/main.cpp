#include <iostream>
#include "ju_zhen.h"
#include <iomanip>

int main(int argc, char *argv[]) {
//    vector<vector<int>> v{
//            {1,0,0,0},
//            {0,1,0,0},
//            {0,0,4,0},
//            {0,0,0,5}
//    };
//    if(v.empty()){
//        cout << "矩阵为空" << endl;
//        return -1;
//    }
    ju_zhen juZhen;


    if (argc == 1) {
        cout << "没有矩阵文件" << endl;
        return -1;
    }

    auto v = juZhen.init_read(string{argv[1]});

    double ju_zhen_dao_shu = 1.0 / juZhen.ju_zhen_ji_suan(v);
    auto ban_sui_ju_zhen = juZhen.ban_sui_ju_zhen(v);
    juZhen.number_mult_ju_zhen(ban_sui_ju_zhen, ju_zhen_dao_shu);
    for (auto &hang: ban_sui_ju_zhen) {
        for (auto &val: hang)
            cout << left << setw(6) << val;
        cout << endl;
    }
    return 0;
}
