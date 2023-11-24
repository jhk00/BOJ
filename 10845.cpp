#include <iostream>
#include <queue>
#include <string>
using namespace std;



int main() {
ios::sync_with_stdio(0);
cin.tie(0);
queue<int> Q;
int num;
cin >> num;
while(num--) {
string s;
cin >> s;
if(s == "push") {
    int add;
    cin >> add;
    Q.push(add);
}

if(s == "pop") {
    if(Q.empty())
    cout << -1 << "\n";
    else {
    cout << Q.front() << "\n";
    Q.pop();
    }
}

if(s == "size") 
    cout << Q.size() << "\n";

if(s == "empty") {
    if(Q.empty())
    cout << 1 << "\n";
    else
    cout << 0 << "\n";
}

if(s == "front") {
    if(Q.empty())
    cout << -1 << "\n";
    else
    cout << Q.front() << "\n";
}

if(s == "back") {
    if(Q.empty())
    cout << -1 << "\n";
    else
    cout << Q.back() << "\n";
}
}
}