#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int mod = 1e9+7;
const int maxn = 1005;
char a[maxn][maxn];
int dp[maxn][maxn];

void solve(){
    int n;
    cin>>n;
    for (int  i = 1; i <= n; i++)
    {
        for (int  j = 1; j <= n; j++)
        {
            cin>>a[i][j];
        }
    }
    if(a[1][1]!='*'){
        dp[1][1] = 1;
    }
    for (int  i = 1; i <=n; i++)
    {
        for (int  j = 1; j <= n; j++)
        {
            if(j-1>=0 && a[i][j]!='*' && a[i][j-1]!='*'){
                dp[i][j]  = (dp[i][j] + dp[i][j-1])%mod;
            }
            if(i-1>=0 && a[i][j]!='*' && a[i-1][j]!='*'){
                dp[i][j] = (dp[i][j] + dp[i-1][j])%mod;
            }
        }
    }
    cout<<dp[n][n]%mod;
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