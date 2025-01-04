#include<bits/stdc++.h>
#define ll long long

using namespace std;


void solve(){
    ll u,v;
    cin>>u>>v;
    ll result = (u*u + v*v)/4;
    ll du =(u*u + v*v)%4;
    if( du == 0 ){
        cout<<result<<".00";
    }
    else if( du == 1 ){
        cout<<result<<".25";
    }
    else if( du == 2 ){
        cout<<result<<".50";
    }
    else{
        cout<<result<<".75";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("b001.inp","r",stdin);
    // freopen("b001.out","w",stdout);
    solve();
    return 0;
}