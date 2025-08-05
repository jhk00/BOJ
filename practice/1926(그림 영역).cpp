#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define X first;
#define Y second;
int board[502][502];
bool vis[502][502];
int n,m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m; // 행 열
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
    cin >> board[i][j];
    int mx = 0; // 그림의 최댓값
    int num = 0; // 그림의 수
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j]== 0 || vis[i][j]) continue; // 빨간칸 or 방문한곳 이면 다시찾고
            num++; // 그림수 하나 추가
            queue<pair<int,int>> Q;
            vis[i][j] = 1; // 방문한 곳 1로 바꾼 후
            Q.push({i,j}); // 큐에 방문한 pair 푸쉬
            int area = 0; // while 문 안에서 pop이 이루어 질 때마다 area값을 1씩 증가시키면 area값이 곧 그림의 넓이
            while(!Q.empty()) {
                area++; // 우선 한pair push하고 시작했으니 area++
                pair<int,int> cur = Q.front(); Q.pop(); // cur이라는 pair를 front 라 하면
                for(int dir = 0; dir <4; dir++) { // 4방향 탐색
                    int nx = cur.X + dx[dir]; // n = 행
                    int ny = cur.Y + dy[dir];  //  m = 열
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 배열의 원소 성질 -> i = 0 ~ n-1 까지고, j = 0 ~ m-1 까지
                    if(vis[nx][ny] || board[nx][ny] != 1) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx,ny});
                }
            }
            mx = max(mx, area); // algorithm 헤더에 있는 max함수 -> 요소 1과 요소 2중 더 큰값 리턴
            }
        }
        cout << num << '\n' << mx;
    }

