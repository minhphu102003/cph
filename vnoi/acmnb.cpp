#include<bits/stdc++.h>
#define ll long long

using namespace std;

bool cmp(pair<int,int> &a, pair<int,int> &b){
    return (a.first- a.second < b.first - b.second);
}

void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> list(2*n);
    for (int  i = 0; i < 2*n; i++)
    {
        int a,b;
        cin>>a>>b;
        list[i] = {a,b};
    }
    sort(list.begin(), list.end(), cmp);
    int ans = 0;
    for (int  i = 0; i < n; i++)
    {
        ans +=list[i].first;
    }
    for (int i = n; i < 2*n; i++)
    {
        ans +=list[i].second;
    }
    cout<<ans<<endl;
    
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