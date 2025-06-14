#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int INF = 1e9+ 5;
vector<vector<int>> tr;
vector<int> a;

pair<int, int> dfs(int node) {
  int cho = a[node];
  int notCho= 0;      
  bool flag = false;
  int loss= INF;
  int len = tr[node].size();
  for (int i = 0 ; i< len; i++) {
    auto [nc, c] = dfs(tr[node][i]);
      cho += nc;
      notCho += max(nc, c);
      if (c > nc) flag = true;
      else loss = min(loss, c - nc);
    }
    if (!flag && !tr[node].empty()) {
      notCho+= loss;
  }
  return {notCho, cho};
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    int t;
    cin>>t;
    while (t--)
    {
      int n;
      cin>>n;
      a= vector<int>(n + 1);
      tr= vector<vector<int>>(n + 1);
      for (int i = 1; i <= n; ++i)
        cin>>a[i];
      vector<int> pa(n + 1);
      int root = 0;
      for (int i = 1; i <= n; ++i) {
        cin >> pa[i];
        if (pa[i] == 0) root = i;
        else tr[pa[i]].push_back(i);
      }
      auto[dp, dp1] = dfs(root);
      cout<< max(dp, dp1)<<'\n';
    }
    return 0;
}