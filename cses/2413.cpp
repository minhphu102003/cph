#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int mod = 1e9+7;
const int maxn=1e6+5;
ll dp[maxn][2];

void init(){
    dp[1][1] = 1;
    dp[1][2] = 1;
    for (int i = 2; i < maxn; i++)
    {
        dp[i][1] = (dp[i-1][1]*4%mod + dp[i-1][2])%mod;
        dp[i][2] = (dp[i-1][1] + dp[i-1][2]*2%mod)%mod;
    }
}

void solve(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        cout<<(dp[n][1] + dp[n][2])%mod<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("B001.inp","r",stdin);
    // freopen("B001.out","w",stdout);
    init();
    solve();
    return 0;
}