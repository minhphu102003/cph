#include<bits/stdc++.h>
#define ll long long

using namespace std;

void dfs(int cur, const vector<vector<int>>& gra, const set<pair<int,int>>& dir, vector<bool>& vis, int& count){
    vis[cur] = true;
    int len = gra[cur].size();
    for (int  i = 0; i < len; i++)
    {
        if(!vis[gra[cur][i]]){
            if (dir.count({cur, gra[cur][i]})) count++;
            dfs(gra[cur][i],gra, dir, vis, count);
        }
    }
    
}

int minReorder(int n, vector<vector<int>>& connections) {
    vector<vector<int>> a(n);
    set<pair<int, int>>dir;
    int len = connections.size();
    for (int  i = 0; i < len; i++)
    {
        int u = connections[i][0];
        int v = connections[i][1];
        a[u].push_back(v);
        a[v].push_back(u);
        dir.insert({u,v});
    }
    vector<bool> vi(n,false);
    int count = 0;
    dfs(0,a,dir,vi,count);
    return count;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    
    int n;
    cin >> n;

    vector<vector<int>> connections;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        connections.push_back({u, v});
    }

    int result = minReorder(n, connections);
    cout << result << '\n';

    return 0;
}