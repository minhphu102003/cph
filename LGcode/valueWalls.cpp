#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAX = 205;

int bfs(pair<int, int> s, pair<int, int> t, vector<vector<char>>& b, int r, int c) {
    vector<vector<bool>> v(r, vector<bool>(c, false));
    queue<pair<int, int>> q;
    q.push(s);
    v[s.first][s.second] = true;
    int d = 0;
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            auto [x, y] = q.front();
            q.pop();
            if (x == t.first && y == t.second) {
                return d;
            }
            for (auto [dx, dy] : dir) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && nx < r && ny >= 0 && ny < c && !v[nx][ny] && b[nx][ny] != 'W') {
                    v[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        d++;
    }
    return INT_MAX;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int r, c, n, tx, ty;
        cin >> r >> c >> n >> tx >> ty;
        vector<pair<int, int>> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i].first >> p[i].second;
            p[i].first--;
            p[i].second--;
        }
        vector<vector<char>> b(r, vector<char>(c));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> b[i][j];
            }
        }
        int totalC = 0;
        for (auto [x, y] : p) {
            int cost = bfs({x, y}, {tx - 1, ty - 1}, b, r, c);
            if (cost != INT_MAX) {
                totalC += cost;
            } else {
                totalC = INT_MAX;
            }
        }
        vector<int> diff; 
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (b[i][j] == 'W') { 
                    b[i][j] = '.';
                    int newC = 0;
                    for (auto [x, y] : p) {
                        int cost = bfs({x, y}, {tx - 1, ty - 1}, b, r, c);
                        if (cost != INT_MAX) {
                            newC += cost;
                        } else {
                            newC = INT_MAX;
                        }
                    }
                    diff.push_back(abs(newC - totalC)); 
                    b[i][j] = 'W';
                }
            }
        }
        cout << totalC << " ";
        ll sumD = 0;
        for (int d : diff) {
            sumD += d;
        }
        cout << sumD << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
