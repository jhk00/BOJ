#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string QT[64];


bool check(int row, int col, int num) {
    char start = QT[row][col];
    for(int i = row; i < row + num; i++) {
    for(int j = col; j < col + num; j++) {
    if(start != QT[i][j])
    return false;
    }
    }
    
    return true;
}

void divide(int row, int col, int num) {
if(check(row,col,num)) 
    cout << QT[row][col];
else {
    cout << "(";
    int size = num / 2;
    for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 2; j++) {
    divide(row+size*i, col+size*j, size);
   
    }
    }
    cout << ")";
}

}


int main() {
ios::sync_with_stdio(0);
cin.tie(0);
int N;
cin >> N;

for(int i = 0; i < N; i++)
cin >> QT[i];

divide(0,0,N);

}


// 새로 알게 된 사실 -> for문은 재귀호출이 다 쌓일때까지 막지 않고 바로바로 실행시킨 후 다음껄 기억해서 
// 다음 재귀함수를 실행시킴. 그래서 이 문제에서 분할 후 4사분면에 있는 사각형을 먼저 탐색하는게 아니라
// 1사분면에 있는 사각형부터 탐색해서 아니면 분할하고 그런식인거임. 그래서 예제 출력값도 1이 먼저 찍히는것
// 결론 : for문 안에 재귀가 있으면 재귀가 스택 안에 다 쌓이고 역순으로 실행되는게 아니라 그냥 쌓이면 바로 실행시킨후 for문의 그다음 순서
// 재귀함수를 불러서 실행시키고 이런식. 4321 순이 아니라 1234 순으로 그대로 호출됨. 그동안 스택에 쌓인거는 f(n-1) 식의 재귀함수였다.

// 이 문제 대충 n=4 로 예제 몇번 돌려보면서 for문의 재귀호출 흐름 생각하면 참 좋은거 같음
// 그리고 string board 선언 후 다룰때 borad[m][n] 형식으로 사용 가능한거 인지해두기