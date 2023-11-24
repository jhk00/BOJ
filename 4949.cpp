//괄호 문제 해결 방법 Algorithm
// 1. 여는 괄호가 나오면 스택에 추가
// 2. 닫는 괄호가 나왔을 경우,
//    (1) 스택이 비어있으면 올바르지 않은 괄호 쌍
//    (2) 스택의 top이 짝이 맞지 않은 괄호일 경우 올바르지 않은 괄호 쌍
//    (3) 스택의 top이 짝이 맞는 괄호일 경우 pop
// 3. 모든 과정을 끝낸 후 스택에 괄호가 남아있으면 올바르지 않은 괄호 쌍,
//    남아있지 않으면 올바른 괄호 쌍

#include <iostream>
#include <stack>
#include <string>
using namespace std;



int main() {
ios::sync_with_stdio(0);
cin.tie(0);

while(1) {
string a;
getline(cin, a);
if(a ==".")
break;
stack<char> S;
bool isValid = true;
for(auto c : a) {
    if(c == '(' || c == '[') 
        S.push(c);
    else if(c == ')') {
        if(S.empty()) {
        isValid = false;
        break;
        }
        else if(S.top() == '(') {
        S.pop();
        }
        else {
        isValid = false;
        break;
        }
    }
    else if(c == ']') {
        if(S.empty()) {
        isValid = false;
        break;
        }
        else if(S.top() == '[') {
        S.pop();
        }
        else {
        isValid = false;
        break;
        }
    }
}
if(!S.empty()) isValid = false;
if(isValid)
cout << "yes\n";
else
cout << "no\n";
}
}

// 교훈 - 출력초과가 뜨면 while 무한루프 안에서 출력을 찍고 있는지
// 확인하기... 꼭!