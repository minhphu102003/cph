#include<bits/stdc++.h>
#define ll long long

using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    queue<pair<int, int>> q;
    vector<vector<int>> time(n, vector<int>(m, -1));
    int fresh = 0;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (grid[i][j] == 2) {
                q.push({i, j});
                time[i][j] = 0;
            } else if (grid[i][j] == 1) {
                fresh++;
            }

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    int res = 0;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                grid[nx][ny] == 1 && time[nx][ny] == -1) {
                time[nx][ny] = time[x][y] + 1;
                res = time[nx][ny];
                grid[nx][ny] = 2;
                q.push({nx, ny});
                fresh--;
            }
        }
    }

    return fresh == 0 ? res : -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m));
    for (int  i = 0; i < n; i++)
    {
        for (int  j = 0; j < m; j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<orangesRotting(a);
    return 0;
}