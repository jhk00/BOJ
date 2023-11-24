#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[502][502];
int vis[502][502];
int n,m; // 행, 열
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};



int main() {
ios::sync_with_stdio(0);
cin.tie(0);

cin >> n >> m;
for(int i = 0; i < n; i++)
for(int j = 0; j < m; j++) 
cin >> board[i][j];
int mx = 0; // 그림의 최댓값
int num = 0; // 그림의 개수
for(int i = 0; i < n; i++) {
for(int j = 0; j < m; j++) {
    if (board[i][j] == 0 || vis[i][j]) continue;

    queue<pair<int,int>> Q;
    Q.push({i,j});
    vis[i][j] = 1;
    int area = 0;
while(!Q.empty()) {
    area++;
    pair<int,int> rec = Q.front(); Q.pop();
    for(int dir = 0; dir < 4; dir++) {
        int nx = rec.X+dx[dir];
        int ny = rec.Y+dy[dir];
    if(nx < 0 || nx >= n || ny < 0 || ny >= 0) continue;
    if(board[nx][ny] == 0 || vis[nx][ny]) continue;
    vis[nx][ny] = 1;
    Q.push({nx,ny});
    }
}
mx = max(mx,area);
}
}
cout << mx << '\n';
}