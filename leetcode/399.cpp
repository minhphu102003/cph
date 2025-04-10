#include <bits/stdc++.h>
#define ll long long

using namespace std;

class UnionFind
{
public:
    unordered_map<string, string> parent;
    unordered_map<string, double> weight;

    void add(const string &x)
    {
        if (!parent.count(x))
        {
            parent[x] = x;
            weight[x] = 1.0;
        }
    }

    string find(const string &x)
    {
        if (parent[x] != x)
        {
            string orig_parent = parent[x];
            parent[x] = find(parent[x]);
            weight[x] *= weight[orig_parent];
        }
        return parent[x];
    }

    void unite(const string &x, const string &y, double value)
    {
        add(x);
        add(y);
        string rootX = find(x);
        string rootY = find(y);
        if (rootX != rootY)
        {
            parent[rootX] = rootY;
            weight[rootX] = value * weight[y] / weight[x];
        }
    }

    double isConnected(const string &x, const string &y)
    {
        if (!parent.count(x) || !parent.count(y))
            return -1.0;
        string rootX = find(x);
        string rootY = find(y);
        if (rootX != rootY)
            return -1.0;
        return weight[x] / weight[y];
    }
};

vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
{
    UnionFind uf;

    for (int i = 0; i < equations.size(); ++i)
    {
        string a = equations[i][0];
        string b = equations[i][1];
        double val = values[i];
        uf.unite(a, b, val);
    }

    vector<double> res;
    for (auto &q : queries)
    {
        res.push_back(uf.isConnected(q[0], q[1]));
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp", "r", stdin);
    freopen("B001.out", "w", stdout);
    int n;
    cin >> n;
    vector<vector<string>> equations(n);
    vector<double> values(n);
    for (int i = 0; i < n; ++i)
    {
        string a, b;
        double v;
        cin >> a >> b >> v;
        equations[i] = {a, b};
        values[i] = v;
    }
    int q;
    cin >> q;
    vector<vector<string>> queries(q);
    for (int i = 0; i < q; ++i)
    {
        string x, y;
        cin >> x >> y;
        queries[i] = {x, y};
    }
    vector<double> results = calcEquation(equations, values, queries);
    int len = results.size();
    for (int i = 0; i < len; i++)
    {
        cout << fixed << setprecision(5) << results[i] << '\n';
    }
    return 0;
}