#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
deque<int> d;
int num;
cin >> num;
while(num--) {
    string s;
    cin >> s;
    if(s == "push_front") {
        int add1;
        cin >> add1;
        d.push_front(add1);
    }
    
    if(s == "push_back") {
        int add2;
        cin >> add2;
        d.push_back(add2);
    }

    if(s == "pop_front") {
        if(d.empty())
        cout << -1 << "\n";
        else {
        cout << d.front() << "\n";
        d.pop_front();
        }
    }
    if(s == "pop_back") {
        if(d.empty())
        cout << -1 << "\n";
        else {
        cout << d.back() << "\n";
        d.pop_back();
        }
    }

    if(s == "size")
    cout << d.size() << "\n";

    if(s == "empty") {
        if (d.empty())
        cout << 1 << "\n";
        else
        cout << 0 << "\n";
    }

    if(s == "front") {
        if(d.empty())
        cout << -1 << "\n";
        else
        cout << d.front() << "\n";
    }

    if(s == "back") {
        if(d.empty())
        cout << -1 << "\n";
        else
        cout << d.back() << "\n";
    }
    }
}
