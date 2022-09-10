// vector的实现
//#include <cstring>
//#include <iostream>
// using namespace std;
//
// template <class T> class vector {
//  private:
//    size_t sz;
//    T *arr;
//
//  public:
//    size_t size() { return sz; }
//    vector(int number) { arr = new T[number]; }
//
//    vector() = default;
//    vector(vector<T> const &v) {
//        arr = new T[v.sz];
//        memcpy(arr, v.arr, sz * sizeof(int));
//    }
//    vector(vector<T> &&v) {
//        sz = v.sz;
//        arr = v.arr;
//        v.sz = 0;
//        v.arr = nullptr;
//    }
//    vector<T> &operator=(vector<T> const &v) {
//        this->~vector<T>();
//        new (this) vector<T>(v); //新语法，在某个地址上面去构造，new
//        //堆上  当前的this上面 构建一个vector;
//        return *this;
//    }
//    vector<T> &operator=(vector<T> &&v) {
//        this->~vector<T>();
//        new (this) vector<T>(move(v));
//        return *this;
//    }
//
//    T &operator[](size_t t) { return arr[t]; }
//    ~vector() { delete[] arr; }
//};
//
// int main() {
//    vector<int> v{10};
//    vector<int> v1{v};
//    vector<int> v2;
//    v2 = v;
//    v2 = move(v1);
//    return 0;
//}

//
//#include <iostream>
// using namespace std;
// class Pig {
//  public:
//    string name;
//    Pig(string name) : name(name) {}
//    explicit Pig(Pig const &v) = default;
//};
// void show(Pig pig) { cout << pig.name << endl; }
// int main() {
//    Pig pig{"piqi"};
//    //show(pig);//这里必须显示构造
//    show(Pig{pig});
//    return 0;
//}
//最好是拷贝构造，拷贝之类的都用显示，即构造函数都用显示

//#include <iostream>
// using namespace std;
// class Pig {
//  public:
//    string name;
//    explicit Pig(string name) : name(name) {}
//    explicit Pig(Pig const &v) = default;
//};
// void show(Pig pig) { cout << pig.name << endl; }
// int main() {
//    Pig pig{"piqi"};//都用显示构造
//    //show(pig);//这里必须显示构造
//    show(Pig{pig});
//    return 0;
//}

//#include <iostream>
// using namespace std;
// int main(){
//
//    std::cout << "hello"s + " "  + "world" << std::endl;
//    string a = "23 yuan"s;
//    int n = stoi(a);
//    cout << n << endl;
//    return 0;
//}

//#include <iostream>
// using namespace std;
// int main() {
//    if (is_signed<char>::value)
//        cout << "x86" << endl;
//    return 0;
//}

#include <iostream>
#include <vector>
using namespace std;

int main() {
    string name{"hello"};
    cout << name.length() << endl;
    cout << name.size() << endl;
    return 0;
}
