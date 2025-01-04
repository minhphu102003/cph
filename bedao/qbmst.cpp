#include<bits/stdc++.h>
#define ll long long

using namespace std;

struct edge{
    int u,v,weight;
    bool operator<(const edge &other) const {
        if(weight == other.weight){
            return u < other.u;
        }
        return weight < other.weight;
    }
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

void solve(){
    int n,m;
    cin>>n>>m;
    vector<edge> V(m);
    for (int  i = 0; i < m; i++)
    {
        edge temp;
        cin>>temp.u>>temp.v>>temp.weight;
        temp.u--;
        temp.v--;
        V[i] = temp;
    }
    sort(V.begin(),V.end());
    vector<int> parent(n), rank(n,0);
    for (int  i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    
    int weight = 0;
    vector<edge> mst;
    for (edge e : V)
    {
        if (findSet(e.u, parent) != findSet(e.v, parent)) {
            weight += e.weight;
            mst.push_back(e);
            unionSets(e.u, e.v, parent, rank);
        }
    }
    cout <<weight << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    solve();
    return 0;
}