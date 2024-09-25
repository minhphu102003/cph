#include<bits/stdc++.h>
#define ll long long

using namespace std;


void solve(){
    int t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        int ans = 0;
        for (int i = 2; i <= n; i+=2)
        {
            if(n%(i*i)==0  && round(sqrt(n/(i*i))) == sqrt(n/(i*i)) && n/(i*i)%2 == 0){
                ans +=1;
            }
        }
        cout<<ans<<endl;
    }
    
}

void optimizing(){
    int t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        if(n%16 != 0){
            cout<<0<<endl;
            continue;
        }
        n/=16;
        ll x = sqrtl(n);
        if(x*x != n){
            cout<<0<<endl;
            continue;
        }
        int ans = 0;
        for (int  i = 1; i*i <= x; i++)
        {
            if(x%i==0){
                ans +=1;
                if( i != x/i)   ans ++;
            }
        }
        cout<<ans<<endl;
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("B001.inp","r",stdin);
    // freopen("B001.out","w",stdout);
    // solve();
    optimizing();
    return 0;
}