#include <iostream>
#include <queue>
#include <algorithm>
#define X first
#define Y second
using namespace std;
int n,m; // 행, 열
string board[102]; 
// 미로에 해당하는 수들이 붙어서 입력되므로 string 배열로 받았습니다.
// int로 선언을 하면 board[i][0]에 0 혹은 1이 담기는게 아니라 01110101101 이런게 담기게 된다.
int dist[102][102];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int main() {
cin >> n >> m;
for(int i = 0; i < n; i++)
cin >> board[i];

queue<pair<int,int>> Q;
Q.push({0,0});
dist[0][0] = 1;
while(!Q.empty()) {
    pair<int,int> cur = Q.front(); Q.pop();
    for(int dir = 0; dir < 4; dir++) {
        int mx = cur.X + dx[dir];
        int my = cur.Y + dy[dir];
    
    if( mx < 0 || mx >= n || my < 0 || my >= m) continue;
    if( board[mx][my] != '1' || dist[mx][my] > 0) continue; // 기존코드 dist[nx][ny] >= 0
    dist[mx][my] = dist[cur.X][cur.Y] + 1;
    Q.push({mx,my});
}
}
cout << dist[n-1][m-1];
}
// barkingdog 답지에는 fill 함수로 dist 배열에 모두 -1을
// 채워넣고 풀었는데 솔직히 그 이유는 모르겠음
// 그냥 0으로 초기화하고 경계값조건 만져주면 끝
