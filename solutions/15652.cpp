#include <iostream>
using namespace std;
int N,M;
int arr[10];

void f(int k) {
    if(k == M) {
        for(int i = 0; i < M; i++)
        cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    else {
        int st = 1;
        if(k != 0) st = arr[k-1];  
        for(int i = st; i <= N; i++) {
        arr[k] = i;
        f(k+1);
    }
}
}

int main() {
cin >> N >> M;
f(0);
}