#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
const int MAX_N = 17;
const int MAX_R = 105;
const int MAX_C = 105;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
struct Point {
    int x, y;
};
int R, C, N;
char grid[MAX_R][MAX_C];
Point shrines[MAX_N]; 
int dist[MAX_N + 1][MAX_R][MAX_C]; 
int dp[1 << MAX_N][MAX_N];
void bfs(int id, int sx, int sy) {
    queue<Point> q;
    q.push({sx, sy});
    dist[id][sx][sy] = 0;  
    while (!q.empty()) {
        Point cur = q.front(); q.pop();
        int x = cur.x, y = cur.y;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i]; 
            if (nx >= 0 && nx < R && ny >= 0 && ny < C && grid[nx][ny] != '#' && dist[id][nx][ny] == INF) {
                dist[id][nx][ny] = dist[id][x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}
int tsp() {
    for (int mask = 0; mask < (1 << N); mask++) {
        for (int i = 0; i < N; i++) {
            dp[mask][i] = INF;
        }
    }
    for (int i = 0; i < N; i++) {
        if (dist[0][shrines[i].x][shrines[i].y] == INF) {
            continue; 
        }
        dp[1 << i][i] = dist[0][shrines[i].x][shrines[i].y]; 
    }
    for (int mask = 0; mask < (1 << N); mask++) {
        for (int i = 0; i < N; i++) {
            if (mask & (1 << i)) { 
                for (int j = 0; j < N; j++) {
                    if (!(mask & (1 << j)) && dist[i + 1][shrines[j].x][shrines[j].y] != INF) { 
                        dp[mask | (1 << j)][j] = min(dp[mask | (1 << j)][j], dp[mask][i] + dist[i + 1][shrines[j].x][shrines[j].y]);
                    }
                }
            }
        }
    }
    int ans = INF;
    for (int i = 0; i < N; i++) {
        ans = min(ans, dp[(1 << N) - 1][i]);
    }
    return (ans == INF) ? -1 : ans;
}

int main() {
    cin >> R >> C >> N;
    for (int i = 0; i < R; i++) {
        cin >> grid[i];
    }
    int shrineCount = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == 'S') {
                shrines[shrineCount++] = {i, j};
            }
        }
    }
    for (int i = 0; i <= N; i++) {
        for (int x = 0; x < R; x++) {
            for (int y = 0; y < C; y++) {
                dist[i][x][y] = INF;
            }
        }
    }
    bfs(0, 0, 0);
    for (int i = 0; i < N; i++) {
        bfs(i + 1, shrines[i].x, shrines[i].y);
    }
    bool canVisitAllShrines = true;
    for (int i = 0; i < N; i++) {
        if (dist[0][shrines[i].x][shrines[i].y] == INF) {
            canVisitAllShrines = false;
            break;
        }
    }
    if (!canVisitAllShrines) {
        cout << -1 << endl;
        return 0;
    }
    int result = tsp();
    cout << result << endl;
    return 0;
}
