#include<bits/stdc++.h>
#define ll long long
const int maxn = 1e6+5;
using namespace std;

ll k[maxn] = {1};

void init(){
    fill(k, k + maxn, 1);
    for (int  i = 2; i < maxn; i++)
    {
        if(k[i]==1){
            for (int  j = i; j <maxn; j+=i)
            {
                k[j] *=i;
            }
        }
    }
}

void solve(){
    init(); // Hàm cần đo thời gian
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        map<ll,int> c;
        for (int i = a; i <=b; i++)
        {
            c[k[i]]++;
        }
        ll ans = 0;
        for (pair<ll,int> a : c)
        {
            ans += (a.second*(a.second-1)/2);
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
    solve();
    return 0;
}