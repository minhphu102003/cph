#include<bits/stdc++.h>
#define ll long long
const int maxn = 1e5+5;
using namespace std;
int n,m;
int ans = 0;

vector<int> a[maxn];
vector<int> dp(maxn,-1);
vector<bool> visited(maxn, false); 

int dfs(int x){
    if(dp[x] != -1) return dp[x];
    dp[x] = 0;
    for (int v : a[x])
    {
        dp[x] = max(dp[x], 1+dfs(v));
    }
    return dp[x];
}


void solve(){
    cin>>n>>m;
    while (m--)
    {
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
    }
    int ans = 0;
    for (int  i = 1; i <= n; i++)
    {
        ans = max(ans, dfs(i));
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("B001.inp","r",stdin);
    // freopen("B001.out","w",stdout);
    solve();
    return 0;
}