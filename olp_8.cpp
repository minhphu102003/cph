#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn  =105;
int a[maxn];

void solve(){
    int n,x;
    cin >> n >> x;
    for (int  i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int dp[x+1];
    dp[0] = 0;
    for (int  i = 1; i <= x; i++)
    {
        dp[i] = 1e9;
        for (int  j = 0; j < n; j++)
        {
            if(i - a[j] >= 0 && dp[i] > dp[i - a[j]] +1 )
            dp[i] = dp[i - a[j]] +1;
        }
    }
    cout<<(dp[x]==1e9 ? -1 : dp[x]) << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B001.inp","r",stdin);
    freopen("B001.out","w",stdout);
    solve();
    return 0;
}