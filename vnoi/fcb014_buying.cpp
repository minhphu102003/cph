#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll a,b,x,y;
    cin>>a>>b>>x>>y;
    cout<<a*x+b*y;
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