#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int dai_shu_yu_zi_shi(vector<vector<int>> &mat, int x, int y);
int calcul(vector<vector<int>> &mat, int x1, int y1, int x2, int y2);

vector<vector<int>> init_read(string file) {
    fstream ofs;
    ofs.open("/home/jienow/Development/CPP_DEVELOPMENT/CPP_LEARNING/new_cpp02/"
             "shuju/" +
                 file,
             ios::in);

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

int fu_hao(int x, int y) { return pow(-1, x + y); }

int dai_shu_yu_zi_shi(vector<vector<int>> &mat, int x, int y) {
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
    return calcul(tmp, 0, 0, (int)tmp.size() - 1, (int)tmp.size() - 1);
}

int yu_zi_shi(vector<vector<int>> &mat, int x, int y) {
    return mat[x][y] * fu_hao(x, y) * dai_shu_yu_zi_shi(mat, x, y);
}

int calcul(vector<vector<int>> &mat, int x1, int y1, int x2, int y2) {
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

int main(int argc, char *argv[]) {
    string file;
    if(argc ==1){
        cout << "没有传入文件名，请重新运行" << endl;
        return 1;
    }
    else file = argv[1];

    auto mat = init_read(file);

    int result = calcul(mat, 0, 0, (int)mat.size() - 1, (int)mat.size() - 1);

    cout << result << endl;

    return 0;
}
