#include <iostream>
using namespace std;

 int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int X;
    cin >> X;
    int arr[N];
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for(int i = 0; i < N; i++) {
        if(arr[i] < X) {
            cout << arr[i] << " ";
        }
    }
    return 0;
}

풀이 1
int n,x;
std::cin >> n >> x;
int *a = new int[n];
for(int i = 0; i < n; i++)
std::cin >> a[i];
for(int i  = 0; i < n; i++) {
    if(a[i] < x) std::cout << a[i] << ' ';
}
delete[] a;


풀이 2
int n,x,a[10005]
for(int i = 0; i < n; i++) cin >> a[i];
for(int i = 0; i < n; i++)
if(a[i] < x) cout << a[i] << ' ';