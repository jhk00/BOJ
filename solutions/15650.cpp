
// 조합문제 -> 순서가 있음
#include <iostream>
using namespace std;
int N,M;
bool isused[10];
int arr[10];

void f(int k) { // 여태까지 k번째 뽑았음 -> 하나도 안뽑은 상태서 시작하니 k = 0
    if( k == M ) {
        for(int i = 0; i < M; i++) 
        cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    else {
        int st = 1;
        if(k != 0) st = arr[k-1] + 1; // 
        for(int i = st; i <= N; i++) {
        if(!isused[i]) {
            isused[i] = 1;
            arr[k] = i;
            f(k+1);
            isused[i] = 0;
        }
    }
    }
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);
cin >> N >> M;
f(0);

}