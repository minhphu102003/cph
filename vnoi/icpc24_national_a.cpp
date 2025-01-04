#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int x;
        map<int, int> cnt;
        for (int  i = 0; i < n; i++)
        {
            cin>>x;
            cnt[x]++;
        }
        ll ans = 0;
        int smaller = 0;
        for ( pair<int, int> a : cnt)
        {
            if(a.second>= 3){
                ans +=1LL* a.second *(a.second -1)* (a.second -2)/6;
            }   
            if(a.second >=2){
                ans +=1LL* smaller*a.second* (a.second-1)/2;
            }
            smaller += a.second;
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