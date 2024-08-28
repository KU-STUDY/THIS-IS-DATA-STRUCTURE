#include <iostream>
#include <queue>

using namespace std;
#define X first
#define Y second

int n = 10;
int m = 10;

int board[500][500];
bool vis[500][500];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void) {
    queue<pair<int,int>> Q;
    vis[0][0] = 1;

    Q.push({0,0});
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int dir=0; dir<4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(vis[nx][ny] || board[nx][ny] != 1) continue;
            vis[nx][ny] = 1;
            Q.push({nx,ny});
        }
    }
}