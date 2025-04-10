#include<bits/stdc++.h>
#define ll long long

using namespace std;

int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    int n = maze.size(), m = maze[0].size();
    queue<pair<int, int>> q;
    vector<vector<int>> dist(n, vector<int>(m, -1));
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    int sx = entrance[0], sy = entrance[1];
    q.push({sx, sy});
    dist[sx][sy] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && maze[nx][ny] == '.' && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
                if (nx == 0 || ny == 0 || nx == n - 1 || ny == m - 1) {
                    if (!(nx == sx && ny == sy)) {
                        return dist[nx][ny];
                    }
                }
            }
        }
    }

    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<vector<char>> maze(n, vector<char>(m));
    for (int  i = 0; i < n; i++)
    {
        for (int  j = 0; j < m; j++)
        {
            cin>>maze[i][j];
        }
    }
    int x, y;
    cin >> x >> y;
    vector<int> entrance = {x, y};
    cout<<nearestExit(maze, entrance); 
    return 0;
}