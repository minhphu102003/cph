#include <bits/stdc++.h>
using namespace std;

struct edge {
    int u, v, weight, weight_index;
};

int findSet(int v, vector<int> &parent) {
    if (v == parent[v])
        return v;
    return parent[v] = findSet(parent[v], parent);
}

void unionSets(int a, int b, vector<int> &parent, vector<int> &rank) {
    a = findSet(a, parent);
    b = findSet(b, parent);
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v;
        edges[i].weight = i + 1; 
        edges[i].weight_index = i;
    }
    vector<int> requireds(k);
    unordered_set<int> specialNodes;
    for (int i = 0; i < k; i++) {
        cin >> requireds[i];
        specialNodes.insert(requireds[i]);
    }
    vector<int> parent(n + 1), rank(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    vector<int> chosen(m, 0);
    vector<edge> specialEdges;
    for (auto &e : edges) {
        if (specialNodes.count(e.u) || specialNodes.count(e.v)) {
            specialEdges.push_back(e);
        }
    }
    sort(specialEdges.begin(), specialEdges.end(), [](edge &a, edge &b) {
        return a.weight < b.weight;
    });
    for (auto &e : specialEdges) {
        if (findSet(e.u, parent) != findSet(e.v, parent)) {
            unionSets(e.u, e.v, parent, rank);
            chosen[e.weight_index] = 1;
        }
    }
    sort(edges.begin(), edges.end(), [](edge &a, edge &b) {
        return a.weight < b.weight;
    });
    for (auto &e : edges) {
        if (findSet(e.u, parent) != findSet(e.v, parent)) {
            unionSets(e.u, e.v, parent, rank);
            chosen[e.weight_index] = 1;
        }
    }
    for (int i = 0; i < m; i++) {
        cout << chosen[i] << " ";
    }
    cout << endl;
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
