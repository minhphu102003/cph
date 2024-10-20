#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
const int MAX_V = 10005; 
vector<int> adj[MAX_V]; 
int capacity[MAX_V][MAX_V]; 
int parent[MAX_V];
bool bfs(int source, int sink) {
    fill(parent, parent + MAX_V, -1);
    queue<pair<int, int>> q;
    q.push({source, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next] > 0) { 
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == sink)
                    return true; 
                q.push({next, new_flow});
            }
        }
    }
    return false;
}

int edmondsKarp(int source, int sink) {
    int flow = 0;
    while (bfs(source, sink)) {
        int cur_flow = INF;
        int cur = sink;
        while (cur != source) {
            cur_flow = min(cur_flow, capacity[parent[cur]][cur]);
            cur = parent[cur];
        }
        cur = sink;
        while (cur != source) {
            int prev = parent[cur];
            capacity[prev][cur] -= cur_flow;
            capacity[cur][prev] += cur_flow;
            cur = prev;
        }
        flow += cur_flow;
    }
    return flow;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, nA, nB, nC;
        cin >> n >> nA >> nB >> nC;
        int source = 0;       
        int sink = n + 4;      
        for (int i = 0; i < MAX_V; i++) {
            adj[i].clear();
            for (int j = 0; j < MAX_V; j++) {
                capacity[i][j] = 0;
            }
        }
        int mA, mB, mC;
        cin >> mA;
        for (int i = 0; i < mA; i++) {
            int worker;
            cin >> worker;
            adj[worker].push_back(n + 1);   
            adj[n + 1].push_back(worker);
            capacity[worker][n + 1] = 1;    
        }
        cin >> mB;
        for (int i = 0; i < mB; i++) {
            int worker;
            cin >> worker;
            adj[worker].push_back(n + 2);   
            adj[n + 2].push_back(worker);
            capacity[worker][n + 2] = 1;    
        }
        cin >> mC;
        for (int i = 0; i < mC; i++) {
            int worker;
            cin >> worker;
            adj[worker].push_back(n + 3);   
            adj[n + 3].push_back(worker);
            capacity[worker][n + 3] = 1;    
        }
        for (int i = 1; i <= n; i++) {
            adj[source].push_back(i);
            adj[i].push_back(source);
            capacity[source][i] = 1;    
        }
        adj[n + 1].push_back(sink);
        adj[sink].push_back(n + 1);
        capacity[n + 1][sink] = nA; 
        adj[n + 2].push_back(sink);
        adj[sink].push_back(n + 2);
        capacity[n + 2][sink] = nB;  
        adj[n + 3].push_back(sink);
        adj[sink].push_back(n + 3);
        capacity[n + 3][sink] = nC;  
        int maxWorkersAssigned = edmondsKarp(source, sink);
        cout << maxWorkersAssigned << endl;
    }
    return 0;
}
