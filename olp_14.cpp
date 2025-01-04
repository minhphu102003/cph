#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 200005;

ll n; 
ll a[maxn];
// Copy
void solve(){
    cin>>n;
    a[0] = 0;
    for (int  i = 1; i <= n ; i++)
    {
        cin>>a[i];
        a[i] +=a[i-1];
    }

    vector<ll> dp(n+5, INT32_MIN);
    vector<ll> dpR(n+5, INT32_MIN);
    vector<ll> lM(n +5, INT32_MIN);

    for (int i = 3; i <=n; i++)
    {
        dp[i] = max(dp[i-3] + a[i] - a[i-3], a[i] - a[i-3]);
        lM[i] = max(lM[i-1], dp[i]);
    }
    ll ans = INT64_MIN;

    for (int  i = n-2; i > 0; i--)
    {
        dpR[i] = max(dpR[i+3] + a[i+2] - a[i-1], a[i+2]- a[i-1]);
        ans = max(ans, dpR[i] + lM[i-1]);
    }
    cout<<ans<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}