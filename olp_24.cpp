#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n,w1,w2;
    cin>>n>>w1>>w2;
    ll a[n];
    for (int  i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    vector<ll> dpL(n, INT64_MIN);
    vector<ll> dpW(n, INT64_MIN);
    vector<ll> dpR(n, INT64_MIN);
    dpW[0] = a[0] * w1;
    dpL[1] = dpW[0] + a[1]*w2;
    for (int i = 2; i < n-3; i++)
    {
        dpW[i-1] = a[i-1] * w1;
        dpW[i-1] = max(dpW[i-1],dpW[i-2]);
        dpL[i] = max(dpL[i-1],a[i]*w2 + dpW[i-1]);
    }
    dpW[n-1] = a[n-1]* w1;
    dpR[n-2] = a[n-2] *w2 + dpW[n-1];
    ll ans = dpL[n-4] + a[n-3] + dpR[n-2];
    for (int i = n-2; i > 3; i--)
    {
        dpW[i] = a[i]*w1;
        dpW[i] = max(dpW[i],dpW[i+1]);
        dpR[i-1] = max(dpR[i],a[i-1]*w2 + dpW[i]);
        ans = max(ans,a[i-2] + dpL[i-3] + dpR[i-1]);
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