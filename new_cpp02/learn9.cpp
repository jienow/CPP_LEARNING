#include <iostream>
#include <unistd.h>
using namespace std;
int main(){
    cout << "hello world" << endl;
    for(int i = 0;i < 3;i ++){
        cout << "shenjie" << i;
        fflush(stdout);
        sleep(1);
        printf("\r");

    }
    cout << endl;
    return 0;
}
