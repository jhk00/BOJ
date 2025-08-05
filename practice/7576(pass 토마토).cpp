
#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;
int n,m; // 행 열
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int board[1002][1002];
int vis[1002][1002];
int nmt = 0; // 안익은 토마토가 없을때 안전장치
int cmt = 0; // 토마토가 모두 익지 못할때 안전장치

// 1 -> 익은 토마토
// 0 -> 익지 않은 토마토
// -1 -> 빈칸
// 0을 모두 1로 만들어야함 ( 모두 익을때 까지의 날짜 구하기)
int main() {
    cin >> n >> m;
    queue<pair<int,int>> q;
    for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
    cin >> board[i][j];
    if(board[i][j] == 1) {
    q.push({i,j});
    vis[i][j] = 1;
    }
    else if(board[i][j] == 0) {
    nmt++; // 안익은 토마토의 개수 저장
    }
    else {
    vis[i][j] = -1;
    }
    }
    }
    
    while(!q.empty()) {
        pair<int,int> cur = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m ) continue;
        if(board[nx][ny] != 0 || vis[nx][ny] != 0) continue;
        vis[nx][ny] = vis[cur.X][cur.Y] + 1;
        q.push({nx,ny});
        }
    }
    int mx = 0; 
    for(int i = 0; i < n; i++) { 
    for(int j = 0; j < m; j++) {
    mx = max(mx, vis[i][j]);    
    if(vis[i][j] == 0)  
    cmt++; // cant mature - 루프를 다 돌아도 토마토가 못익었을때
    }
    }
    if(cmt > 0) // 못익은 토마토가 있을때 -> -1출력
    cout << -1 << "\n";
    if(nmt == 0) // 입력받을때 안익은 토마토가 애초에 없을때 -> 0출력
    cout << 0 << "\n";
    else
    cout << mx-1 << "\n";
    
    }


//일단 pass