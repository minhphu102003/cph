#include<bits/stdc++.h>
#define ll long long
const int maxn = 100001;
using namespace std;

void solve(){
    vector<ll> col[maxn];
    vector<ll> pref[maxn];    
    ll n;
    cin>>n;
    for (int  i = 1; i < maxn; i++)
    {
        col[i].push_back(0);
    }
    for (int  i = 1; i <= n; i++)
    {
        ll a,b;
        cin>>a>>b;
        col[b].push_back(a);
    }
    for (int  i = 1; i < maxn; i++)
    {
        pref[i].resize(col[i].size(), 0 );
        for (int  j = 1; j < col[i].size(); j++)
        {
            pref[i][j] = pref[i][j-1] + col[i][j];
        }
    }
    ll add = 0 ,q;
    ll diff[maxn] = {0};
    cin>>q;
    for (int  i = 1; i <= q; i++)
    {
        ll t,color,x;
        cin>>t>>color>>x;
        if(t==1){
            add +=x;
            diff[color] +=x;
        }
        else{
            ll low =1 ,high = col[color].size() - 1,ans = 0;
            while (low <= high)
            {
                ll mid = (low+high)/2;
                if(pref[color][mid] + mid*(add - diff[color])<= x){
                    ans = mid;
                    low = mid + 1;
                }
                else{
                    high = mid-1;
                }
            }
            cout<<ans<<endl;
        }
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