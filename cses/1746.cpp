#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int mod = 1e9+7;
const int  maxm = 105;
const int maxn = 1e5+5;

int a[maxn];
ll dp[maxn][maxm];

void solve(){
    int n,m;
    cin>>n>>m;
    for (int  i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    if(a[0] == 0){
        fill(dp[0], dp[0] + maxm, 1);
    }else{
        dp[0][a[0]] = 1;
    }
    for (int  i = 1; i < n; i++)
    {
        if(a[i] == 0){
            for (int  j = 1; j <= m; j++)
            {
                dp[i][j] += dp[i-1][j];
                if(j -1 > 0)    dp[i][j] += dp[i-1][j-1];
                if(j+1 <= m) dp[i][j] += dp[i-1][j+1];
                dp[i][j] %= mod;
            }
        }else{
            dp[i][a[i]] += dp[i-1][a[i]];
            if(a[i]-1 > 0) dp[i][a[i]] += dp[i-1][a[i]-1];
            if(a[i]+1 <= m) dp[i][a[i]] += dp[i-1][a[i]+1];
            dp[i][a[i]] %= mod;
        }
    }
    ll ans = 0;
    for (int  i = 1; i <= m; i++)
    {
        ans += dp[n-1][i];
        ans %= mod;
    }
    cout<<ans;
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