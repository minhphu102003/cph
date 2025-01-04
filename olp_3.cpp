#include<bits/stdc++.h>
#define ll long long

using namespace std;

// Xác định số lượng các trường hợp chia dư để tính cặp số
void solve(){
    ll n;
    cin>>n;
    ll a[3]= {0, 0, 0};
    ll val;
    for (ll  i = 0; i < n; i++)
    {
        cin>>val;
        int mod = val%3;
        a[mod]++;
    } 
    ll ans = (ll)a[0]*(a[0] -1)/2 + (ll)a[1]*a[2];
    cout<<ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen(".inp","r",stdin);
    // freopen(".out","w",stdout);
    solve();
    return 0;
}
