#include <iostream>
#include <algorithm>
using namespace std;
int board[129][129];
int result[2];

bool check(int row, int col, int num) {
int start = board[row][col];
for(int i = row ; i < row + num ; i++ ){
for(int j = col ; j < col + num ; j++ ){
if(board[i][j] != start)
return false;
}
}

return true;
}



void divide(int row, int col, int num) {
    if(check(row,col,num)) 
        result[board[row][col]]++;

    else {
        int size = num / 2;

        for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
        divide(row+size*i, col+size*j, size);

    }
}


int main() {
ios::sync_with_stdio(0);
cin.tie(0);

int N;
cin >> N; 
for(int i = 0; i < N; i++) 
for(int j = 0; j < N; j++) 
cin >> board[i][j];

divide(0,0,N);
for(int i = 0; i < 2; i++)
cout << result[i] << '\n';

}

// 문제를 잘못 이해해서 이틀 날림
// 나의 재귀 호출흐름 이해는 정확했음
// 문제를 잘 읽자 제발 완벽한 이해를 하자
// 문제의 이해를 위해선 백준에서 주어진 테스트 케이스 이외의
// 테스트 케이스를 내가 직접 넣어봐서 해야할 필요가 있음(반드시)

// 1780번도 똑같은 문제인데 거기 테스트 케이스로 한정지어서
// 생각해서 2630번도 그거에 갇혀 문제를 잘못이해했음
// 반드시 주어진 테스트 케이스 이외의 테스트 케이스도 내가 해보자
// 그냥 애초에 1780번도 내가 잘못이해함 ㅠㅠ
// 문제의 정확한 이해에 시간을 많이 할애할 것