#include<bits/stdc++.h>
#define ll long long
const int MOD = 1e9+7;
using namespace std;

void solve(ll a , ll b){
    if(b==0){
        cout<<1<<endl;
        return;
    }
    a %= MOD;
    ll ans = 1;
    while (b>0)
    {
        if(b&1){
            ans = (ans*a)% MOD;
        }
        b/=2;
        a  = (a*a) % MOD;
    }
    cout<<ans<<endl;
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("B008.inp","r",stdin);
    // freopen("B008.out","w",stdout);
    int n;
    cin>>n;
    while (n--)
    {
        ll a, b;
        cin>>a>>b;
        solve(a,b);
    }
    
    return 0;
}