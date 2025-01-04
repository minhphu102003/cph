#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    int n;
    cin>>n;
    int t[n];
    int r[n-1];
    int prefix = 0;
    for (int  i = 0; i < n; i++)
    {
        cin>>t[i];
        prefix += t[i];
    }
    for (int  i = 0; i < n-1; i++)
    {
        cin>>r[i];
    }
    int chance[n-1];
    for (int i = 0; i < n-1; i++)
    {
        chance[i] = t[i] + t[i+1] - r[i];
        if(chance[i]<0){
            chance[i] = 0;
        }
    }
    int dp[n];
    dp[0] = 0;
    dp[1] = chance[0];
    for (int  i = 2; i < n; i++)
    {
        dp[i] = (dp[i-2] + chance[i-1] > dp[i-1]) ? (dp[i-2] + chance[i-1]) : dp[i-1];
    }
    prefix -= dp[n-1];
    cout<<prefix<<endl;
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