#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
const int LOG = 17;

vector<int> tree[MAXN];
int up[MAXN][LOG];
int depth[MAXN];

void dfs(int v, int parent)
{
    up[v][0] = parent;
    for (int i = 1; i < LOG; i++)
    {
        if (up[v][i - 1] != -1)
            up[v][i] = up[up[v][i - 1]][i - 1];
        else
            up[v][i] = -1;
    }
    for (int u : tree[v])
    {
        if (u != parent)
        {
            depth[u] = depth[v] + 1;
            dfs(u, v);
        }
    }
}

int lca(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);
    int diff = depth[u] - depth[v];
    for (int i = 0; i < LOG; i++)
    {
        if ((diff >> i) & 1)
            u = up[u][i];
    }

    if (u == v)
        return u;

    for (int i = LOG - 1; i >= 0; i--)
    {
        if (up[u][i] != up[v][i])
        {
            u = up[u][i];
            v = up[v][i];
        }
    }

    return up[u][0];
}
bool is_ancestor(int u, int v)
{
    return lca(u, v) == u;
}
bool on_path(int x,int y,int z)
{
    int lcaxz=lca(x,z);
    int lcaxy=lca(x,y);
    int lacyz=lca(y,z);
    if (is_ancestor(lcaxz,y)&&is_ancestor(y,z)) return true;
    if (lcaxz==lca(lcaxy,lacyz) &&(is_ancestor(y,x)||is_ancestor(y,z))) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    depth[1] = 0;
    dfs(1, 0);
    
    //cout<<lca(5,4)<<endl;
    while (q--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if (on_path(x, y, z))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
