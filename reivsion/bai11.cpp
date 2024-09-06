#include<bits/stdc++.h>
#define ll long long
#define MOD 1e9+7
using namespace std;

int mu(ll a, ll b, int mod){
    a %= mod;
    int res = 1;
    while (b>0)
    {
        if(b%2==1){
            res= (res*a)% mod;
        }
        b /=2;
        a = (a*a)% mod;
    }
    return res;
}

//Exponentiation by Squaring

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("B008.inp","r",stdin);
    freopen("B008.out","w",stdout);
    ll a,b;
    cin>>a>>b;
    cout<<mu(a,b,MOD);
    return 0;
}