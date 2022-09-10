#include <deque>
#include <iomanip>
#include <iostream>
#include <unistd.h>

#define jin_du_tiao_length 50
using namespace std;

void jia_zai_dong_hua();
void deng_dai_pictures();
string mult_string(int number);

int main(int argc, char *argv[]) {

    //读入数据
    cout << "--请输入数据--" << endl;

    //创建数据
    //姓名

    string name;
    if (argc <= 1) {
        cout << "没有检测到您在命令行内写入姓名，请输入:";
        cin >> name;
    } else
        name = string(argv[1]);
    cout << "* 您的姓名是:";
    cout << name << endl;

    //身高

    string high;
    if (argc <= 2) {
        cout << "没有检测到您在命令行内写入身高，请输入:";

        cin >> high;
    } else
        high = string(argv[2]);
    cout << "* 您的身高是(cm):";
    cout << high << endl;

    fflush(stdout);

    // sleep(3);
    deng_dai_pictures();

    //加载动画
    jia_zai_dong_hua();

    cout << endl;
    cout << "计算完毕！" << endl;
    cout << name << "同学,";
    cout << "您的身高是 : " << high << "厘米" << endl;

    return 0;
}
void deng_dai_pictures() {
    for (int i = 3; i > 0; i--) {
        cout << "等待" << i << "秒后，开始计算...";
        fflush(stdout);
        sleep(1); // sleep之前要将输出缓存中的东西输出出来
        cout << '\r';
    }
}

void jia_zai_dong_hua() {
    for (int i = 0; i <= jin_du_tiao_length; i++) {
        cout << "正在计算"s
             << "[" << hex << setw(jin_du_tiao_length + 1) << left
             << mult_string(i) << "]"
             << to_string(int(float(100) / jin_du_tiao_length * i)) << "%";
        fflush(stdout);
        usleep(100000);
        cout << '\r';
    }
    sleep(1);
}
string mult_string(int number) {
    deque<char> list{'>'};
    while (number--) {
        list.push_front('=');
    }
    stringstream str;
    for (auto i : list) {
        str << i;
    }
    return str.str();
}
