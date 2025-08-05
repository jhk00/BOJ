
/*n-1 개의 원판을 기둥 1에서 기둥 2로 옮긴다.
n번 원판을 기둥 1에서 기둥 3으로 옮긴다.
n-1개의 원판을 기둥 2에서 기둥 3으로 옮긴다.
//----> 원판이 n-1개일 때 옮길 수 있으면 원판이 n개일 때에도 옮길 수 있다.//

원판이 1개일 때 원판을 내가 원하는 곳으로 옮길 수 있다.
원판이 k개일 때 옮길 수 있으면 원판이 k+1개일 때에도 옮길 수 있다.*/





#include <iostream>
using namespace std;

void Hanoi(int a, int b, int n) {
if(n == 1) {
cout << a << " " << b << '\n';
return;
}
// 기존에 내가 했던 int풀이 -> Hanoi의 반환형을 int로 해놔서 런타임에러가 떴음
// Hanoi가 int형을 반환하도록 정의되어 있지만, 실제로 반환값을 사용하지 않는다는 점입니다. 
// 이로 인해 컴파일러나 실행 환경에서 런타임 에러가 발생할 수 있습니다. -> void형으로 고치기
Hanoi(a, 6-a-b, n-1); // k번
cout << a << " " << b << '\n';
Hanoi(6-a-b,b,n-1);
}

int pow(int a, int b) {
    if(b==0) return 1;
    return a*pow(a,b-1); 
} // a는 밑, b는 곱할수



/*int pow(int a, int b) {
    int val = 1;
    for(int i = 0; i < b; i++)
    val *= a;
    return val;
}
*/ 
int main(void) {
    // a - 시작 기둥, b - 가고자 하는 기둥, n - n번째 원판
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cout << pow(2,n) -1 << '\n';
    Hanoi(1,3,n);
    return 0;
}