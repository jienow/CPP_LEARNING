//#include <sstream>
//#include <iostream>
//#include <iomanip>
// using namespace std;
// int number = 10;
// int main(int argc,char *argv[]){
//    //cout << "hello world"s.find('h') << endl;
//    //cout << (stringstream() << setprecision(100) << 3.1415f).str() << endl;
//    int number = 20;
//    cout << ::number << endl;
//
//    return 0;
//}

#include <iostream>
#include <memory>
#include <vector>
using namespace std;
//vector<string> split(string const str, string const split_str) {
//    vector<string> ans;
//    size_t pos = 0;
//    while(true){
//        size_t new_pos = str.find_first_of(split_str,pos);
//        if(new_pos == str.npos){
//            ans.push_back(str.substr(pos, new_pos));
//            break;
//        }
//        ans.push_back(str.substr(pos, new_pos-pos));
//        pos = new_pos + 1;
//    }
//    return ans;
//}

 unique_ptr<vector<string>> split(string const str, string const split_str) {
    vector<string> ans;
    unique_ptr<vector<string>> ptr{new vector<string>};
    size_t pos = 0;
    while(true){
        size_t new_pos = str.find_first_of(split_str,pos);
        if(new_pos == str.npos){
            ptr->push_back(str.substr(pos, new_pos));
            break;
        }
        ptr->push_back(str.substr(pos, new_pos - pos));
        pos = new_pos + 1;
    }
    return move(ptr);
}


int main() {
    string str{"hello world world hello\nshenjie\tc++"};
    string split_str{" \n\t"};
    auto ptr = split(str, split_str);
    for(auto& i : *ptr){
        cout << i << endl;
    }
    return 0;
}
