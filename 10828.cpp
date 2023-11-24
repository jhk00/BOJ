#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void) {   
stack<int> S;
int num;
cin >> num;
string s;

while(num--) {
cin >> s;
if(s == "push") {
    int add;
    cin >> add;
    S.push(add);
}

if(s == "top") {
    if(S.empty())
    cout << "-1\n";
    else
    cout << S.top();
}

if(s == "size") 
    cout << S.size();

if(s == "empty" ) {
    if(S.empty())
    cout << "1\n";
    else
    cout << "0\n";
}
if(s == "pop") {
    if(S.empty())
    cout << "-1\n";
    else {
    cout << S.top();
    S.pop();
    } 
} 
}
    return 0;
}


// 한 줄에 하나씩 출력이니 출력찍고 개행문자를 넣어주는게 맞음
