#include <bits/stdc++.h>
using namespace std;
stack<char> op;
stack<int> num;
string str;
unordered_map<char, int> pr{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
void eval() {
    int b = num.top();
    num.pop();
    int a = num.top();
    num.pop();
    char c = op.top();
    op.pop();
    int x = 0;
    if (c == '+')
        x = a + b;
    else if (c == '-')
        x = a - b;
    else if (c == '*')
        x = a * b;
    else if (c == '/')
        x = a / b;
    num.push(x);
}
int main(int argc,char *argv[]) {
    string str;
    if (argc > 1) str = argv[1];
    else {
        cout << "检测到你没有输入表达式，请输入： ";
        cin>>str;
    }
    for (int i = 0; i < str.size(); i++) {
        char c = str[i];
        if (isdigit(c)) {
            int x = 0, j = i;
            while (j < str.size() && isdigit(str[j]))
                x = x * 10 + (str[j++] - '0');
            i = j - 1;
            num.push(x);
        } else if (c == '(')
            op.push(c);
        else if (c == ')') {
            while (op.top() != '(')
                eval();
            op.pop();
        } else {
            while (op.size() && op.top() != '(' && pr[op.top()] >= pr[c])
                eval();
            op.push(c);
        }
    }
    while (op.size())
        eval();
    cout << num.top() << endl;
    return 0;
}
