#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, k;
    ll s;
    cin >>n>>k>>s;
    vector<ll> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin>>a[i];
        a[i] += a[i-1];
    }
    int count=0;
    for (int len=k; len <= n; len += k) {
        for (int i = 0; i+len <= n; i++) {
            ll sum = a[i+len] - a[i];
            if (sum >=s) count++;
        }
    }
    cout<<count<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen(".inp","r",stdin);
    // freopen(".out","w",stdout);
    solve();
    return 0;
}