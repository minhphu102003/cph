#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int maxn = 1e9+7;

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
    dp[0]= 1;
    for (int  i = 1; i <= x; i++)
    {
        for (int  j = 0; j < n; j++)
        {
            if(i - a[j] >= 0){
                dp[i] = (dp[i] + dp[i-a[j]])% maxn;
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