#include <iostream>
using namespace std;

//using long = long long; 이게 안되는 이유 -> 이미 c++에는 long 자료형이 있음

using ll = long long;

ll func(ll A, ll B, ll C) {
if(B==1) return A;
ll val = func(A,B/2,C);
 // 스택영역에 B/2로 쫙 쌓였다가 내가 지정해준 return으로 쌓인거를 없애주면서 형식을 입혀주는 느낌( 일다 이 생각은 너무 절차적임. 이 생각을 버리는게 좋을 것 같다 (8.25 생각))

if( B % 2 == 0 ) {
val = val * val; 
return val % C;
}

else {
val = val * val *A
return val%C;
}
}

int main() {
    ll A,B,C;
    cin >> A >> B >> C;
    cout << func(A,B,C);
}