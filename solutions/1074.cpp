#include <iostream>
using namespace std;



//r행 c열

int func(int n, int r, int c) {
// 너는 2^n * 2^n 배열에서 (r,c)를 방문하는 순서를 반환하는 함수야
// ( 지정 후 -> 내부 동작은 일단 신경쓰지 말기)
if(n==0) return 0; // 나는 0일때 조건을 안다
int half =1;
for(int i = 0; i < n-1; i++) half *= 2;
if( r < half && c < half ) return func(n-1,r,c);
if( r < half && c >= half ) return half*half + func(n-1,r,c-half);
if( r >= half && c < half ) return 2*half*half + func(n-1,r-half,c);
if( r >= half && c >= half) return 3*half*hlf + func(n-1, r-half, c-half);
}



int main() {
int n,r,c;
cin >> n >> r >> c;
cout << func(n,r,c);    
}
// 가따와서 비트연산자 공부