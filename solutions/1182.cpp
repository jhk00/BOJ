#include <iostream>
using namespace std;

int n, s;
int arr[30];
int cnt = 0;

void func(int cur, int tot) { // cur -> 현재 배열의 인덱스, tot -> 현재 배열의 총합
    if (cur == n) {
        if(tot == s) cnt++;
        return;
    }
    func(cur+1, tot); // 현재 원소를 부분집합에 포함하지 않는 경우
    func(cur+1, tot+arr[cur]); // 현재 원소를 부분집합에 포함하는 경우
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for(int i = 0; i < n; i++)
    cin >> arr[i];
    func(0,0);
    if(s == 0) cnt--;
    cout << cnt;
}