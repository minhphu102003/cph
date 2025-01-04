#include<bits/stdc++.h>
#define ll long long
const int maxn = 205;

using namespace std;

ll a[maxn];

void solve(){
    int n;
    cin>>n;
    for (int  i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    sort(a, a+n);
    int dp[n];
    fill(dp, dp + n, 1);
    int ans = 1;
    for (int  i = 1; i < n; i++)
    {
        for (int  j = i-1; j >=0; j--)
        {
            if(a[i]%a[j]==0){
                dp[i] = max(dp[j]+1, dp[i]);
            }
        }
        ans = max(dp[i],ans);
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