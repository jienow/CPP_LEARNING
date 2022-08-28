
#define FMT_HEADER_ONLY
#include <iostream>
#include <fmt/format.h>
using namespace std;
int main(){
    cout << "hello world!" << endl;
    cout << "hello" << endl;
    cout << fmt::format("hello") << endl;
    return 0;
}
