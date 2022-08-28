//#include <iostream>
// using namespace std;
// struct Pig {
//    string name;
//    int age;
//    explicit Pig() {
//        //不允许隐式构造
//        //最好加上，不然会出现Pig p = 80 这种情况
//    }
//};
// int main() {
//
//    return 0;
//}
//要多使用type{}来进行类型初始化
// type()进行初始化的话，容易对里面的内容进行强制类型装换，容易出错
//
//如果强制类型转换，容易让数据类型转换成为指针类型
//所以应该使用static_cast<int>(3.14f)来进行类型转换
//如果要将类型来转换成为指针类型，可以使用reinterpret_cast<void*>(0x11)
//  来进行类型转换
//

//初始化
//#include <iostream>
// using namespace std;
// class Pig{
// public:
//    string name;
//    int age;
//    explicit Pig(int age,string name):age(age),name(name){}
//};
// int main(){
//    Pig pig1{20,"小猪佩琪"s};
//    cout << pig1.age << " " << pig1.name << endl;
//    return 0;
//}

struct Interger {
    int number;
    Interger() = default;
    Interger(int a) : number(a) {}
    Interger(Interger &b) { number = b.number; }
    Interger &operator=(Interger const &a) {
        number = a.number;
        return *this;
    }
    Interger &operator=(int number) { return *this; }
};
#include <iostream>
using namespace std;
int main() {
    // Interger a{10};
    // Interger b = 10;
    // Interger c(a);
    // Interger d = a;
    //Interger a;
    //a = 10;
    //cout << a.number << endl;
    //Interger b;
    //b = a;
    //cout << b.number << endl;
    //string name = "hello world";
    //cout << name << endl;
    //cout << "hello world" << endl;
    //int a = 10;
    int a = 10;
    int b = 20;
    printf("%d %d\n",a,b);
    string name = "hello world";
    cout << name << endl;
    return 0;
}
