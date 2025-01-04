#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int mod = 1e9+7;

void solve(){
    int n,x;
    cin>>n>>x;
    int a[n];
    for (int  i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int dp[x+1];
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for (int  i = 0; i < n; i++)
    {
        for (int  j = 1; j <= x; j++)
        {
            if(j - a[i]>=0){
                dp[j] = (dp[j] + dp[j - a[i]])%mod;
            }
        }
    }
    cout<<dp[x]<<endl;
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