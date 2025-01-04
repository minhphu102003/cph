#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n,x;
    cin>>n>>x;
    ll a[n];
    for (int i = 0; i < n ; i++)
    {
        cin>>a[i];
    }
    if(x ==0 ){
        cout<<0;
        return;
    }
    ll dp[x+1];
    dp[0] = 0;
    for (int  i = 1; i <= x; i++)
    {
        dp[i] = INT_MAX;
        for (int  j = 0; j < n; j++)
        {
            if(i- a[j] >= 0 && dp[i] > dp[i - a[j]]+1)
            dp[i] = dp[i- a[j]] +1;
        }
    }
     cout << ((dp[x] == INT_MAX) ? -1 : dp[x]) << endl;
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