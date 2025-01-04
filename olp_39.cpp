#include<bits/stdc++.h>
#define ll long long
const int MOD = 1e9+7;

using namespace std;

ll mul(ll a, ll b){
    ll ans = 0;
    while (b>0)
    {
        if(b%2==1){
            ans = (ans+ a)% MOD;
        }
        b /=2;
        a = (a+a)%MOD;
    }
    return ans;
}

ll mul1(ll a, ll b) {
    return (a % MOD) * (b % MOD) % MOD;
}

void solve(){
    int n,m;
    cin>>n>>m;
    ll a[m+1];
    ll pre[m+1];
    memset(a,0,sizeof(a));
    memset(pre,0,sizeof(pre));
    for (int i = 0; i < n; i++)
    {
        int x,y;
        cin>>x>>y;
        a[x] += y;
    }
    pre[1] = a[1];
    for (int i = 2; i <=m; i++)
    {
        pre[i] = pre[i-1]+ a[i];
    }
    ll ans = 0;
    for (int  i = 1; i <= m; i++)
    {
        ans = (ans+ mul(a[i], pre[m] - pre[i]))%MOD;
    }
    cout<<ans<<endl;
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