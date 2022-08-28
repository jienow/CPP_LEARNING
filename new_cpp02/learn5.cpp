#include <iostream>
using namespace std;
struct Pig{
    char *name;
    Pig(char *ch):name(ch){}//c++ 默认深拷贝
    Pig(Pig const &p){
        name = p.name;
    }
    ~Pig(){
        delete[] name;
    }
};
int main(){
    char *ch= new char[50];
    Pig p1(ch);//c++ 默认深拷贝
    Pig p2(p1);
    cout << "完成" << endl;
    cout << "hello world" << endl;
    return 0;
}
