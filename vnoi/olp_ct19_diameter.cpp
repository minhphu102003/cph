#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 1e6 + 1;
vector<int> tree[maxn]; 
int dist[maxn];
int n, k;
vector<int> degree(maxn, 1);

pair<int, int> bfs(int start) {
    fill(dist + 1, dist + n + 1, -1); 
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    int farthest_node = start, max_dist = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : tree[u]) {
            if (dist[v] == -1) { 
                dist[v] = dist[u] + 1;
                q.push(v);
                if (dist[v] > max_dist) {
                    max_dist = dist[v];
                    farthest_node = v;
                }
            }
        }
    }
    return {farthest_node, max_dist};
}

void fastprint(int number) {
    char buffer[12]; 
    int idx = 0;
    if (number == 0) {
        putchar('0');
        return;
    }
    if (number < 0) {
        putchar('-');
        number = -number;
    }
    while (number > 0) {
        buffer[idx++] = '0' + (number % 10); 
        number /= 10;
    }
    while (idx--) {
        putchar(buffer[idx]);
    }
}

void fastscan(int &number) {
    bool negative = false;
    char c;
    number = 0;
    while ((c = getchar()) < '0' || c > '9') {
        if (c == '-') negative = true; 
    }
    do {
        number = number * 10 + (c - '0');
    } while ((c = getchar()) >= '0' && c <= '9');
    if (negative) number = -number;
}

void solve() {
    fastscan(k);
    n = k + 2;
    for (int i = 1; i <= n; i++) {
        tree[i].clear();
    }
    fill(degree.begin(), degree.begin() + n + 1, 1);
    vector<int> prufer(k);
    for (int i = 0; i < k; i++) {
        fastscan(prufer[i]);
        degree[prufer[i]]++;
    }
    priority_queue<int, vector<int>, greater<int>> leaves; 
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 1) {
            leaves.push(i);
        }
    }
    for (int x : prufer) {
        int leaf = leaves.top();
        leaves.pop();
        tree[x].push_back(leaf);
        tree[leaf].push_back(x);
        degree[leaf]--;
        degree[x]--;
        if (degree[x] == 1) {
            leaves.push(x);
        }
    }
    int u = leaves.top();
    leaves.pop();
    int v = leaves.top();
    leaves.pop();
    tree[u].push_back(v);
    tree[v].push_back(u);
    int farthest = bfs(1).first;
    int diameter = bfs(farthest).second;
    fastprint(diameter);
    putchar('\n');
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
