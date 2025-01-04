#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll mulIndia(ll a, ll b, ll mod){
    ll ans = 0;
    a%=mod;
    while (b>0)
    {
        if(b%2==1){
            ans = (ans +a)% mod;
        }
        a = (a * 2) % mod;
        b /=2;
    }
    return ans;
}

void solve(){
    int n;
    ll m;
    cin>>n>>m;
    ll a[n];
    pair<ll,ll> current ={1,1};
    pair<ll,ll> left ={0,1};
    pair<ll,ll> right ={1,0};
    for (int  i = 0; i < n; i++)
    {
       cin>>a[i]; 
       if(i%2==0){
        current.first = (current.first + mulIndia(right.first, a[i], m))%m;
        current.second = (current.second + mulIndia(right.second, a[i], m))%m;
        left.first = (current.first - right.first + m) % m;
        left.second = (current.second - right.second + m) % m;

       } else{
        current.first = (current.first +  mulIndia(left.first, a[i], m))%m;
        current.second = (current.second + mulIndia(left.second, a[i], m))%m;
        right.first = (current.first - left.first +m )%m;
        right.second = (current.second - left.second +m)%m;
       }
    }
    cout<<current.first<<" "<<current.second<<endl;
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