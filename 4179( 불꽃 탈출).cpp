#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int R,C; // 행, 열
string board[1002][1002];
int vis[1002][1002];

int main() {
cin >> R >> C;
for(int i = 0; i < R; i++) 
cin >> board[i];
if(board[i] == "J")
queue<pair<char,char>> Q;
Q.push({,0});
vis[0]



}