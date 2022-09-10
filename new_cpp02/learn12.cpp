#include <iostream>
#include <vector>
using namespace std;

int every_number_mult_and(vector<vector<int>> &v1, vector<vector<int>> &v2,
                          int i, int j) {
    int res = 0;
    for(int a = 0;a <v1.size();a ++){
        res += v1[i][a] * v2[a][j];
    }
    return res;
}
vector<vector<int>> vector_mult(vector<vector<int>> &v1,
                                vector<vector<int>> &v2) {
    if (!v1.empty()) {
        if (v1[0].size() != v2.size()) {
            cout << "两个矩阵无法相乘" << endl;
            return {{}};
        }
        vector<vector<int>> ans{v1.size(), vector<int>(v2[0].size(), 0)};
        for (int i = 0; i < v1.size(); i++) {
            for (int j = 0; j < v2[0].size(); j++) {
                ans[i][j] = every_number_mult_and(v1, v2, i, j);
            }
        }

        return ans;

    } else {
        cout << "矩阵为0" << endl;
        return {{}};
    }
}

int main() {

    vector<vector<int>> v1{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    vector<vector<int>> v2{
        {1, 1},
        {1, 1},
        {1, 1}};
    auto ans = vector_mult(v1,v2);
    for(auto &i : ans) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
