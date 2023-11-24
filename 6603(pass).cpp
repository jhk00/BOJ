#include <iostream>
using namespace std;
int K;
int arr[10];
int tarr[10];
bool isused[13];

void f(int k) {
if(k == 6) {
    for(int i = 0; i < 6; i++)
    cout << tarr[i] << ' ';
    cout << '\n';
    return;
}

else {
int st = 1;
if(!k=0) st = 
for(int i = st; i <= 6; i++) {
if(!isused[i]) {
    isused[i] = 1;
    tarr[k] = arr[k];
    f(k+1);
    isused[i] = 0;
    }
}

}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> K;
    for(int i = 0; i < K; i++)
    cin >> arr[i]; 
    f(0);
}