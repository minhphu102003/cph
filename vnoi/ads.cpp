#include <bits/stdc++.h>
#define ll long long

const int maxn = 2000;
const int maxm = 5000;

using namespace std;

vector<vector<int>> graph;
int visited[maxn] = {0}; // Đổi tên mảng thành visited

void solve() {
    int n, m;
    cin >> n >> m;
    graph.resize(n);
    // Đọc dữ liệu đồ thị
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) { // Nếu đỉnh i chưa được thăm
            ans++; // Bắt đầu một thành phần liên thông mới
            queue<int> qu;
            qu.push(i);
            visited[i] = 1; // Đánh dấu đỉnh i là đã thăm
            while (!qu.empty()) {
                int u = qu.front();
                qu.pop();
                // Duyệt tất cả các đỉnh kề với u
                for (vector<int>::iterator it = graph[u].begin(); it != graph[u].end(); ++it) {
                    if (!visited[*it]) {
                        visited[*it] = 1; // Đánh dấu đỉnh đã thăm
                        qu.push(*it); // Đẩy vào hàng đợi
                    }
                }
            }
        }
    }
    // Công thức tính số cạnh cần thêm để biến đồ thị thành một đồ thị có n đỉnh và k thành phần liên thông
    cout << m - n + ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp", "r", stdin);
    freopen("B001.out", "w", stdout);
    solve();
    return 0;
}
